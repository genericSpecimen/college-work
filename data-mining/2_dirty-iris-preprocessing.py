import pandas as pd
import matplotlib.pyplot as plt
from dirty_iris_ruleset import *

f = pd.read_csv("dirty_iris.csv")

# drop NAs {each row (axis = 0) where there's at least one NA (how = 'any')] to get all the complete observations
g = f.dropna(axis = 0, how = 'any')

# total number of observations
num_total = len(f)

# number of complete observations
num_complete = len(g)

percent_complete = (num_complete/num_total) * 100

print(f"Total number of observations        = {num_total}")
print(f"Number of complete observations     = {num_complete}")
print(f"Percentage of complete observations = {percent_complete}%")

# replace all special values with "NA"
f = f.fillna(value="NA")
#print(f)

num_violations = {
    'Species': 0,
    'props_positive': 0,
    'Petal.Length': 0,
    'Sepal.Length': 0,
    'sepal_petal_length': 0
    }

# assuming we use only the "complete" observations (g) from the data set
for key in num_violations.keys():
    print("\n\n--------------------------------------------------------------------------")
    print(f"=> Checking '{key}'...")
    num_violations[key] = di_ruleset[key](g)
    print(f"\nNumber of violations of rule associated with '{key}' = {num_violations[key]}")
    print("--------------------------------------------------------------------------")

print("\nDescription of data set")
print(g.describe())
print("\nSummary of ruleset application (format is <rule : num_violations> )")
print(num_violations)


plt.title("Ruleset Violations")
plt.ylabel("Number of violations")
plt.bar(num_violations.keys(), num_violations.values())
plt.show()


plt.title("Outliers (red square) in Sepal Length")
plt.ylabel("Sepal Length")
red_square = dict(markerfacecolor='r', marker='s')
plt.boxplot(g['Sepal.Length'], flierprops = red_square)
plt.show()

