/**
 * ParseFilecontent.h
 * @author Amer Chahda AC.
 * @date 2018-08-03
 *
 * @brief This Class is response to:
 *  *Read the file and show it on the screan.
 *  *Create a vector to save the words with out punctuation and close the txt-file.
 *  *Shows the number of words in the file.
 *  *Searching after a specific word in the file.
*/

#ifndef PARSEFILECONTENT_H_
#define PARSEFILECONTENT_H_

#include "FileHandler.h"
#include <string>
#include <locale>         ///< std::locale, std::isalpha
#include <vector>
#include <algorithm>
#include <sstream>

class Parse_File_content
{
	public:

		Parse_File_content(FileHandler w_f);
		Parse_File_content();
		virtual ~Parse_File_content();
		void print_vector(std::vector <std::string> word_vec);
		void read_file(bool fstatuse,std::vector <std::string> & word_vec);
		void counting_words();
		void search_after_word(std::string key_word, std::vector <std::string> & word_vec);
		void call_exit_fun();

	private:

			FileHandler m_working_file;///< An object from FileHandler class to be able to use easly the function open_file which declare in the FileHandler class.

};

#endif /* PARSEFILECONTENT_H_ */
