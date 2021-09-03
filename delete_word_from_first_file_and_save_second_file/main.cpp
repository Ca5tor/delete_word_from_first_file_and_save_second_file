#include "Header.h"

bool	CheckFile(std::string name_file){
	bool			is_exist = true;
	std::ifstream	fin(name_file.c_str());

	if (!fin.is_open()){
		is_exist = false;
		std::cout << "File not found!\n";
	}
	fin.close();

	return is_exist;
}

int	main(void){
	std::string	name_file;

	std::cout << "Enter name file: ";
		std::cin >> name_file;
	if (CheckFile(name_file)) TextFromFileInStr(name_file);
	
	std::cin.get();
	std::cin.get();
	return 0;
}