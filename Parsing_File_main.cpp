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
	std::cout<<"Enter the full file path\n";
	std::getline(std::cin,myfile_path);
	FileHandler obj_file(myfile_path);
	std::cout<<obj_file.open_file();
	return 0;
}



