#include "IniParser.h"
#include "IniParser_Excepttions.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	const char* filename__ = "E:\\data.ini";
	IniParser myClassInstance(filename__);
	
	try {
		cout << myClassInstance.GetValue<int>("NCMD", "EnableChannelControl") << endl;
	}
	catch (IniParser_Exceptions::IniException &e) {
		cout << e.what() << endl;
	}

	getchar();
	return 0;

}
