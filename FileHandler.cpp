////////////////////////////////////////////////////
/// FileHandler.cpp
///
///  Created on: 3 aug. 2018
///      Author: ACH11739
////////////////////////////////////////////////////
#include <iostream>
#include "FileHandler.h"
FileHandler::FileHandler(std::string filepath)
{
	file_path=filepath;
}

FileHandler::FileHandler()
{
	// TODO Auto-generated constructor stub
}

FileHandler::~FileHandler()
{
	// TODO Auto-generated destructor stub
}

std::string FileHandler::get_file_path()
{
	return file_path;
}

std::string FileHandler::open_file()
	{
		std::string file_statuse="";
		std::string line;
		std::ifstream my_file(get_file_path());
		if (my_file.is_open())
		{
			file_statuse="The file is open.";
			while ( std::getline (my_file,line) )
			    {
			     std::cout << line << '\n';
			    }

		}
		else
		{
			file_statuse="Error while opening the file";
		}
		my_file.close();
		return file_statuse;
	}
