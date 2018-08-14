/*
 * ParseFilecontent.cpp
 *
 *  Created on: 8 aug. 2018
 *      Author: ACH11739
 */

#include "ParseFilecontent.h"

Parse_File_content::Parse_File_content(FileHandler w_f)
: m_working_file(w_f)
{
}

Parse_File_content::Parse_File_content()
{
}

Parse_File_content::~Parse_File_content()
{
}

/**
 * @brief this function to print out the word vector on the user screen.
 *
 *  @param[in] word_vec the vector where we save the word from the text file.
 */
void Parse_File_content::print_vector(std::vector <std::string> word_vec)
{
	for(auto i = word_vec.begin(); i != word_vec.end(); i++)
	{
		std::cout<< *i << "\n";
	}
}

/**
 * Read the text file with passing two parameters:
 * @param[in] fstatuse it is a boolean parameter to be sure that is the file is open.
 * @param[out] word_vec this vector to save the words and only the words from the text file.
 */
void Parse_File_content::read_file(bool fstatuse,std::vector <std::string> & word_vec)
{
	m_working_file.open_file();
	std::locale loc;
	std::string word;
	std::string temp;/// @var is a variable to save the value of the iterator pointer after convert it to small letter.
	std::string line;
	std::ifstream current_file(m_working_file.get_file_path());
	if (fstatuse)
	{
		std::cout << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=" << m_working_file.get_file_path() << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n";
		while ( getline (current_file, line) )
		{
			std::cout << line << '\n';
			for (std::string::iterator it=line.begin(); it!=line.end(); ++it)
			{
				if (std::isalpha(*it, loc))
				{
					temp = std::tolower(*it);
			        word.append(temp);
				}
			    else
			    {
			      word.append(" ");
			    }
			 }
			 std::istringstream iss(word);
			 copy(std::istream_iterator<std::string>(iss), std::istream_iterator<std::string>(), back_inserter(word_vec));
		}
		std::cout << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*= End of the file =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n";
		print_vector(word_vec);
	}
	else
	{
		std::cout << "Error while reading the file\n";
	}
}
/**
 * This function to counting the words inside the text file using istream_iterator which ignore the white space
 * and distance function
 * std::distance(in, end)\n
 * it is a ready function to measure the distance between start address to the end address
 * @param[in]  in first address.
 * @param[in]  end last sddress.
 * @return  distance The distance between them.
 */
void Parse_File_content::counting_words()
{
	std::ifstream current_file(m_working_file.get_file_path());
	std::istream_iterator <std::string> in{ current_file }, end;
	std::cout << "Word count: " << std::distance(in, end) << "\n------------------------------------------\n";
}

/**
 * This function looking after a word in the text file:
 * @param[in] key_word user word.
 * @param[in] word_vec the vector of words we created from the text file.
 * \n
 * before searching after the word it is good to be sure that all the letters in it are small.
 */
void Parse_File_content::search_after_word( std::string key_word, std::vector <std::string> & word_vec)
{
	transform(key_word.begin(), key_word.end(), key_word.begin(),::tolower);
	if (std::find(word_vec.begin(),word_vec.end(),key_word)!=word_vec.end())
	{
		std::cout << "\t\tThe word is exist :-)\n";
	}
	else
	{
		std::cout << "\t\tWord dose not exist :-(\n";
	}
}
/**
 * This function call the exit_fun which located in FileHandler class doing this through the object that we created from the FileHandlerclass as a private attribute in Parse_File_content this called composition
 */
void Parse_File_content::call_exit_fun()
{
	m_working_file.exit_file();
}

