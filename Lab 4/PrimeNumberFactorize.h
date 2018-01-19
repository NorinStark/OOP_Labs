#pragma once

#include <vector>
#include <string>


class PrimeNumberFactorization {
public:

	PrimeNumberFactorization(unsigned int num);
	const std::string toString();
	const std::vector<unsigned int>& getFactors();
	const unsigned int getValue();

private:
	unsigned int value;
	std::vector <unsigned int> factors;
	const std::string _convertInt(unsigned int num);

};