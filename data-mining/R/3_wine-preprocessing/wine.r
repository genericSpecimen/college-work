wine <- read.csv("wine.csv")

# 1st column is the class label
# attributes X
X = wine[, -1]

# class label y
y = wine[, 1]

# apply the mean function along each column (= 2)
# apply(X, 2, mean)

# but use colMeans (faster than apply)
colMeans(X)
# apply the sd (standard deviation) function along each column (= 2)
apply(X, 2, sd)


# we see mean and standard deviation is not 0 and 1 respectively for any column,
# so we standardize them all using the scale() function

standardized_X = scale(X)

colMeans(standardized_X)
apply(standardized_X, 2, sd)

