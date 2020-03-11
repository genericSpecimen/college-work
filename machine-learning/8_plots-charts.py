import numpy as np
import matplotlib.pyplot as plt

# bar chart
data = [23, 45, 56, 78, 213]
x = [1, 2, 3, 4, 5]
plt.bar(x, data)
plt.title("Bar chart")
plt.show()

# histogram
data = np.random.randint(1, 51, 500)
bins = np.arange(51)
plt.hist(data, bins)
plt.title("Histogram with bins in the range 0..50")
plt.xlabel("x")
plt.ylabel("Frequency")
plt.show()

# sine function plot
x = np.arange(0, 4*np.pi, 0.1)
y = np.sin(x)
plt.plot(x,y)
plt.title("sine function plot")
plt.xlabel("x")
plt.ylabel("y = sin(x)")
plt.show()

# cosine function plot
x = np.arange(0, 4*np.pi, 0.1)
y = np.cos(x)
plt.plot(x,y)
plt.title("cosine function plot")
plt.xlabel("x")
plt.ylabel("y = cos(x)")
plt.show()

