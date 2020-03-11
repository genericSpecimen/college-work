import numpy as np

a = np.random.randint(-10, 10, 9).reshape(3,3)
print("=> Matrix a:\n", a)

print("=> Taking absolute values of matrix a:\n")
b = np.abs(a)
print(b, "\n")

print("-> Taking negative of matrix a:\n")
c = -a
print(c, "\n")

col = [10,20,30]
print(f"=> Adding column {col} to the end of matrix a\n")
a = np.insert(a, a.shape[1], col, axis = 1)
print(a, "\n")

row = [100,200,300,400]
print(f"=> Adding row {row} to the end of matrix a\n")
a = np.insert(a, a.shape[0], row, axis = 0)
print(a, "\n")

c = np.min(a, axis = 0)
print(f"=> Minimum value in each column of a: {c}\n")

c = np.min(a, axis = 1)
print(f"=> Minimum value in each row of a: {c}\n")

d = np.max(a, axis = 0)
print(f"=> Maximum value in each column of a: {d}\n")

d = np.max(a, axis = 1)
print(f"=> Maximum value in each row of a: {d}")

e = a.sum()
print(f"=> Sum of all elements of a: {e}")

e = a[0,:].sum()
print(f"=> Sum of first row of a: {e}")

e = a[:,1].sum()
print(f"=> Sum of second column of a: {e}")

e = a.cumsum()
print(f"=> Cumulative sum across all elements: {e}")

e = a.cumsum(axis = 0)
print(f"=> Cumulative sum along each column:\n {e}")

e = a.cumsum(axis = 1)
print(f"=> Cumulative sum along each row:\n {e}")

