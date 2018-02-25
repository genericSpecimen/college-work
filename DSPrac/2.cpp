#include<iostream>
int binarySearch(int a[],int l,int h,int element) {
	if(h >= l) {
		int low = l; int high = h;
		int mid = (low+high)/2;
		if(a[mid] == element)
			return mid;
		else if(a[mid] < element)
			return binarySearch(a,mid+1,h,element);
		else
			return binarySearch(a,l,mid-1,element);
	}
	return -1;
}

class SET {
public:
	int cardinality;
	int* elements;
	
	SET(int n) {
		cardinality = n;
		elements = new int[cardinality];
	}

	void getElements() {
		std::cout << "Enter the elements of the set: ";
		for(int i=0;i<cardinality;i++)
			std::cin >> elements[i];
	}

	void printElements() {
		std::cout << "{";
		for(int i=0;i<cardinality;i++) 
			std::cout << elements[i] << ',';
		std::cout << "}\n";
	}

	bool isSubsetOf(SET& obj) { //check if invoking object is a subset of passed object
		int i,j;
		if((*this).cardinality > obj.cardinality)
			return false;
		else {
			for(i=0;i<(*this).cardinality;i++) {
				for(j=0;j<obj.cardinality;j++) {
					if((*this).elements[i] == obj.elements[j])
						break;
				}
				if(j == obj.cardinality)
					return false;
			}
			return true;
		}
	}

	void print_union_set(SET& obj) { //display the union of the two sets
		int union_set_size = (*this).cardinality + obj.cardinality;
		int i,j;
		SET* union_set = new SET(union_set_size);
		for(i=0;i<(*this).cardinality;i++)
			union_set -> elements[i] = (*this).elements[i];
		for(j=0;j<obj.cardinality;j++)
			union_set -> elements[i+j] = obj.elements[j];
		//remove duplicates, if any
		for(int x=0;x<union_set_size;x++) {
			for(int y=x+1;y<union_set_size;) {
				if(union_set->elements[x] == union_set->elements[y]) {
					for(int z=y;z<union_set_size-1;z++)
						union_set->elements[z] = union_set->elements[z+1];
					--union_set_size;
				}
				else
					++y;
			}
		}
		union_set->cardinality = union_set_size;
		std::cout << "\nThe union set is: ";
		union_set -> printElements();
	}
	
	void print_intersection_set(SET& obj) {
		std::cout << "\nThe intersection set is: {";
		if(this->cardinality < obj.cardinality) {
			for(int i=0;i<this->cardinality;i++) {
				if(binarySearch(obj.elements,0,obj.cardinality,this->elements[i]) != -1)
					std::cout << this->elements[i] << ',';
			}
		}
		else if(obj.cardinality < this->cardinality) {
			for(int i=0;i<obj.cardinality;i++) {
				if(binarySearch(this->elements,0,this->cardinality,obj.elements[i]) != -1)
					std::cout << obj.elements[i] << ',';
			}
		}
		std::cout << "}\n";
	}

	void complement_set(SET& obj) {
		std::cout << "The complement of set B with respect to set A is: {";
		for(int i=0;i<this->cardinality;i++) {
			if(binarySearch(obj.elements,0,obj.cardinality,this->elements[i]) == -1)
				std::cout << this->elements[i] << ',';
		}
		std::cout << "}";
	}

	void set_difference(SET& obj) {
		std::cout << "The set difference A-B is: {";
		for(int i=0;i<this->cardinality;i++) {
			if(binarySearch(obj.elements,0,obj.cardinality,this->elements[i]) == -1)
				std::cout << this->elements[i] << ',';
		}
		std::cout << "}\n";
	}

	void symmetric_difference(SET& obj) {
		std::cout << "The symmetric difference is: {";
		for(int i=0;i<this->cardinality;i++) {
			if(binarySearch(obj.elements,0,obj.cardinality,this->elements[i]) == -1)
				std::cout << this->elements[i] << ',';
		}
		for(int i=0;i<obj.cardinality;i++) {
			if(binarySearch(this->elements,0,this->cardinality,obj.elements[i]) == -1)
				std::cout << obj.elements[i] << ',';
		}
		std::cout << "}\n";
	}

	void cartesian_product(SET& obj) {
		std::cout << "The cartesian product of A and B is: {";
		for(int i=0;i<this->cardinality;i++){
			for(int j=0;j<obj.cardinality;j++)
				std::cout << "(" << this->elements[i] << ',' << obj.elements[j] << "),";
		}
		std::cout << "}\n";
	}
	~SET() {
		delete[] elements;
	}
};

int main() {
	int num,option;
	char ans = 'y';
	std::cout << "Enter the number of elements of set A: ";
	std::cin >> num;
	SET sa(num);
	sa.getElements();
	std::cout << "\nSet A is: ";
	sa.printElements();
	std::cout << "Enter the number of elements of set B: ";
	std::cin >> num;
	SET sb(num);
	sb.getElements();
	std::cout << "\nSet B is: ";
	sb.printElements();
	do {
		std::cout << "What do you want to do?\n";
		std::cout << "1. Check whether set A is a subset of set B.\n";
		std::cout << "2. Display the union and intersection of set A and set B.\n";
		std::cout << "3. Display the complement of B with respect to A.\n";
		std::cout << "4. Display the set difference A-B and symmetric difference between set A and set B.\n";
		std::cout << "5. Display the cartesian product of set A and set B.\n";
		std::cout << "\nEnter your option: ";
		std::cin >> option;
		switch(option) {
			case 1: if(sa.isSubsetOf(sb))
						std::cout << "Yes, set A is a subset of set B.\n";
					else 
						std::cout << "No, set A is not a subset of set B.\n"; break;
			case 2: sa.print_union_set(sb);
					sa.print_intersection_set(sb); break;
			case 3: sa.complement_set(sb); break;
			case 4: sa.set_difference(sb);
					sa.symmetric_difference(sb); break;
			case 5: sa.cartesian_product(sb); break;
			default: std::cout << "\nInvalid option!";									
		}
		std::cout << "\nDo you want to continue? (y/n)";
		std::cin >> ans;
	} while(ans == 'y' || ans == 'Y');
	
}