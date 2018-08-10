/*
 * ParseFilecontent.h
 *
 *  Created on: 8 aug. 2018
 *      Author: ACH11739
 */

#ifndef PARSEFILECONTENT_H_
#define PARSEFILECONTENT_H_

#include "FileHandler.h"
#include <string>
#include <locale>         // std::locale, std::isalpha
#include <vector>
#include <algorithm>
#include <sstream>

class Parse_File_content
{
	public:

		Parse_File_content(FileHandler w_f);
		Parse_File_content();
		virtual ~Parse_File_content();
		void print_vector(std::vector <std::string> v);
		void read_file(bool fstatuse,std::vector <std::string> & word_vec);
		void counting_words();
		void search_after_word(std::string key_word, std::vector <std::string> & word_vec);
		void call_exit_fun();

	private:

			FileHandler m_working_file;

};

#endif /* PARSEFILECONTENT_H_ */
