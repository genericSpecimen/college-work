function [WA_gini, WA_entropy] = gini_entropy_ce(N)

num_nodes = size(N, 2)

WA_gini = 0;
WA_entropy = 0;
WA_classification_err = 0;
total = sum(sum(N))
for i=1:num_nodes
	printf("------------------------------------\n")
	node = N(:,i)
	total_in_node = sum(node)
	gini = 1 - sum((node ./ total_in_node) .^ 2)
	X = (node') / total_in_node;
	entropy = -(X * log2(X'))
	if(isnan(entropy))
	    entropy = 0
	end
	ce = 1 - max(node / total_in_node)
	printf("------------------------------------\n")
	WA_entropy += ((total_in_node / total) * entropy);
	WA_gini += ((total_in_node / total) * gini);
	WA_classification_err += ((total_in_node / total) * ce);
end

printf("Weighted average of gini: %f\n", WA_gini)
printf("Weighted average of entropy: %f\n", WA_entropy)
printf("Weighted average of classification error: %f\n", WA_classification_err)

end

# for single node
# N = [0; 6]

N = [2 2; 3 2]
gini_entropy_ce(N)

