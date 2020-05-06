library(dbscan)
library(factoextra)

data('multishapes')

X <- multishapes[, -3]

# to determine eps, we plot the sorted distances of
# 4th nearest neighbor of each point and look for the "knee"
# we select eps = value corresponding to the knee
k = 4
kNNdistplot(X, k)

# we see it's near 0.16
abline(h = 0.16, col = 'green')

db <- dbscan(X, eps = 0.16, minPts = k+1)

# visualize the resulting clusters (only points)
fviz_cluster(db, data = X, geom = 'point')

