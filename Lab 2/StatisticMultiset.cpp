#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <fstream>
#include <string>
#include "StatisticMultiset.h"

template <class T> StatisticMultiset<T>::StatisticMultiset() : sum(0) {}

template <class T> void StatisticMultiset<T>::AddNum(T const &num) {
	data.insert(num);
	sum += num;
}

template <class T> void StatisticMultiset<T>::AddNum(std::multiset<T> const &numbers) {
	for (auto &i : numbers) {
		data.insert(i);
		sum += i;
	}
}

template <class T> void StatisticMultiset<T>::AddNum(std::vector<T> const &numbers) {
	for (auto &i : numbers) {
		data.insert(i);
		sum += i;
	}
}

template <class T> void StatisticMultiset<T>::AddNum(std::list<T> const &numbers) {
	for (auto &i : numbers) {
		data.insert(i);
		sum += i;
	}
}

template <class T> void StatisticMultiset<T>::AddNum(StatisticMultiset<T> const &a_stat_set) {
	if (this != &a_stat_set) {
		AddNum(a_stat_set.data);
	}
	else {
		for (auto i = a_stat_set.data.begin(); i != a_stat_set.data.end(); i++) {
			data.insert(*i);
			sum += *i;
			i++;
		}
	}
}

template <class T> void StatisticMultiset<T>::AddNumsFromFile(char const * filename) {
	std::ifstream in(filename);
	if (!in.good())
		std::cerr << "File can not be opened!\n";
	T Mset;
	while (in >> Mset) {
		AddNum(Mset);
		sum += Mset;
	}
}

template <class T> T StatisticMultiset<T>::GetMin() const {
	return *data.begin();
}

template <class T> T StatisticMultiset<T>::GetMax() const {
	return *data.rbegin();
}

template <class T> float StatisticMultiset<T>::GetAvg() const {
	float ans = 0;
	if (data.size() == 0)
		std::cerr << "StatisticMultiset is empty! \n";
	else
		ans = (sum / data.size());
	return ans;
}

template <class T> int StatisticMultiset<T>::GetCountUnder(float const &threshold) const {
	int ans = 0;
	for (auto i = data.begin(); i != data.end() && *i < threshold; i++)
		++ans;
	return ans;
}

template <class T> int StatisticMultiset<T>::GetCountAbove(float const &threshold) const {
	int ans = 0;
	for (auto i = data.rbegin(); i != data.rend() && *i > threshold; i++)
		++ans;
	return ans;
}