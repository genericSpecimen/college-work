library(dbscan)

X <- iris[, -5]
y <- iris[, 5]

k = 4
#kNNdistplot(X, k)
#abline(h = 0.45, col="green")

eps = 0.45

db = dbscan(X, eps, minPts=k)
print(db)

hullplot(X, db, main="DBSCAN")

