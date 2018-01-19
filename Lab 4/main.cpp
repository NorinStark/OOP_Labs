#include <string>
#include <fstream>
#include <vector>
#include <iostream>

#include "PrimeNumberFactorize.h"

using namespace std;

int main(int argc, char** argv) {

	string filename_in, filename_out;
	std::cin >> filename_in >> filename_out;
	std::ifstream in(filename_in);
	std::ofstream out(filename_out);

	if (!in.good() || !out.good())
	{
		std::cerr << "File IO error while opening\n";
	}
	
	if (in.is_open())
	{
		unsigned int num;
		while (!in.eof())
		{
			in >> num;
			PrimeNumberFactorization factors(num);
			out << factors.toString() << endl;
		}
	}

	in.close();
	out.close();


	return 0;
}