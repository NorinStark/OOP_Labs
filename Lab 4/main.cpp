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
	
	PrimeNumberFactorization p;
	unsigned int num;
	while (in >> num)
	{
		std::vector <unsigned int> ans = p.getFactorization(num);
		out << num << "=";
		for (size_t i = 0; i < ans.size(); i++)
		{
			out << ans[i] << " ";
			if (i + 1 < ans.size())
			{
				out << "*";
			}
		}
		out << '\n';
	}
	out << p.toString() << endl;

	in.close();
	out.close();

	return 0;
}