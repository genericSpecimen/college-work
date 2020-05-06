library(factoextra)

data('multishapes')

X <- multishapes[, -3]

# kmeans with k = 5 clusters
# initally, a set of 5 distinct cluster centres are chosen
# nstart = 25 such sets are chosen, so that we reduce the
# chances of randomly selecting bad initial centers

km <- kmeans(X, centers = 5, nstart = 25)
# visualize the resulting clusters (only points)
fviz_cluster(km, data = X, geom = 'point')
