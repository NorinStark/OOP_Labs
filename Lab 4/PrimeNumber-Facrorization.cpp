#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "PrimeNumberFactorize.h"


void PrimeNumberFactorization::Prime_Num() {

	prime_num[1] = 1;
	for (int i = 2; i < MAXN; i++)
		prime_num[i] = i;

	for (int i = 4; i < MAXN; i += 2)
		prime_num[i] = 2;

	for (int i = 3; i*i < MAXN; i++)
	{
		if (prime_num[i] == i)
		{
			for (int j = i*i; i < MAXN; j += i)
				if (prime_num[j] == j)
					prime_num[j] = i;
		}
	}

}

const std::vector<unsigned int> PrimeNumberFactorization::getFactorization(unsigned int num){

	std::vector <unsigned int> value;
	while (num != 1)
	{
		value.push_back(prime_num[num]);
		num = num / prime_num[num];
	}
	return value;

}

const std::string PrimeNumberFactorization::toString() {
	std::string factorStr(_convertInt(prime_num[0]));
	for (int i = 1; i < MAXN; i++) {
		factorStr += " ";
		factorStr += _convertInt(prime_num[i]);
	}
	return std::move(factorStr);
}

const std::string PrimeNumberFactorization::_convertInt(unsigned int value) {
	std::ostringstream oss;
	oss << value;
	return std::move(std::string(oss.str()));
}