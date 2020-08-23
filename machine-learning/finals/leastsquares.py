from sklearn.linear_model import LinearRegression
import numpy as np

X = np.array([2, 5, 8, 12, 17]).reshape(1, -1)
y = np.array([6, 12, 15, 23, 29])

lin_reg = LinearRegression().fit(X, y)

print(lin_reg.intercept_)
print(lin_reg.coef_)

# test for x = 10
X_test = np.array([10]).reshape(-1, 1)
y_pred = lin_reg.predict(X_test)
print(y_pred)

