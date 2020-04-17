library(e1071)
library(caret) # train, confusionMatrix
#library(klaR)
# train-test split
library(rpart)
library(rpart.plot)

set.seed(10)
m = nrow(iris)

# 75-25 split
sample <- sample.int(n = m, size = floor(0.75*m), replace = FALSE)
iris_train <- iris[sample,]
iris_test <- iris[-sample,]

model <- rpart(Species ~ ., data = iris_train, method = "class")
rpart.plot(model)
pred <- predict(model, iris_test, type = "class")
xtab <- table(pred, iris_test$Species)
cm <- confusionMatrix(xtab)
cat(sprintf(" => Decision tree 75-25 split; accuracy: %f\n", cm$overall['Accuracy']))


# 2/3rd - 1/3rd split
sample <- sample.int(n = m, size = floor((2/3)*m), replace = FALSE)
iris_train <- iris[sample,]
iris_test <- iris[-sample,]
model <- rpart(Species ~ ., data = iris_train, method = "class")
rpart.plot(model)
pred <- predict(model, iris_test, type = "class")
xtab <- table(pred, iris_test$Species)
cm <- confusionMatrix(xtab)

cat(sprintf(" => Decision tree 2/3rd - 1/3rd split; accuracy: %f\n", cm$overall['Accuracy']))

# holdout method is the same as above


# random subsampling (repeated holdout method)
# training set size varies from 50% to 80%
accuracies <- c()
i <- 1
for(j in 50:80) {
	sample <- sample.int(n = m, size = floor((2/3)*m), replace = FALSE)
	iris_train <- iris[sample,]
	iris_test <- iris[-sample,]
	model <- rpart(Species ~ ., data = iris_train, method = "class")
	pred <- predict(model, iris_test, type = "class")
	xtab <- table(pred, iris_test$Species)
	cm <- confusionMatrix(xtab)
	accuracies[i] <- cm$overall['Accuracy']
	i = i + 1
}

cat(sprintf(" => Decision tree using random subsampling; mean accuracy: %f\n", mean(accuracies)))


# k-fold cross validation

set.seed(123)
ctrl = trainControl(method = "cv", number = 10)

model <- train(Species ~ ., data = iris, method = "rpart", trControl = ctrl)
cat(sprintf(" => Decision tree using 10-fold CV accuracy: %f\n", max(model$results$Accuracy)))

# standardized data
iris[,-5] <- scale(iris[,-5])
sample <- sample.int(n = m, size = floor(0.75*m), replace = FALSE)
iris_train <- iris[sample,]
iris_test <- iris[-sample,]

model <- rpart(Species ~ ., data = iris_train, method = "class")
rpart.plot(model)
pred <- predict(model, iris_test, type = "class")
xtab <- table(pred, iris_test$Species)
cm <- confusionMatrix(xtab)
cat(sprintf(" => Decision tree 75-25 split; standardized; accuracy: %f\n", cm$overall['Accuracy']))


