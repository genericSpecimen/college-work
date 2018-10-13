#include<iostream>
#include<string>

std::string& strip_leading_zeroes(std::string& str) {
	while(str[0] == '0') {
		str = str.substr(1,str.length());
	}
	return str;
}

std::string xor_strings(const std::string& s1, const std::string& s2) {
    std::string temp("");
    for(int i=0;i<s1.length();i++) {
        temp += (char) (((s1[i] - '0') ^ (s2[i] - '0')) + 48);
    }
    return temp;
}

std::string crc_remainder(std::string& dividend, std::string& divisor) {
	//returns the remainder string that will be appended to input string
	/*
	*	1. Pick the same number of bits of dividend as in divisor
	*	2. Perform XOR operation on these bits. The result of this operation is the current remainder.
	*	3. Strip leading zeros of current remainder, if any, and append appropriate number of bits from
	*	   the dividend to form the new dividend that has same number of bits as divisor.
	*	4. Keep performing XOR until no more dividend bits can be appended to form the new dividend.
	*/
    std::string remainder("");
	const int num_bits_divisor = divisor.length();

	std::string temp;
	int i=0; //keeps track of the index till which we have processed the dividend
	temp = dividend.substr(i, num_bits_divisor);
	i += num_bits_divisor;
	do {
		/*
		std::cout << "___________________________________\n";
		std::cout << "Current dividend: " << temp << std::endl;
		std::cout << "Current divisor : " << divisor << std::endl;
		std::cout << "----------------------\n";
		*/
		remainder = xor_strings(temp, divisor);
		int length1 = remainder.length();
		// std::cout << "Remainder       : " << remainder << std::endl;

		remainder = strip_leading_zeroes(remainder);
		int length2 = remainder.length();
		int num_zeroes_stripped = length1 - length2;
		/*
    	std::cout << "Number of zeroes stripped: " << num_zeroes_stripped << std::endl;
		std::cout << "Remainder       : " << remainder << std::endl;
		std::cout << "___________________________________\n";
		*/
		temp = dividend.substr(i, num_zeroes_stripped);
		remainder += temp;
    	temp = remainder;
		i += num_zeroes_stripped;
	} while(remainder.length() >= divisor.length());
	return remainder;
}

int main() {
	std::string input_string("000000010100001");
	std::string generator("1001");
	/*
	std::cout << "Enter data (without leading zeroes): ";
	std::cin >> input_string;
	*/
	
	std::cout << "Original data: " << input_string << std::endl;
	std::cout << "Generator    : " << generator << std::endl;

	std::cout << "Stripping leading zeroes, if any: ";
	input_string = strip_leading_zeroes(input_string);
	std::cout << input_string << std::endl;

	std::string remainder = crc_remainder(input_string, generator);
	std::cout << "Remainder bits: " << remainder << std::endl;
	input_string += remainder;
	std::cout << "Data transmitted after applying CRC: " << input_string << std::endl;
}
