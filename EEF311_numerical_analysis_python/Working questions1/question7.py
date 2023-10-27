import numpy as np

# Create the initial array with a single row and five columns
A = np.array([5, 8, -8, 99, 0])

# Reshape A to have one column and five rows
A_reshaped = A.reshape(5, 1)

# Print the original and reshaped arrays
print("Original array A:")
print(A)
print("Reshaped array A:")
print(A_reshaped)
