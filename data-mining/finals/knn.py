from sklearn.metrics.pairwise import euclidean_distances
import numpy as np

X = [[0.5], [3.0], [4.5], [4.6], [4.9], [5.2], [5.3], [5.5], [7.0], [9.5]]

d = euclidean_distances(X, [[5.0]])
print(d, "\n")

sorted_d = np.sort(d.reshape(1,10)[0])
print(sorted_d, "\n")

w = 1/(d**2)
print(w, "\n")


