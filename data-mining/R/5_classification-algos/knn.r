library(caret) # train, confusionMatrix
library(klaR)
library(class)

# train-test split
set.seed(10)
m = nrow(iris)

X = iris[,-5]
y = iris[,5]

# 75-25 split
sample <- sample.int(n = m, size = floor(0.75*m), replace = FALSE)
X_train <- X[sample, ]
X_test <- X[-sample,]
y_train <- y[sample]
y_test <- y[-sample]
pred <- knn(X_train, X_test, cl=y_train, k=10)

xtab <- table(pred, y_test)
cm <- confusionMatrix(xtab)
cat(sprintf(" => knn 75-25 split; accuracy: %f\n", cm$overall['Accuracy']))

# 2/3rd - 1/3rd split
sample <- sample.int(n = m, size = floor((2/3)*m), replace = FALSE)
X_train <- X[sample, ]
X_test <- X[-sample,]
y_train <- y[sample]
y_test <- y[-sample]
pred <- knn(X_train, X_test, cl=y_train, k=10)

xtab <- table(pred, y_test)
cm <- confusionMatrix(xtab)

cat(sprintf(" => knn 2/3rd - 1/3rd split; accuracy: %f\n", cm$overall['Accuracy']))

# holdout method is the same as above


# random subsampling (repeated holdout method)
# training set size varies from 50% to 80%
accuracies <- c()
i <- 1
for(j in 50:80) {
	sample <- sample(m, j)
	X_train <- X[sample, ]
	X_test <- X[-sample,]
	y_train <- y[sample]
	y_test <- y[-sample]
	pred <- knn(X_train, X_test, cl=y_train, k=10)

	xtab <- table(pred, y_test)
	cm <- confusionMatrix(xtab)

	accuracies[i] <- cm$overall['Accuracy']
	i = i + 1
}

cat(sprintf(" => knn using random subsampling; mean accuracy: %f\n", mean(accuracies)))


# k-fold cross validation

set.seed(123)
ctrl = trainControl(method = "cv", number = 10)

model <- train(Species ~ ., data = iris, method = "knn", trControl = ctrl)
cat(sprintf(" => knn using 10-fold CV accuracy: %f\n", max(model$results$Accuracy)))

# standardized data
X = scale(X)

sample <- sample.int(n = m, size = floor(0.75*m), replace = FALSE)
X_train <- X[sample, ]
X_test <- X[-sample,]
y_train <- y[sample]
y_test <- y[-sample]
pred <- knn(X_train, X_test, cl=y_train, k=10)

xtab <- table(pred, y_test)
cm <- confusionMatrix(xtab)
cat(sprintf(" => knn 75-25 split; standardized; accuracy: %f\n", cm$overall['Accuracy']))

