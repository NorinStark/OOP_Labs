#pragma once

#include <vector>
#include <list>
#include <fstream>
#include <set>

template <class T>
struct StatisticMultiset {

	StatisticMultiset();

	void AddNum(T const &num);
	void AddNum(std::multiset<T> const &numbers);
	void AddNum(std::vector<T> const &numbers);
	void AddNum(std::list<T> const &numbers);
	void AddNum(StatisticMultiset<T> const &a_stat_set);
	void AddNumsFromFile(char const * const filename);

	T GetMax() const;
	T GetMin() const;
	float GetAvg() const;
	int GetCountUnder(float const &threshold) const;
	int GetCountAbove(float const &threshold) const;

private:
	std::multiset <T> data;
	T sum;
};

//#include "StatisticMultiset.cpp"
