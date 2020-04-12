library(editrules)

iris <- read.csv("dirty_iris.csv")

# complete.cases returns a logical vector indicating which cases are complete,
# i.e., have no missing values. Simply sum the logical vector to get the number
# of TRUEs

num_complete <- sum(complete.cases(iris))
num_total <- nrow(iris)


sprintf("Total number of observations   : %d", num_total)
sprintf("Number of complete observations: %d", num_complete)

percent <- (num_complete/num_total) * 100
sprintf("Percentage of complete observations: %f%%", percent)

# replace special values with NA
iris[is.na(iris) || is.null(iris)] <- NA
# iris[86, 4] was "Inf"
iris[86, 4] <- NA

# omit the records containing NA
na.omit(iris)
e <- editfile("iris_rules.txt")
ve <- violatedEdits(e, iris)
summary(ve)
plot(ve)

boxplot(iris$Sepal.Length)
boxplot.stats(iris$Sepal.Length)

