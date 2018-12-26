#include <iostream>
#include <map>
#include <sstream>
#include "IniParser_Excepttions.h"

#pragma once

class IniParser
{
public:
	IniParser(const char*);
	~IniParser();
	void Initilization(const char* filename) const throw (IniParser_Exceptions::exc_io);
	bool IsHaveSection(const char* section_name) const throw (IniParser_Exceptions::exc_cfg_not_initied);
	bool IsHaveParam(const char* section_name, const char* param_name) const throw (IniParser_Exceptions::exc_cfg_not_initied, IniParser_Exceptions::SectionNameException);
	/*
	int GetValueInt(const char* section_name, const char* param_name) const;
	double GetValueDouble(const char* section_name, const char* param_name) const;
	std::string GetValueString(const char* section_name, const char* param_name) const;
	*/
	template<typename T>
	T GetValue(const std::string &section_name, const std::string &param_name) const throw (IniParser_Exceptions::IniException) ;
	

};
