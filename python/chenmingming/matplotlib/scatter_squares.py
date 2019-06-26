import matplotlib.pyplot as plt
x_values = list(range(1, 1001))
y_values = [x**2 for x in x_values]
plt.scatter(x_values, y_values, c=y_values, cmap=plt.cm.Blues, edgecolors='none', s=20)
plt.title("Square Numbers", size=24)
plt.xlabel("Value", size=14)
plt.ylabel("Square of Value", size=14)
plt.tick_params(axis="both", which="major", size=10)
plt.axis([0, 1100, 0, 1100000])
plt.show()
plt.savefig("squares_plot.pdf", bbox_inches="tight")