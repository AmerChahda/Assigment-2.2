////////////////////////////////////////////////////
/// Parsing_File_main.cpp
///
///  Created on: 3 aug. 2018
///      Author: ACH11739
////////////////////////////////////////////////////
#include <iostream>
#include "FileHandler.h"

int main ()
{
	std::string myfile_path;
	bool my_file_statuse="false";
	std::cout<<"Enter the full file path\n";
	std::getline(std::cin,myfile_path);
	FileHandler obj_file(myfile_path);
	my_file_statuse=obj_file.open_file();
	obj_file.read_file(my_file_statuse);
	obj_file.counting_words();
	obj_file.exit_file();
	return 0;
}



