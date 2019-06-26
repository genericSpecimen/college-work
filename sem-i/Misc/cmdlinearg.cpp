#include <iostream>
#include <string>
#include <map>

int main(int argc,const char *argv[]){
	std::map<char,int>map;
	std::string input(argv[1]);
	for(int i=0;i<input.length();i++){
		map[input[i]]++;
	}

	for(std::map<char,int>::iterator itr = map.begin();itr != map.end();++itr){
		std::cout << itr->first << " " << itr->second << std::endl;
	}
}