import numpy as np

t = 0.5

# bernstein polynomials
B03 = (1-t)**3
print(f"B03 = {B03}")
B13 = 3 * t * ((1-t)**2)
print(f"B13 = {B13}")
B23 = 3 * (t**2) * (1-t)
print(f"B23 = {B23}")
B33 = t**3
print(f"B33 = {B33}")

# control points
P1 = np.array([3, 3, 0]).reshape(3, 1)
P2 = np.array([4, 5, 0]).reshape(3, 1)
P3 = np.array([6, 5, 0]).reshape(3, 1)
P4 = np.array([8, 6, 0]).reshape(3, 1)

B03P1 = B03 * P1
print(f"B03P1 =\n {B03P1}")
B13P2 = B13 * P2
print(f"B13P2 =\n {B13P2}")
B23P3 = B23 * P3
print(f"B23P3 =\n {B23P3}")
B33P4 = B33 * P4
print(f"B33P4 =\n {B33P4}")

Q = B03P1 + B13P2 + B23P3 + B33P4
print(f"Q =\n {Q}")


