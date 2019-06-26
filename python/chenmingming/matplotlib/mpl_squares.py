import matplotlib.pyplot as plt
input_values = [1, 2, 3, 4, 5]
squares = [1, 4, 9, 16, 25]
plt.plot(input_values, squares, linewidth=10)
plt.title("Square Numbers", size=24)
plt.xlabel("Value", size=14)
plt.ylabel("Square of Value", size=14)
plt.tick_params(axis="both", size=14)
plt.show()