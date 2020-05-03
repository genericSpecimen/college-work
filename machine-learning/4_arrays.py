import numpy as np

one_d = np.array([1,2,3,4])
print("One dimensional array: ", one_d)
print(f"Shape of array = {one_d.shape}\n")

two_d = np.array([
        [1,2,3,4],
        [5,6,7,8]
    ])
print("Two dimensional array: ")
print(two_d)
print(f"Shape of array = {two_d.shape}\n")

three_d = np.array([
            [[1,2,3,4],
            [5,6,7,8]],

            [[9,10,11,12],
            [13,14,15,16]]
        ])
print("Three dimensional array: ")
print(three_d)
print(f"Shape of array = {three_d.shape}\n")

print("Array of all ones:")
o = np.ones([2,3])
print(o, "\n")

print("Array of all zeros:")
z = np.zeros([2,3])
print(z, "\n")


rg = np.random.default_rng(1)
# range is [10,100)
random_array = rg.uniform(10, 100, (2, 3))
print(f"Random array of shape {random_array.shape}: ")
print(random_array, "\n")

diagonal_matrix = np.diag((2,3,4,5), k=0)
print(f"Diagonal matrix of shape {diagonal_matrix.shape}: ")
print(diagonal_matrix, "\n")

