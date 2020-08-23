x = [63; 66; 69; 71; 71; 75]
y = [127; 142; 162; 156; 169; 208]

mean(x)
mean(y)

x - mean(x)
y - mean(y)


b1_num = (x - mean(x)) .* (y - mean(y))
sum(b1_num)

b1_den = (x - mean(x)) .^ 2
sum(b1_den)


slope = sum(b1_num) / sum(b1_den)

intercept = mean(y) - (slope * mean(x))


