#!/usr/bin/env python
# coding: utf-8

# # Image Compression Using PCA
# 
# Name: **Irfan Sheikh**
# 
# Roll no.: **16**

# In[1]:


from PIL import Image
import matplotlib.image as mpimg
import matplotlib.pyplot as plt
import numpy as np
from sklearn.decomposition import PCA
import time


# ## Conversion to grayscale

# In[2]:


h = 0 #index for image
img = Image.open(f'human{h}_800.jpg').convert('L')
img.save(f'human{h}_grayscale.jpg')


# In[3]:


img = mpimg.imread(f'human{h}_grayscale.jpg')
X = img
print(X.shape)
X


# ## Using sklearn's PCA module

# In[4]:


pca = PCA()
pca.fit(X)
np.set_printoptions(suppress=True)
# Percentage of variance explained by each of the principal components.
#print(pca.explained_variance_ratio_ * 100)
# the cumulative percentage variance explained by dimensions
#print(pca.explained_variance_ratio_.cumsum() * 100)
print(pca.n_components_)


# ### Scree plot

# In[5]:


# explained_variance is equal to n_components largest eigenvalues of the covariance matrix of X.
plt.figure(figsize=(20,8))
num_pcs = np.arange(pca.n_components_) + 1
plt.plot(num_pcs, pca.explained_variance_, 'b-', linewidth=2)
plt.grid()
plt.xticks(np.arange(0, max(num_pcs)+1, 10))
plt.title(f'Scree Plot (Image {h+1})', fontsize=20)
plt.xlabel('Principal Components (Eigenvectors)', fontsize=20)
plt.ylabel('Eigenvalues', fontsize=20)
plt.xticks(rotation=60)
plt.savefig(f'scree_{h}.jpg', bbox_inches='tight', dpi=300)


# ### Proportion of variance explained

# In[6]:


plt.figure(figsize=(20,8))
num_pcs = np.arange(pca.n_components_) + 1
plt.plot(num_pcs, pca.explained_variance_ratio_.cumsum(), 'b-', linewidth=2)
plt.grid()
plt.xticks(np.arange(0, max(num_pcs)+1, 10))
plt.title(f'Proportion of Variance Explained (Image {h+1})', fontsize=20)
plt.xlabel('Number of Principal Components (Eigenvectors)', fontsize=20)
plt.ylabel('Proportion of Variance Explained', fontsize=20)
plt.xticks(rotation=60)

plt.axhline(y = 0.99, color='k', linestyle='--', label = '99% Explained Variance')
plt.axhline(y = 0.95, color='c', linestyle='--', label = '95% Explained Variance')
plt.axhline(y = 0.90, color='r', linestyle='--', label = '90% Explained Variance')
plt.legend(loc='best')
plt.savefig(f'propvar_{h}.jpg', bbox_inches='tight', dpi=300)


# ### Reconstruction of the Image

# In[7]:


num_pc = 80


# In[8]:


pca = PCA(n_components=num_pc)
pca.fit(X)

Z = pca.transform(X)
reconstructed_img = pca.inverse_transform(Z)


# ## Manual Computation using the linalg module

# In[9]:


num_pc = 80

# center the data X and find eigenvectors of the covariance matrix
X_centered = X - np.mean(X, axis = 0)
X_cov = np.cov(X_centered, rowvar=False)
eig_vals, eig_vecs = np.linalg.eigh(X_cov)

# sort eig_vals and eig_vecs in decreasing order of eigenvalues
idx = np.argsort(eig_vals)[::-1]
eig_vals = eig_vals[idx]
eig_vecs = eig_vecs[:,idx]

print(eig_vecs[:,:num_pc].shape)
#print(eig_vecs[:5,:num_pc])
#print(pca.components_.T[:5,:])

# eig_vals is the same as pca.explained_variance_ in this case
#np.equal(np.around(eig_vals,8), np.around(pca.explained_variance_,8))

# While PCA() lists the entries of an eigenvectors rowwise,
# np.linalg.eig() lists the entries of the eigenvectors columnwise.
# pca.components_ is equal to eig_vecs.T - relate to (W.T)
#eig_vecs.T

# proportion of variance explained by the principal components - same as
# pca.explained_variance_ratio_
prop_var = np.divide(eig_vals, np.sum(eig_vals))


# In[10]:


# transform to z-space
Z = np.dot(X_centered, eig_vecs[:,:num_pc])
# inverse transform
X_hat = np.dot(Z, eig_vecs[:,:num_pc].T) + np.mean(X, axis=0)

#print(X_hat)
fig = plt.imshow(X_hat, cmap='gray')


# # Comparison
# 

# In[11]:


h = 0
img = mpimg.imread(f'human{h}_grayscale.jpg')
X = img


# In[12]:


#5% 10% 20% 30% 40%
num_pc = 800
pca = PCA(n_components=num_pc)
pca.fit(X)

Z = pca.transform(X)
reconstructed_img = pca.inverse_transform(Z)
print(reconstructed_img.shape)

fig = plt.imshow(reconstructed_img, cmap='gray')
plt.imsave(f'name.jpg', reconstructed_img, cmap='gray')


# In[13]:


num_pc = 400
plt.figure(figsize=(20,20))
#100%, 1.25%, 2.5%, 3.75%, 5% 10% 20% 30% 40%
#props = [1, 0.0125, 0.025, 0.0375, 0.05, 0.10, 0.20, 0.30, 0.40]

props = [
    [1, 0.0125, 0.025],
    [0.0375, 0.05, 0.10],
    [0.20, 0.30, 0.40]
]

p_ind = 1

for i in range(len(props[p_ind])):
    plt.subplot(3,3,i+1)
        
    n = int(props[p_ind][i]*num_pc)
    pca = PCA(n_components=n)
    pca.fit(X)
    Z = pca.transform(X)
    reconstructed_img = pca.inverse_transform(Z)
    
    fig = plt.imshow(reconstructed_img, cmap='gray')
    plt.title(f'{n} components ({props[p_ind][i]*100}%)', y=-0.1, fontsize=20)
    plt.axis('off')
    fig.axes.get_xaxis().set_visible(False)
    fig.axes.get_yaxis().set_visible(False)
    plt.savefig(f'reconstructed_{h}{p_ind}.jpg', bbox_inches='tight', dpi=300)
    #plt.imsave(f'recon{h}/reconstructed_{n}.jpg', reconstructed_img, cmap='gray')

