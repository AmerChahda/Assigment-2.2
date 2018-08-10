////////////////////////////////////////////////////
/// FileHandler.cpp
///
///  Created on: 3 aug. 2018
///      Author: ACH11739
////////////////////////////////////////////////////

#include "FileHandler.h"

FileHandler::FileHandler(std::string filepath)
{
	file_path=filepath;
}

FileHandler::FileHandler()
{
}

FileHandler::~FileHandler()
{

}

std::string FileHandler::get_file_path()
{
	return file_path;
}

bool FileHandler::open_file()
{
	bool file_statuse = "false";
	std::ifstream my_file(get_file_path());
	if (my_file.is_open())
	{
		std::cout << "The file is open.\n";
		return file_statuse="true";
	}
	else
	{
		std::cout<<"Error while opening the file.\n";
		return file_statuse="false";
	}
}
/*void FileHandler::read_file(bool fstatuse)
{
	std::string line;
	std::ifstream current_file(get_file_path());
	if (fstatuse)
	{
		std::cout<<"=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<get_file_path()<<"=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n";
		while ( getline (current_file,line) )
		{
			std::cout << line << '\n';
		}
		std::cout<<"=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*= End of the file =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n";
	}
	else
	{
		std::cout<<"Error while reading the file";
	}
}
void FileHandler::counting_words()
{
	std::ifstream current_file(get_file_path());
	std::istream_iterator<std::string> in{ current_file }, end;
	std::cout << "Word count: " << std::distance(in, end)<<"\n------------------------------------------\n";
}
void FileHandler::search_after_word( std::string key_word)
{
	bool flag_word_exist;
	std::string line;
	std::ifstream current_file(get_file_path());
	while (getline(current_file, line))
	{
	   if (line.find(key_word) != std::string::npos)
	   {
		   std::cout << line << std::endl;
		   flag_word_exist="true";
       }
	}
	if (!flag_word_exist)
		std::cout << " not found\n";
}*/
void FileHandler::exit_file()
{
	std::fstream current_file(get_file_path());
	std::cout<<"File closing now.....\n";
	current_file.close();
}
