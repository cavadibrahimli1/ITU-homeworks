import numpy as np

# Coefficients of the equations
A = np.array([[3, -1, 4],
              [17, 2, 1],
              [1, 12, -7]])

# Right-hand side of the equations
B = np.array([2, 14, 54])

# Solve the system of equations
solution = np.linalg.solve(A, B)

# The solution contains the values of x1, x2, and x3
x1, x2, x3 = solution

print("Solution:")
print("x1 =", x1)
print("x2 =", x2)
print("x3 =", x3)
