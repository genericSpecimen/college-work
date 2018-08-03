#include <iostream>
#include <string>
#include <map>

int main(){
	std::map<char,int>map;
	std::cout << "Enter a string : ";
	std::string input;
	std::getline(std::cin,input);
	for(int i=0;i<input.length();i++){
		map[input[i]]++;
	}

	for(std::map<char,int>::iterator itr = map.begin();itr != map.end();++itr){
		std::cout << itr->first << " " << itr->second << std::endl;
	}
}