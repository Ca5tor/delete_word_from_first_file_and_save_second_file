#include "Header.h"

void	TextFromFileInStr(std::string name_file){
	std::ifstream	file;
	std::string		str;
	std::string		line;

	file.open(name_file);
	if (!file){
		std::cout << "Ñan't open file\n";
		file.close();
	}
	else{
		while (getline(file, str)){
			line += str;
			if (!file.eof()) line += '\n';
		}
		file.close();
		WritingToNewFile(line);
	}
}

void	WritingToNewFile(std::string text){
	std::string	new_text = "";
	bool		flag_b;
	bool		flag_c;
	int			iter;
	int			i = 0;
	int			j;

	while (text[i]){
		iter = 0;
		j = i;
		flag_b = false;
		flag_c = false;
		while ((text[j] >= 'a' || text[j] >= 'A') && (text[j] <= 'z' || text[j] <= 'Z')){
			if (text[j] == 'b') flag_b = true;
			if (text[j] == 'c') flag_c = true;
			iter++;
			j++;
		}
		if (flag_b && flag_c) i += iter + 1;
		new_text += text[i];
		i++;
	}
	std::ofstream new_file;
	new_file.open("f2.txt");
	new_file << new_text;
	new_file.close();
	std::cout << "Done!\n";
}