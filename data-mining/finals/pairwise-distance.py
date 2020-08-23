from sklearn.metrics.pairwise import euclidean_distances

# 1D points
X = [[1], [2], [3], [5]]
print(euclidean_distances(X, X), "\n")

# 2D points
X = [[0, 2], [2, 0], [3, 1], [5, 1]]
print(euclidean_distances(X, X), "\n")

# Arun DM Test question
X = [[1, 2], [2, 2], [2, 1], [-1, 4], [-2, -1], [-1, -1]]
centroids = [[1, 2], [-1, 4]]
print(euclidean_distances(X, centroids))

#K-means
X = [[2], [4], [10], [12], [3], [20], [30], [11], [25]]
centroids = [[2], [4], [6]]
euclidean_distances(X, centroids)

# 2D points
X = [[0.40, 0.53], [0.22, 0.38], [0.35, 0.32], [0.26, 0.19], [0.08, 0.41], [0.45, 0.30]]
print(euclidean_distances(X, X), "\n")



X = [[5, 8], [7, 3], [6, 4], [8, 4], [4, 7]]
centroids = [[2, 8], [2, 5], [1, 2]]
print(euclidean_distances(X, centroids), "\n")

