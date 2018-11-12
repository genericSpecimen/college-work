#include<iostream>
int main(int argc, char* argv[]) {
	if(argc != 3) {
		std::cout << "Usage: copyfiles source destination\n";
		return 1;
	} else {
		std::string source(argv[1]);
		source += " ";
		std::string dest(argv[2]);
		dest += " ";
		
        std::string copy_cmd("cp ");
		copy_cmd += source;
		copy_cmd += dest;
		std::system(copy_cmd.c_str());
        std::cout << "Copied " << source << " into " << dest << std::endl;
        std::cout << "Contents of: " << dest << std::endl;

        std::string display_command("cat ");
        display_command += dest;
        std::system(display_command.c_str());  
	}
}