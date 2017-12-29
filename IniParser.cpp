#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <sstream>
#include "IniParser.h"
#include "IniParser_Excepttions.h"

using namespace std;

int index_ = 0;
int read_index__ = 0;
bool flag = false;
bool static section_flag_ = false;
bool section_pram_flag_ = false;

string str;
char* ch;
string needle = "[";
string needle1 = ";";
string start_brace_ = "[";
string end_brace_ = "]";
string build_input_section_string__ = "[";
string hold_data__[8000];

IniParser::IniParser(const char* fname)
{
	Initilization(fname);
}
IniParser::~IniParser()
{
	cout << "DESTROY ... " << "\n";
}

void IniParser::Initilization(const char* fileName) const throw (IniParser_Exceptions::exc_io)
{
	cout << "FILE READING .... " << "\n";
	ifstream infile(fileName);
	string g;

	if (!infile.is_open()) throw IniParser_Exceptions::exc_io(fileName);
	
	while (getline(infile, g))
	{
			hold_data__[index_] = g;
			index_++;
	}
	infile.close();
	cout << "DATA STORED ... " << "\n\n";
}

bool IniParser::IsHaveSection(const char* section_name) const throw (IniParser_Exceptions::exc_cfg_not_initied)
{
	build_input_section_string__ = build_input_section_string__ + section_name + end_brace_;    // BUILD THE HEADER OF THE SECTION NAME USING BRACES
	while (index_ > read_index__)
	{
		str = hold_data__[read_index__];
		if (!section_flag_)
		{
			if (!str.find_first_of(needle))
			{
				if (flag == true) flag = false;
				if (str == build_input_section_string__)
				{
					section_flag_ = true;
					break;
				}
				else throw IniParser_Exceptions::exc_cfg_not_initied();
			}
		}
		read_index__++;
	}
	return section_flag_;
}

bool IniParser::IsHaveParam(const char* section_name, const char* param_name) const throw (IniParser_Exceptions::exc_cfg_not_initied, IniParser_Exceptions::SectionNameException)
{
	read_index__ = 0;
	flag = false;
	section_flag_ = false;
	string build_input_section_string__1 = "[";
	build_input_section_string__1 = build_input_section_string__1 + section_name + "]";
	while (index_ > read_index__)
	{
		str = hold_data__[read_index__];
		if (!str.find_first_of(needle))
		{
			if (flag == true) flag = false;
			if (str == build_input_section_string__1)
			{
					section_flag_ = true;
					break;
			}
			else throw IniParser_Exceptions::exc_cfg_not_initied();
			
		}

		if (str.find_first_of(needle) && flag == true) // THIS CONDITION WILL BE TRUE WHEN IT WILL ACTUALLY FIND OUT THE SECTION NAME
		{
				if (!str.find(param_name)) throw IniParser_Exceptions::WrongParameterException(param_name);
		}
		else throw IniParser_Exceptions::SectionNameException(section_name);
		read_index__++;
	}
	return section_pram_flag_;
}

template<> 
int IniParser::GetValue<int>(const string &section_name, const string &param_name) const throw (IniParser_Exceptions::IniException)
{
	read_index__ = 0;
	int value_ = 0;
	flag = false;
	section_flag_ = false;
	string build_input_section_string__1 = "[";
	std::size_t pos = 0;
	std::string::size_type sz;
	build_input_section_string__1 = build_input_section_string__1 + section_name + "]";
	std::size_t found;

	while (index_ > read_index__)
	{
		str = hold_data__[read_index__];
		if (!str.find_first_of(needle))
		{
			if (flag == true) flag = false;
			if (str == build_input_section_string__1) {
					flag = true;
				}
		}

		if (str.find_first_of(needle) && flag == true)
		{
				if (!str.find(param_name))
				{
					pos = str.find("=");
					string tmpStr = str.substr(pos + 2, str.length());
					pos = tmpStr.find(" ");
					string val = tmpStr.substr(0, pos);
					if (val.find(".") != string::npos)
						value_ = -1;
					else
					{
						try
						{
							value_ = stoi(val);
							break;
						}
						catch (const exception e) { value_ = -1; }
					}
				}
				else throw IniParser_Exceptions::WrongParameterException(param_name);
			
		}
		read_index__++;
	}
	return value_;
}

template<>
double IniParser::GetValue<double>(const string &section_name, const string &param_name) const throw (IniParser_Exceptions::IniException)
{
	read_index__ = 0;
	double value_ = 0;
	flag = false;
	section_flag_ = false;
	string build_input_section_string__1 = "[";
	std::size_t pos = 0;
	std::string::size_type sz;
	build_input_section_string__1 = build_input_section_string__1 + section_name + "]";
	std::size_t found;

	while (index_ > read_index__)
	{
		str = hold_data__[read_index__];
		if (!str.find_first_of(needle))
		{
			if (flag == true) flag = false;
			if (str == build_input_section_string__1) {
					flag = true;
				}			
		}
		if (str.find_first_of(needle) && flag == true)
		{
			if (!str.find(param_name))
				{
					pos = str.find("=");
					string tmpStr = str.substr(pos + 2, str.length());
					pos = tmpStr.find(" ");
					string val = tmpStr.substr(0, pos);
					found = val.find(".");

					if (found == string::npos)
						value_ = -1;
					else
					{
						try
						{
							value_ = stold(val);
							break;
						}
						catch (const exception& e) { value_ = -1; }
					}
				}
			else throw IniParser_Exceptions::WrongParameterException(param_name);
		}
		read_index__++;
	}
	return value_;
}

template<>
std::string IniParser::GetValue<string>(const string &section_name, const string &param_name) const throw (IniParser_Exceptions::IniException)
{
	read_index__ = 0;
	string strvalue_ = "";
	flag = false;
	section_flag_ = false;
	string build_input_section_string__1 = "[";
	std::size_t pos = 0;
	std::string::size_type sz;
	build_input_section_string__1 = build_input_section_string__1 + section_name + "]";
	std::size_t found;

	while (index_ > read_index__)
	{
		str = hold_data__[read_index__];
		if (!str.find_first_of(needle))
		{
			if (flag == true) flag = false;
			if (str == build_input_section_string__1) {
					flag = true;
				}	
		}

		if (str.find_first_of(needle) && flag == true)
		{
				if (!str.find(param_name))
				{
					pos = str.find("=");
					string tmpStr = str.substr(pos + 2, str.length());
					pos = tmpStr.find(" ");
					string val = tmpStr.substr(0, pos);
					try
					{
						strvalue_ = "-1";
						stod(val);
						break;
					}
					catch (const exception e)
					{
						strvalue_ = val;
						break;
					}

					try
					{
						strvalue_ = "-1";
						stoi(val);
						break;
					}
					catch (const exception e)
					{
						strvalue_ = val;
						break;
					}
				}
				else throw IniParser_Exceptions::WrongParameterException(param_name);
		}
		read_index__++;
	}
	return strvalue_;
}

