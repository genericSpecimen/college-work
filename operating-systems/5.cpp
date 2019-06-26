#include<iostream>
#include<cstdlib>
int main(int argc, char* argv[]) {
	if(argc != 3) {
		std::cout << "Usage: copyfiles source destination\n";
		exit(1);
	} else {
		std::string source(argv[1]);
		source += " ";
		std::string dest(argv[2]);
		dest += " ";
		std::string cmd("cp ");
		cmd += source;
		cmd += dest;
		const char* command = cmd.c_str();
		std::system(command);
	}
}
