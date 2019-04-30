import matplotlib.pyplot as plt
from random_walk import RandomWalk
rw = RandomWalk(5000)
rw.fill_walk()
plt.figure(dpi=512, figsize=(10, 6))
point_number = list(range(rw.num_points))
plt.scatter(rw.x_value, rw.y_value, c=point_number, cmap=plt.cm.Blues, edgecolors='none', s=1)
plt.scatter(0, 0, c="green", edgecolors='none', s=100)
plt.scatter(rw.x_value[-1], rw.y_value[-1], c="red", edgecolors='none', s=100)
# plt.axis('off')
plt.show()