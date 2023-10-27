import numpy as np

G = np.array([5, -4.7, 99, 50, 6, -1, 0, 50, -78, 27, 10])

# (a) Select all of the positive numbers in G and store them in x.
x = G[G > 0]

# (b) Select all the numbers in G between 0 and 30 and store them in y.
y = G[(G >= 0) & (G <= 30)]

# (c) Select all of the numbers in G that are either less than -50 or greater than 50 and store them in z.
z = G[(G < -50) | (G > 50)]

print("x:", x)
print("y:", y)
print("z:", z)
