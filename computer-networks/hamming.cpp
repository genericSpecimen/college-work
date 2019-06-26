#include<iostream>
#include<cmath>
#include<vector>

void printArray(int a[], int size) {
	for(int i=0;i<size;i++) std::cout << a[i] << " ";
	std::cout << std::endl;
}

bool is_r_bit(int index, int r_bits_index[], int num_r_bits) {
	for(int i=0;i<num_r_bits;i++) {
		if(index == r_bits_index[i]) return true;
	}
	return false;
}

int convertToDecimal(std::vector<int> check_bits) {
	int decimal = 0;
	std::vector<int> temp; //store the check bits in a reverse order into temp
	for(std::vector<int>::reverse_iterator rit = check_bits.rbegin(); rit != check_bits.rend(); rit++) {
		temp.push_back(*rit);
	}
	int index = 0; //convert into decimal by multiplying each element by 2^(bit position)
	for(std::vector<int>::iterator itr = temp.begin(); itr != temp.end(); itr++, index++) {
		decimal += pow(2,index)*(*itr);
	}
	return decimal;
}

void set_redundant_bits(int packet[], int total_bits, int r_bits_index[], int num_r_bits, int num_data_bits) {
	//----------------------find the bits to be XORed-----------------------------
	std::vector<std::vector<int>> redundant;
	for(int i=0;i<num_r_bits;i++) {
		std::vector<int> temp;
		for(int j=1;j<=total_bits;j++) {
			if(((j>>i)&1) == 1 && !(is_r_bit(j, r_bits_index, num_r_bits))) {
				temp.push_back(packet[j-1]);
			}
		}
		redundant.push_back(temp);
	}
	//----------------------------------------------------------------------------

	//calculate the redundant bits by XOR-ing the bits found
	int redundant_bits[num_r_bits];
	int a = 0; // index of redundant_bits array
	std::vector<std::vector<int>>::iterator i;
	std::vector<int>::iterator j;
	for(i = redundant.begin(); i != redundant.end(); i++) {
		int temp = 0;
		for(j = i->begin(); j != i->end(); j++) {
			temp = temp^(*j);
		}
		redundant_bits[a++] = temp;
	}
	
	// set the redundant bits	
	for(int i=0,k=0;i<num_data_bits;i++) {
		int index = pow(2,i);
		packet[index-1] = redundant_bits[k++];
	}

}

void error_detection(int packet[], int total_bits, int r_bits_index[], int num_r_bits) {
	std::cout << "Data received   : ";
	for(int i=0;i<total_bits;i++) std::cout << packet[i] << " ";
	std::cout << std::endl;

	std::vector<std::vector<int>> check_bits_to_XOR;
	for(int i=0;i<num_r_bits;i++) {
		std::vector<int> temp;
		for(int j=1;j<=total_bits;j++) {
			if(((j>>i)&1) == 1) {
				temp.push_back(packet[j-1]);
			}
		}
		check_bits_to_XOR.push_back(temp);
	}

	std::vector<std::vector<int>>::iterator i;
	std::vector<int>::iterator j;
	std::vector<int> check_bits;
	for(i = check_bits_to_XOR.begin(); i != check_bits_to_XOR.end(); i++) {
		int temp = 0; // 0^x == x
		for(j = i->begin(); j != i->end(); j++) {
			temp = temp^(*j);
		}
		check_bits.push_back(temp);
	}

	std::cout << "Check bits: ";
	for(std::vector<int>::reverse_iterator rit = check_bits.rbegin(); rit != check_bits.rend(); rit++)
		std::cout << *rit << ", ";
	std::cout << std::endl;

	int error_bit_index = convertToDecimal(check_bits) - 1;
	std::cout << "Error at: " << (error_bit_index + 1) << std::endl;
	std::cout << "Data after correction: ";
	switch(packet[error_bit_index]) {
		case 0: packet[error_bit_index] = 1; break;
		case 1: packet[error_bit_index] = 0; break;
	}
	printArray(packet, total_bits);
	
}

int main() {
	int num_data_bits = 7;
	int data[num_data_bits]; //to store original data
	//------------------------------------------------------------
	
	std::cout << "Enter " << num_data_bits << " bits of data: ";
	for(int i=0;i<num_data_bits;i++) {
		std::cin >> data[i];
	}
	std::cout << "Original data: ";
	printArray(data, num_data_bits);
	
	//------------------------------------------------------------
	
	int num_r_bits = 4; //calculate later, according to the condition
	int r_bits_index[num_r_bits]; //stores the indices(positions) of the redundant bits

	for(int i=0;i<num_r_bits;i++) {
		r_bits_index[i] = pow(2,i);
	}
	std::cout << "The (index) positions of redundant bits are: ";
	printArray(r_bits_index, num_r_bits);

	//-------------------------------------------------------------
	int total_bits = num_data_bits + num_r_bits;
	int packet[total_bits];

	//set the non-redundant data
	for(int i=1,j=0;i<=total_bits;i++) {
		if(!is_r_bit(i, r_bits_index, num_r_bits)) {
			packet[i-1] = data[j];
			j++;
		}
	}

	//set the redundant bits
	set_redundant_bits(packet, total_bits, r_bits_index, num_r_bits, num_data_bits);
	std::cout << "Data transmitted: ";
	printArray(packet, total_bits);

	//manually create an error at the 6th bit
	int error_bit_index = 6;
	switch(packet[error_bit_index - 1]) {
		case 0: packet[error_bit_index - 1] = 1; break;
		case 1: packet[error_bit_index - 1] = 0; break;
	}
 	error_detection(packet,total_bits,r_bits_index,num_r_bits);
	
}
