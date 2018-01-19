#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "PrimeNumberFactorize.h"

PrimeNumberFactorization::PrimeNumberFactorization(unsigned int num) {

	value = num;
	factors.push_back(1);

	if (num < 2 || num != 1)
		factors.push_back(num);
	if (num % 2 == 0)
		factors.push_back(2);

	for (int div = 3; num / div >= div; div += 2)
	{
		if (num%div == 0)
			factors.push_back(div);
	}

}

const std::string PrimeNumberFactorization::toString() {
	std::string factorStr(_convertInt(factors[0]));
	for (int i = 1; i < factors.size(); i++) {
		factorStr += " ";
		factorStr += _convertInt(factors[i]);
	}
	return std::move(factorStr);
}

const std::vector<unsigned int>& PrimeNumberFactorization::getFactors() {
	return factors;
}

const unsigned int PrimeNumberFactorization::getValue() {
	return value;
}

const std::string PrimeNumberFactorization::_convertInt(unsigned int num) {
	std::ostringstream oss;
	oss << value;
	return std::move(std::string(oss.str()));
}