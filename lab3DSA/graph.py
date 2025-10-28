
import numpy


from sklearn.linear_model import LinearRegression
from matplotlib import pyplot as plt


# Load the data from a text file
#data = numpy.loadtxt('cmake-build-debug/hashSearch.txt',  usecols=(0, 1))
#data = numpy.loadtxt('cmake-build-debug/BTSsearch.txt',usecols=(0, 1))
#data = numpy.loadtxt('cmake-build-debug/BinarySearch.txt', usecols=(0, 1))
data = numpy.loadtxt('cmake-build-debug/sequential.txt',usecols=(0, 1))


# Split the data into independent and dependent variables
X = data[:, :-1]
y = data[:, -1]

# Create a linear regression model
model = LinearRegression()

# Train the model using the data
model.fit(X, y)

# Print the coefficients of the linear regression line
print('Coefficients:', model.coef_)

# Predict the dependent variable using the model
y_pred = model.predict(X)

# Plot the results
plt.scatter(X, y)
plt.plot(X[:, 0], y_pred, color='red')
plt.xlabel('size of element')
plt.title('Binary_10^5')
plt.ylabel('time ms')
plt.show()
