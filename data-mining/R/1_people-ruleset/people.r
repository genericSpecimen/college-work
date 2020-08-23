# run using the command ``` source("people.r") ``` inside the interactive R environment

library(editrules)

# read the csv file
people <- read.csv("people.txt")
people


# read the editrules file
rules <- editfile("rules.txt")
rules

#Determine which record violates which edits. 
ve <- violatedEdits(rules, people)

# summary of the violatedEdits
summary(ve)

# plot the results
plot(ve)

