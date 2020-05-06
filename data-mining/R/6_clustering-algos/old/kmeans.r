library(dbscan)
X <- iris[, -5]
y <- iris[, 5]

# number of clusters
K = 3
cl <- kmeans(X, K)
print(cl)

#plot(X, col = cl$cluster)
hullplot(X, cl, main="k-means with k=3")

K = 4
cl <- kmeans(X, K)
print(cl)

#plot(X, col = cl$cluster)
hullplot(X, cl, main="k-means with k=4")
