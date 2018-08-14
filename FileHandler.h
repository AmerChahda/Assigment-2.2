/**
 * FileHandler.h
 * @author Amer Chahda AC.
 * @date 2018-08-03
 *
 * @brief This header file contain a declaration of FileHandler class which is response to open and close the txt-file
 */

#ifndef FILEHANDLER_H_
#define FILEHANDLER_H_

#include <string>
#include <fstream>
#include <iostream>
#include <iterator>

class FileHandler
{
	public:

		FileHandler(std::string fpath);
		FileHandler();
		virtual ~FileHandler();
		std::string get_file_path();
		bool open_file();
		void exit_file();

	private:

		std::string file_path; ///< variable to save the path of the file.
};

#endif /* FILEHANDLER_H_ */
