import numpy as np

a = np.random.randint(1, 10, (3, 3))
print(f"=> Matrix a of shape {a.shape}:\n", a, "\n")

a1 = a.transpose()
print(f"=> Transpose of matrix a: \n", a1, "\n")

b = np.random.randint(1, 10, (3,3))
print(f"=> Matrix b of shape {b.shape}:\n", b, "\n")

c = a + b
print(f"=> Matrix addition a + b:\n", c, "\n")

d = a - b
print(f"=> Matrix subtraction a - b:\n", d, "\n")

e = a @ b # use @ for matrix multiplication
print(f"=> Matrix multiplication a x b:\n", e, "\n")

