import numpy as np
import matplotlib.pyplot as plt

x = np.arange(0, 4*np.pi, 0.1)

fig, axs = plt.subplots(2, 2)

y = np.sin(x)
axs[0, 0].plot(x, y, "tab:red")
axs[0, 0].set_title("sine")
axs[0, 0].set(ylabel = "y = sin(x)")

y = np.cos(x)
axs[0, 1].plot(x, y, "tab:green")
axs[0, 1].set_title("cosine")
axs[0, 1].set( ylabel = "y = cos(x)")

y = np.exp(x)
axs[1, 0].plot(x, y, "tab:blue")
axs[1, 0].set_title("exp")
axs[1, 0].set(xlabel = "x", ylabel = "y = e^(x)")

x = np.arange(1,5, 0.1)
y = np.log10(x)
axs[1, 1].plot(x, y, "tab:orange")
axs[1, 1].set_title("log10")
axs[1, 1].set(xlabel = "x", ylabel = "y = log10(x)")

plt.show()

