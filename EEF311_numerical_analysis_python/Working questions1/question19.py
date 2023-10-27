import numpy as np
import matplotlib.pyplot as plt

# Generate values for t from -4π to 4π
t = np.linspace(-4 * np.pi, 4 * np.pi, 1000)

# Compute the corresponding values of x, y, and z
x = np.cos(t)
y = np.cos(t / 2)
z = 12 * np.cos(t)

# Plot the functions with different colors
plt.plot(t, x, label='x = cos(t)', color='blue')
plt.plot(t, y, label='y = cos(t/2)', color='green')
plt.plot(t, z, label='z = 12 * cos(t)', color='red')

# Add labels and a legend
plt.xlabel('t')
plt.ylabel('Function Value')
plt.title('Plot of Three Functions')
plt.legend()

# Show the plot
plt.grid(True)
plt.show()
