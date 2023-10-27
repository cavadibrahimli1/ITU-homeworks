import numpy as np

# Coefficients matrix
coefficients = np.array([[4, -2], [-6, 1]])

# Right-hand side vector
rhs = np.array([-42, 31])

# Solve for [x, y] using the inverse of the coefficients matrix
solution = np.dot(np.linalg.inv(coefficients), rhs)

# Extract the values of x and y
x = solution[0]
y = solution[1]

print("The solution is:")
print(f"x = {x}")
print(f"y = {y}")
