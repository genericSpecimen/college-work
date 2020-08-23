function [theta, J_history] = gradientDescent(X, y, theta, alpha, num_iters)

m = length(y); % number of training examples
J_history = zeros(num_iters, 1);

for iter = 1:num_iters
    printf("-------------Iteration %d-----------------\n", iter)
    hypothesis = X * theta
    error = hypothesis - y
    err_sum_t0 = sum(error)
    err_sum_t1 = sum(error .* X(:,2))
    err_sum_t2 = sum(error .* X(:,3))
    theta = theta - (alpha / m) * (X' * error)
    printf("-----------------------------------------\n")
   
    J_history(iter) = computeCost(X, y, theta);

end

end



X = [0 1; 1 2; 2 2; 3 1; 2 1];
y = [4; 7; 8; 7; 6];

m = length(y);
X = [ones(m, 1) X];

theta = [1; 1; 1];
iterations = 1;
alpha = 0.1;
gradientDescent(X, y, theta, alpha, iterations)	

