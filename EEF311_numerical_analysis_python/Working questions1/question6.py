import numpy as np
import math

# Create an array of angles between 0 and 2π radians in increments of π/2 radians
angles_radians = np.arange(0, 2 * math.pi + math.pi/2, math.pi/2)

# (a) Calculate the sine of each angle in the array
sine_values = np.sin(angles_radians)

# (b) Calculate the cosine of each angle in the array
cosine_values = np.cos(angles_radians)

# (c) Convert each angle in the array to degrees
angles_degrees = np.degrees(angles_radians)

# Print the results
print("Angles in radians:", angles_radians)
print("Sine values:", sine_values)
print("Cosine values:", cosine_values)
print("Angles in degrees:", angles_degrees)
