#include <string>
#include <stdexcept>


#pragma once

using namespace std;

namespace IniParser_Exceptions {

	class IniException : public std::runtime_error {
	public: 
		explicit IniException(const std::string & arg) : runtime_error(arg){}
	};

	class exc_io : public  IniException {
	public:
		explicit exc_io(const std::string &fileName) : IniException(fileName + "file error"), fileName(fileName) {};

		std::string getFileName() const {
			return fileName;
		}
	private:
		std::string fileName;
	};

	class exc_cfg_not_initied : public IniException {
	public:
		explicit exc_cfg_not_initied() : IniException("Configure can't be initialised") {};

	};
	
	class SectionNameException : public IniException {
	public:
		explicit SectionNameException(const std::string &section_name) : IniException(section_name + "not found"), section_name(section_name){}

		std::string getSectionName() const {
			return section_name;
		}
	private:
		std::string section_name;
	};

	class WrongParameterException : public IniException {
	public:
		explicit WrongParameterException(const std::string &param_name) : IniException(param_name + "not found"), param_name(param_name) {}

			std::string getParam_name() const {
			return param_name;
		}
	private:
		std::string param_name;
	
	};

};
