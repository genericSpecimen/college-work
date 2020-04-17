library(arules)

# read a transaction data file and create a transactions object
groceries = read.transactions("groceries.csv")

# use minsup = 1%, minconf = 75%
rules <- apriori(groceries, parameter = list(supp = 0.01, conf = 0.75, target = "rules"))
summary(rules)

# if the lift is > 1, that lets us know the degree to which the
# antecent and consequent are dependent on one another,
# and makes those rules potentially useful for predicting the
# consequent in future data sets.
# (lift == 1) implies antecedent and consequent are independent of each other
inspect(head(rules, by = "lift"))

# use minsup = 3%, minconf = 60%
rules <- apriori(groceries, parameter = list(supp = 0.03, conf = 0.60, target = "rules"))
summary(rules)
inspect(head(rules, by = "lift"))

