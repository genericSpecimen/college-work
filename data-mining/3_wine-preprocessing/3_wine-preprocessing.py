import pandas as pd
import numpy as np
import sklearn.preprocessing as ppr

f = pd.read_csv("wine.csv")


# store target attribute (wine class) in y
# we don't standardize the target attribute
y = f['Wine']

# store data attributes (all except Wine class) in X
X = f.drop('Wine', axis=1)

print("\n------------ Original data set ---------------")
print("=> Mean of each column:")
print(np.mean(X), "\n")
print("=> Standard deviation of each column:")
print(np.std(X), "\n")
print("----------------------------------------------")


print("\n=> Standardizing using 'sklearn.preprocessing.scale' ...")
# sklearn works with numpy arrays, so scale returns a numpy array
s_X = ppr.scale(X)

# We create a DataFrame object from the numpy array by using the same indices
# and columns from X. This also helps with pretty output.
standardized_X = pd.DataFrame(s_X, index = X.index, columns = X.columns)

print("\n---------- Standardized data set -------------")
print("=> Mean of each column:")
print(np.mean(standardized_X), "\n")
print("=> Standard deviation of each column:")
print(np.std(standardized_X))
print("----------------------------------------------")
print(standardized_X)

