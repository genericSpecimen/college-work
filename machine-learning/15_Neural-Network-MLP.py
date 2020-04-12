from sklearn import preprocessing
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.neural_network import MLPClassifier
from sklearn.metrics import classification_report, confusion_matrix, accuracy_score
import numpy as np

iris_data = load_iris()

X = iris_data.data
y = iris_data.target

X = preprocessing.scale(X)

# train test split (60 - 40)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.4, random_state = 5)

print(f"Dimensions of X: {X.shape}, of y: {y.shape}")
print(f"Dimensions of X_train: {X_train.shape}, of y_train: {y_train.shape}")
print(f"Dimensions of X_test: {X_test.shape}, of y_test: {y_test.shape}")

# use Stochastic Gradient Descent

nn = MLPClassifier(solver='sgd', hidden_layer_sizes=(5,), max_iter=2000, random_state=1).fit(X_train, y_train)

y_pred = nn.predict(X_test)

# same as (y_pred == y_test).mean()

print(accuracy_score(y_test, y_pred))
print(confusion_matrix(y_test, y_pred))

target_names = ["setosa", "versicolor", "virginica"]
print(classification_report(y_test, y_pred, target_names=target_names))

