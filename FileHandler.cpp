////////////////////////////////////////////////////
/// FileHandler.cpp
///
///  Created on: 3 aug. 2018
///      Author: ACH11739
////////////////////////////////////////////////////
/**
 * FileHandler.cpp
 * @author Amer Chahda AC.
 * @date 2018-08-03
 *
 * @brief This cpp file contain the implementation of FileHandler class which is response to open and close the txt-file
 */
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
/**
 * \brief This function will open the txt file
 * \return file_statuse a boolean value of the file status "True" if the file was successfully open or "False" if not
 *
 */
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

/**
 * This function to close the file
 */
void FileHandler::exit_file()
{
	std::fstream current_file(get_file_path());
	std::cout<<"File closing now.....\n";
	current_file.close();
}
