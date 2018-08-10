/*!
 * @author Amer Chahda AC.
 *
 * @version 0.1.
 *
 * @date 2018-08-10
 *
 * @bug When we searching after a word which contains not alphabet character
 *
 * @copyright MinGW Public License.
 *
 * @mainpage Parsing File and Search after a Word.
 *
 * @section intro_section Introduction
 * This program gives you the number of words are exist an a txt file and helps you to check if a word exist or not.
 *
 *
 */


#include <iostream>
#include "FileHandler.h"
#include "ParseFilecontent.h"
/*!
 * @brief In the main function you will find calling functions, creating objects and variable deceleration.
 */
int main ()
{
	std::string myfile_path; //!< Variables to save the path of the file.
	std::string key_word; //!< Variables to save the searching word.
	std::vector <std::string> word_vec; //!< Vector of string to save the words from the txt file and use it for searching.
	bool my_file_statuse="false";
	std::cout<<"Enter the full file path\n";
	std::getline(std::cin,myfile_path);
	FileHandler obj_file(myfile_path);
	Parse_File_content tasks_on_file(obj_file);
	my_file_statuse=obj_file.open_file();
	tasks_on_file.read_file(my_file_statuse,word_vec);
	tasks_on_file.counting_words();
	std::cout<<"Enter a word to search after it\n";
	std::getline(std::cin,key_word);
	tasks_on_file.search_after_word(key_word,word_vec);
	tasks_on_file.call_exit_fun();
	return 0;
}



