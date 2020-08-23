function J = computeCost(X, y, theta)

m = length(y); % number of training examples
J = 0;
prediction = X * theta;

error = prediction - y;

squared_error_sum = error' * error;

J = (1/(2*m)) * squared_error_sum;

end

