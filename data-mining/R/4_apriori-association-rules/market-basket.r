library(arules)

# read a transaction data file and create a transactions object
#Groceries = read.transactions("Groceries.csv")

# or use an inbuilt dataset 
data('Groceries')

# use minsup = 1%, minconf = 50%
rules <- apriori(Groceries, parameter = list(supp = 0.01, conf = 0.3, target = "rules"))
summary(rules)

# if the lift is > 1, that lets us know the degree to which the
# antecedent and consequent are dependent on one another,
# and makes those rules potentially useful for predicting the
# consequent in future data sets.
# (lift == 1) implies antecedent and consequent are independent of each other
inspect(head(rules, by = "lift"))
inspect(head(rules, by = "confidence"))

# use minsup = 3%, minconf = 60%
rules <- apriori(Groceries, parameter = list(supp = 0.015, conf = 0.50, target = "rules"))
summary(rules)
inspect(head(rules, by = "lift"))
inspect(head(rules, by = "confidence"))

