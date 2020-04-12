from sklearn.datasets import load_boston
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error
import matplotlib.pyplot as plt
import numpy as np

boston_data = load_boston()

# all attributes are to be used
X = boston_data.data
y = boston_data.target

# train test split (60 - 40)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.4, random_state = 5)

print(f"Dimensions of X: {X.shape}, of y: {y.shape}")
print(f"Dimensions of X_train: {X_train.shape}, of y_train: {y_train.shape}")
print(f"Dimensions of X_test: {X_test.shape}, of y_test: {y_test.shape}")

# fit using the training set
lin_reg = LinearRegression().fit(X_train, y_train)

# make prediction using test set
y_pred = lin_reg.predict(X_test)

mse_train = mean_squared_error(y_train, lin_reg.predict(X_train))
r2_train = lin_reg.score(X_train, y_train)
mse_test = mean_squared_error(y_test, y_pred)
r2_test = lin_reg.score(X_test, y_test)

perf_report = """
------------ Performance Report ------------
    Training set:
        Mean squared error = {}
        R2 score = {}
    Test set:
        Mean squared error = {}
        R2 score = {}
--------------------------------------------
"""
print(perf_report.format(mse_train, r2_train, mse_test, r2_test))

