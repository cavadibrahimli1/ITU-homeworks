# NumPy program to create a 2D array with 1 on the border and 0 inside.
import numpy as np

# Specify the dimensions of the desired 2D array
rows, cols = 5, 5  # You can change these dimensions as needed

# Create a 2D array filled with zeros
array = np.zeros((rows, cols))

# Set the border elements to 1
array[0, :] = 1
array[-1, :] = 1
array[:, 0] = 1
array[:, -1] = 1

print(array)
