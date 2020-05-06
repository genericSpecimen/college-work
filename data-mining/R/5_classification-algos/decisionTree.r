library(caret)

# standardization
iris[, -5] <- scale(iris[, -5])


# ------------------------------ Holdout method ---------------------------

# 75 - 25 split

# p = %age of data that goes into training;
# list=FALSE results should be in a matrix instead of list
train_idx <- createDataPartition(y = iris$Species, p = 0.75, list = FALSE) 
iris_train <- iris[train_idx, ]
iris_test <- iris[-train_idx, ]

# attributes X
X = iris_train[, -5]
# class labels y (species)
y = iris_train[, 5]

# use the Random Forest method
model <- train(X, y, method='rf')
# predict the output for test data
pred <- predict(model, iris_test)
cm <- confusionMatrix(pred, iris_test$Species)
cat(sprintf(" => Random Forest method using 75-25 split; accuracy: %f\n", cm$overall['Accuracy']))

# 2/3rd - 1/3rd split

train_idx <- createDataPartition(y = iris$Species, p = 0.67, list = FALSE) 
iris_train <- iris[train_idx, ]
iris_test <- iris[-train_idx, ]

X = iris_train[, -5]
y = iris_train[, 5]

model <- train(X, y, method='rf')
pred <- predict(model, iris_test)
cm <- confusionMatrix(pred, iris_test$Species)

cat(sprintf(" => Random Forest method using 2/3rd - 1/3rd split; accuracy: %f\n", cm$overall['Accuracy']))
# -------------------------------------------------------------------------






#--------------------- Random subsampling - Monte Carlo CV ------------------
X = iris[, -5]
y = iris[, 5]

# repeatedly take random 75% of data as training set
trCtrl = trainControl(method = 'LGOCV', p = 0.75)
model <- train(X, y, method='rf', trControl = trCtrl)
cat(sprintf(" => Random Forest method using random subsampling, p = 0.75; max accuracy: %f\n", max(model$results$Accuracy)))

# repeatedly take random 67% of data as training set
trCtrl = trainControl(method = 'LGOCV', p = 0.67)
model <- train(X, y, method='rf', trControl = trCtrl)
cat(sprintf(" => Random Forest method using random subsampling, p = 0.67; max accuracy: %f\n", max(model$results$Accuracy)))
#----------------------------------------------------------------------------






#------------------------ k-fold Cross Validation ---------------------------
X = iris[, -5]
y = iris[, 5]

# 10-fold cross validation
trCtrl = trainControl(method = 'cv', number = 10)
model <- train(X, y, method='rf', trControl = trCtrl)
cat(sprintf(" => Random Forest method using 10-fold CV; accuracy: %f\n", max(model$results$Accuracy)))
#----------------------------------------------------------------------------


