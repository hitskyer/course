import numpy as np
a = np.arange(5)
a[[0,0,2]] = [1,2,3]
a = np.arange(5)
a[[0,0,2]] += 1
print(a)
