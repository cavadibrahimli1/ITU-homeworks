import random

# Generate a random integer between 100 and 999 (including 100 and 999)
c = random.randint(100, 999)

# Extract the first digit
x = c // 100

# Extract the second digit
y = (c // 10) % 10

print("Random integer (c):", c)
print("First digit (x):", x)
print("Second digit (y):", y)
