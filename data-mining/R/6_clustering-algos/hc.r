library(factoextra)

data('multishapes')

X <- multishapes[, -3]

# use the "hclust" function and "complete" method,
# then cut the tree into 5 clusters (i.e. 5th level)
hc5 <- hcut(X, k = 5, hc_func = 'hclust', hc_method = 'complete')

# dendrogram, takes a lot of time to render
# fviz_dend(hc.cut, rect = TRUE)

# visualize the resulting clusters (only points)
fviz_cluster(hc5)

