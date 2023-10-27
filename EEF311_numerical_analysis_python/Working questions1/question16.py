import numpy as np

# Specify the dimensions of the matrix
rows, cols = 8, 8

# Create an 8x8 matrix filled with zeros
matrix = np.zeros((rows, cols), dtype=int)

# Use slicing to set alternate elements to 1
matrix[1::2, ::2] = 1
matrix[::2, 1::2] = 1

print(matrix)
