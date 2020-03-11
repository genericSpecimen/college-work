import numpy as np

a = np.random.randint(1,10,6).reshape(2,3)
print("Matrix a:\n", a, "\n")

b = np.random.randint(1,10,6).reshape(2,3)
print("Matrix b:\n", b, "\n")

# addition of matrices
c = a + b
print("Addition of a and b:\n", c, "\n") 

# subtraction of matrices
d = a - b
print("Subtraction of a and b:\n", d, "\n") 

# multiplication of matrices uses the '@' operator
# the * operator performs element wise multiplication
b = b.reshape(3,2)
print("Reshaped b to shape {b.shape}:\n", b, "\n")
e = a @ b
print("Matrix multiplication of a and b :\n", e, "\n")

# display row 0 of matrix a
row_0 = a[0, :]
print("Row 0 of matrix a:", "\n", row_0)

# display column 1 of matrix b
column_1 = b[:, 1]
print("Column 1 of matrix b: ", "\n", column_2)

