////////////////////////////////////////////////////
/// FileHandler.h
///
///  Created on: 3 aug. 2018
///      Author: ACH11739
////////////////////////////////////////////////////

#ifndef FILEHANDLER_H_
#define FILEHANDLER_H_

#include <string>
#include <fstream>

class FileHandler {
public:
	FileHandler(std::string fpath);
	FileHandler();
	virtual ~FileHandler();

	void set_file_path(std::string fpath);

	std::string get_file_path();
	std::string open_file();

private:
	std::string file_path;
};

#endif /* FILEHANDLER_H_ */
