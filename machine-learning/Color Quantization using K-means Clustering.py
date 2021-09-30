#!/usr/bin/env python
# coding: utf-8

# # Color Quantization using K-means Clustering

# In[1]:


import matplotlib.image as mpimg
import matplotlib.pyplot as plt
import numpy as np
from sklearn.utils import shuffle
from time import time

from sklearn.cluster import KMeans


# In[2]:


def getFileSize(filename):
    lsf = get_ipython().getoutput('ls -l {filename}')
    file_size = int(lsf[0].split()[4])
    return file_size


# In[3]:


def printImageInfo(filename):
    print(f"=> Image: {filename}")
    
    dimensions = get_ipython().getoutput('identify -format "%w x %h  (%[channels])" {filename}')
    print(f"=> Dimensions      : {dimensions[0]}")
    
    num_pixels = get_ipython().getoutput("identify -verbose {filename} | grep 'Pixels:'")
    print(f"=> Number of pixels: {num_pixels[0].split()[1]}")

    img_size = getFileSize(filename)
    print(f"=> Image size      : {img_size} B")

    num_colors = get_ipython().getoutput('identify -format "%k" {filename}')
    print(f"=> Number of colors: {num_colors[0]}")


# ## Original Image

# In[4]:


directory = 'human'
name = 'human'
extension = 'png'

filename = f'imgs/{directory}/{name}.{extension}'
print("Original image information")
printImageInfo(filename)

original_size = getFileSize(filename)


# ## Convert the image to a 2-dimensional array
# 
# Upon doing so, we will have (width * height) pixels as instances, and the 3 RGB dimensions as features.

# In[5]:


img = mpimg.imread(filename)

# Convert to floats instead of the default 8 bits integer coding. Dividing by
# 255 is important so that plt.imshow behaves works well on float data (need to
# be in the range [0-1])
#img = np.array(img, dtype=np.float64) / 255

print(f"Original image array dimensions : {img.shape}")
w, h, d = img.shape

image_array = np.reshape(img, (w * h, d))
print(f"Converted image array dimensions: {image_array.shape}")
#print(image_array[:5])


# ## Using K-means to create codebook and compressed image

# ### Compute cluster centers (create codebook)

# In[6]:


# using n_bits bit codebook
n_bits = 8
n_colors = 2 ** n_bits

print("Fitting model on a small sub-sample of the data")
t0 = time()

image_array_sample = shuffle(image_array, random_state=0)[:10000]
kmeans = KMeans(n_clusters=n_colors, random_state=0).fit(image_array_sample)
#kmeans = KMeans(n_clusters=n_colors, random_state=0).fit(image_array)

print("done in %0.3fs." % (time() - t0))

# the codebook is simply the cluster centers obtained
codebook = kmeans.cluster_centers_


# In[7]:


codebook = (codebook - codebook.min()) / (codebook.max() - codebook.min())


# ### Visualizing the codebook
# 
# The codebook contains 2^n_bits representative colors. 

# In[8]:


plt.figure(figsize=(20,20))

plt.subplot(1,2,1)
orig_n_colors = get_ipython().getoutput('identify -format "%k" {filename}')
orig_n_colors = int(orig_n_colors[0])
plt.title(f'Original image ({orig_n_colors} colors)', fontsize=18)
plt.axis('off')
plt.imshow(img)

print(codebook.shape)
plt.subplot(1,2,2)
if (n_bits == 1):
    plt.imshow(codebook.reshape((1,2,3)))
else:
    plt.imshow(codebook.reshape((int(np.sqrt(n_colors)), int(np.sqrt(n_colors)), 3)))

plt.axis('off')
plt.title(f"Codebook : the {n_colors} best colors", fontsize=18)
plt.savefig(f'imgs/{directory}/{n_bits}-bit/codebook.jpg', bbox_inches='tight', dpi=300)


# ### Predict labels (create the compressed image)
# 
# The compressed image is nothing but a sequence of n_bit indices into the codebook, one for each of the (w\*h)  individual pixels in the original image.

# In[9]:


# Get labels for all points, i.e., create the compressed image
print("Predicting color indices on the full image")
t0 = time()
labels = kmeans.predict(image_array)
print("done in %0.3fs." % (time() - t0))

# the compressed image is simply the labels predicted
compressed_img = labels


# ### Saving the codebook and compressed image onto the disk

# In[10]:


codebook_filename = f'imgs/{directory}/{n_bits}-bit/codebook.npz'
with open(codebook_filename, 'wb') as f:
    np.savez_compressed(f, codebook)

compressed_img_filename = f'imgs/{directory}/{n_bits}-bit/compressed.npz'
with open(compressed_img_filename, 'wb') as f:
    np.savez_compressed(f, compressed_img)

compressed_info_filename = f'imgs/{directory}/{n_bits}-bit/codebook_compressed_info.txt'
with open(compressed_info_filename, 'w') as f:
    print(f'Codebook dimensions: {codebook.shape}', file=f)
    codebook_size = getFileSize(codebook_filename)
    print(f"Codebook size (cluster centers) : {codebook_size} B", file=f)

    print(f'\nCompressed image dimensions : {compressed_img.shape}', file=f)
    compressed_img_size = getFileSize(compressed_img_filename) 
    print(f"Compressed image size (labels)  : {compressed_img_size} B", file=f)

    total_size = codebook_size + compressed_img_size
    print(f"\nTotal size on disk: {total_size} B (codebook + compressed image)", file=f)
    print(f"Percentage of original size: {(compressed_img_size / original_size) * 100} %", file=f)
    print(f"Percentage of space saved  : {((original_size - compressed_img_size) / original_size) * 100} %", file=f)

get_ipython().system(' cat {compressed_info_filename}')


# ## Reconstruction of image

# ### Load the codebook and compressed image from disk

# In[11]:


codebook = np.load(codebook_filename)['arr_0']
compressed_img = np.load(compressed_img_filename)['arr_0']

print(f'Codebook dimensions: {codebook.shape}')
print(f'Compressed img dims: {compressed_img.shape}')


# ### Recreate the image from the code book & compressed image

# In[12]:


d = codebook.shape[1]
reconstructed_image = np.zeros((w, h, d))
idx = 0

for i in range(w):
    for j in range(h):
        reconstructed_image[i][j] = codebook[compressed_img[idx]]
        idx += 1
        
# save reconstructed image to disk        
plt.imsave(f'imgs/{directory}/{n_bits}-bit/reconstructed.{extension}', reconstructed_image)


# ## Comparison of original and reconstructed images

# In[13]:


plt.figure(figsize=(20,20))

plt.subplot(1,2,1)
orig_n_colors = get_ipython().getoutput('identify -format "%k" {filename}')
orig_n_colors = int(orig_n_colors[0])
plt.title(f'Original image ({orig_n_colors} colors)', fontsize=18)
plt.axis('off')
plt.imshow(img)

plt.subplot(1,2,2)
plt.title(f'Reconstructed image ({n_colors} colors, K-Means)', fontsize=18)
plt.axis('off')
plt.imshow(reconstructed_image)

plt.savefig(f'imgs/{directory}/{n_bits}-bit/comparison.jpg', bbox_inches='tight', dpi=300)


# In[14]:


# original image information
print("Original Image information:")
printImageInfo(f'imgs/{directory}/{name}.{extension}')

# reconstructed image information - it should have only 2**n_bits colors now
print("\nReconstructed Image information:")
printImageInfo(f'imgs/{directory}/{n_bits}-bit/reconstructed.{extension}')


# In[ ]:




