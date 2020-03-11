import numpy as np
from pprint import pprint

a = np.arange(20).reshape((5,4))
print("Matrix: ", "\n", a, "\n")

# compute size of matrix
print(f"Shape of matrix: {a.shape}")
print(f"Size of matrix : {a.size}")

# compute size/length of a particular row/column
row_2 = a[2]
print(f"Size of 2nd row:    {row_2}    is: {row_2.size}")

column_1 = a[:, 1]
print(f"Size of 1st column: {column_1} is: {column_1.size}", "\n")

# load data from a text file
f = "5_data.txt"
d = np.loadtxt(f)
print(f"Data loaded from file '{f}':", "\n", d, "\n")

# store matrix in a text file
f = "5_out.txt"
rg = np.random.default_rng(1)
matrix = rg.random((4,5))
print(f"Storing matrix in file '{f}': ", "\n", matrix, "\n")
np.savetxt(f, matrix, fmt = "%f")

# find out variables and their features in the current scope
l = dir()
print("Variables and their features in the current scope:")
pprint(l)
key = None
#for key in l:
    #pprint(dir(f"{key}"))



