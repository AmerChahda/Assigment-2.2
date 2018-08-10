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

void Parse_File_content::print_vector(std::vector <std::string> v)
{
	for(auto i = v.begin(); i != v.end(); i++)
	{
		std::cout<< *i << "\n";
	}
}

void Parse_File_content::read_file(bool fstatuse,std::vector <std::string> & word_vec)
{
	m_working_file.open_file();
	std::locale loc;
	std::string word;
	std::string temp;
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

void Parse_File_content::counting_words()
{
	std::ifstream current_file(m_working_file.get_file_path());
	std::istream_iterator <std::string> in{ current_file }, end;
	std::cout << "Word count: " << std::distance(in, end) << "\n------------------------------------------\n";
}

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

void Parse_File_content::call_exit_fun()
{
	m_working_file.exit_file();
}

