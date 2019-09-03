import numpy as np
a = np.arange(5)
a[[0,0,2]] = [1,2,3]
a = np.arange(5)
a[[0,0,2]] += 1
print(a)

a = np.array([2,3,4,5])
b = np.array([8,5,4])
c = np.array([5,4,6,8,3])
def func(f, *vectors):
	vs = np.ix_(*vectors)
	r = f.identity
	for v in vs:
		r = f(r,v)
	return r


func(np.add, a, b, c)