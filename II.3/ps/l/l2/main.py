import numpy

# 1
# count = 0
# for i in range (10000):
#     M = set(numpy.random.randint(1, 366, 23))
#     if len(M)<23:
#         count+=1
#     print("Geschazte Wkt. von A: ", count/1000)
#     p=1
#     for k in range(23):
#         p=p*(365-k)/365
#     theorWkt = 1-p
#     print("Theoretische Wkt. P(A): ", f"{theorWkt:.6f}")

#2
# import numpy
# from matplotlib.pyplot import axis, plot, figure, show, legend
# fig = figure ()
# axis ("square")
# axis ((0, 1, 0, 1))
# X=numpy. random. random (25)
# Y=numpy. random. random (25)
# plot (X, Y, "bo")
# fig.suptitle ("Beispiel 1 ", fontweight ="bold")
# show()
# fig = figure ()
# axis ("square")
# axis ((0, 1, 0, 1))
# plot (X, numpy.square (X),"g*") # zufallige Punkte auf dem Bild der Funktion f(x)=x^2
# plot (X[-1], numpy.square (X[-1]), "g*",label="$f (x)=x^2$")
# legend (loc=' upper left')
# fig. suptitle ("Beispiel 2 ",fontweight ="bold")
# show()

# import numpy as np
# from math import dist, pi
# from matplotlib.pyplot import plot, figure, show
#
# n = 2000
# fig = figure()
# ax = fig.add_subplot(1, 1, 1)
# ax.set_aspect("equal")
# ax.set_xlim(0, 1)
# ax.set_ylim(0, 1)
#
# X = np.random.random(n)
# Y = np.random.random(n)
# count = 0
#
# Xr = []
# Yr = []
# Xb = []
# Yb = []
#
# for j in range(n):
#     if dist([X[j], Y[j]], [0.5, 0.5]) < 0.5:
#         count += 1
#         Xr.append(X[j])
#         Yr.append(Y[j])
#     else:
#         Xb.append(X[j])
#         Yb.append(Y[j])
#
# plot(Xr, Yr, "ro")
# plot(Xb, Yb, "bo")
# fig.suptitle("Approximation of π/4", fontweight="bold")
# show()
#
# print("π:", pi)
# print("Approximation of π:", 4 * count / n)
# print("Probability that a random point is inside the circle:", count / n)

#3
# import numpy as np
# import matplotlib.pyplot as plt
# from math import atan2, pi
#
# # Function to calculate angle between two vectors
# def angle(v1, v2):
#     dot_product = np.dot(v1, v2)
#     magnitude_product = np.linalg.norm(v1) * np.linalg.norm(v2)
#     return np.arccos(dot_product / magnitude_product)
#
# # Vertices of the square
# square_corners = np.array([[0, 0], [1, 0], [1, 1], [0, 1]])
#
# # Number of simulations
# n = 10000
#
# one_obtuse = []
# two_obtuse = []
#
# # Simulation loop
# for _ in range(n):
#     A = np.random.random(2)  # Random point A inside the square
#
#     obtuse_count = 0
#     for i in range(4):
#         # Triangle formed with A and two consecutive corners of the square
#         v1 = square_corners[i] - A
#         v2 = square_corners[(i + 1) % 4] - A
#         # Calculate the angle at point A
#         angle_at_A = angle(v1, v2) * 180 / pi
#         # Check if the angle is obtuse
#         if angle_at_A > 90:
#             obtuse_count += 1
#     # Classify based on the number of obtuse angles
#     if obtuse_count == 1:
#         one_obtuse.append(A)
#     elif obtuse_count == 2:
#         two_obtuse.append(A)
#
# # Convert to arrays for easier plotting
# one_obtuse = np.array(one_obtuse)
# two_obtuse = np.array(two_obtuse)
#
# # Plot the results
# plt.figure(figsize=(6, 6))
# if len(one_obtuse) > 0:
#     plt.scatter(one_obtuse[:, 0], one_obtuse[:, 1], color='turquoise', label='Exactly 1 obtuse angle', alpha=0.5)
# if len(two_obtuse) > 0:
#     plt.scatter(two_obtuse[:, 0], two_obtuse[:, 1], color='blue', label='Exactly 2 obtuse angles', alpha=0.5)
#
# plt.title('Random Points in the Square with Obtuse Angle Classification')
# plt.legend()
# plt.xlim(0, 1)
# plt.ylim(0, 1)
# plt.gca().set_aspect('equal', adjustable='box')
# plt.show()

#4
import numpy as np
import matplotlib.pyplot as plt

# Generate 500 random x values between 0 and 1
x_values = np.random.uniform(0, 1, 500)

# For each x, generate a corresponding y value between x and (1 - x)
y_values = np.random.uniform(x_values, 1 - x_values)

# Plot the two diagonals for reference
plt.figure()
plt.axis("square")
plt.axis((0, 1, 0, 1))
X = np.linspace(0, 1, 100)
plt.plot(X, X, "k-", label="y = x")           # Diagonal line y = x
plt.plot(X, 1 - X, "k-", label="y = 1 - x")   # Diagonal line y = 1 - x

# Plot the random points between the diagonals
plt.scatter(x_values, y_values, color='blue', s=10, alpha=0.6, label="Random points")

# Show legend and display the plot
plt.legend()
plt.show()

