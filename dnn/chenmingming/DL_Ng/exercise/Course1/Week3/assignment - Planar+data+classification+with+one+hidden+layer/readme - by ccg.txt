Author：ccg

本作业注意：
(1) 2 - Dataset 中第二个程序段中：
plt.scatter(X[0, :], X[1, :], c=Y, s=40, cmap=plt.cm.Spectral);
可能报错，做以下更改即可：
plt.scatter(X[0, :], X[1, :], c=Y[0, :], s=40, cmap=plt.cm.Spectral);

(2) 3 - Simple Logistic Regression 中做以下修改：
#plot_decision_boundary(lambda x: clf.predict(x), X, Y)
#modify
plot_decision_boundary(lambda x: clf.predict(x), X, Y[0, :])

(3) 4.5 Predictions 中做以下修改：
#plot_decision_boundary(lambda x: predict(parameters, x.T), X, Y)
#modify
plot_decision_boundary(lambda x: predict(parameters, x.T), X, Y[0, :])

(4) 4.6 - Tuning hidden layer size (optional/ungraded exercise) 中做以下修改：
#plot_decision_boundary(lambda x: predict(parameters, x.T), X, Y)
#modify
plot_decision_boundary(lambda x: predict(parameters, x.T), X, Y[0, :])

(5) 5 - Performance on other datasets 中做以下修改：
#plt.scatter(X[0, :], X[1, :], c=Y, s=40, cmap=plt.cm.Spectral);
#modify
plt.scatter(X[0, :], X[1, :], c=Y[0, :], s=40, cmap=plt.cm.Spectral);
