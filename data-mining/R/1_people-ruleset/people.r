# run using the command ``` source("people.r") ``` inside the interactive R environment

library(editrules)

people <- read.csv("people.txt")
people

rules <- editfile("rules.txt")
rules

ve <- violatedEdits(rules, people)
summary(ve)
plot(ve)

