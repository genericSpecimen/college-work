X <- iris[,-5]
y <- iris[,5]

hc <- hclust(dist(X), method="complete")
print(hc)
plot(hc, main="Agglomerative Hierarchical Clustering")

C3 <- cutree(hc, 3)
print(C3)
print(table(C3, iris$Species))

