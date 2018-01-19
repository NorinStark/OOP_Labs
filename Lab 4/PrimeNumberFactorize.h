#pragma once

#include <vector>
#include <cstddef>
#include <string>

#define MAXN 10001

class PrimeNumberFactorization {
public:

	void Prime_Num();
	const std::vector<unsigned int> getFactorization(unsigned int num);
	const std::string toString();

private:
	unsigned int prime_num[MAXN];
	const std::string _convertInt(unsigned int value);

};