#include <iostream>
#include <set>
#include <vector>
#include <list>
#include "StatisticMultiset.h"
#include "StatisticMultiset.cpp"

using namespace std;

int main(int argc, char *argv[]) {

	cout << "Lab 02" << "\n" << endl;
	StatisticMultiset<int> ms1;
	ms1.AddNum(89);
	ms1.AddNum(54);
	ms1.AddNum(54);
	ms1.AddNum(24);

	StatisticMultiset<int> ms2;
	std::vector<int> somedata = { 10, 40, 6, 87 };
	ms2.AddNum(somedata);

	StatisticMultiset<int> ms3;
	ms3.AddNum(ms1);
	ms3.AddNum(ms2);

	cout << "Min: " << ms3.GetMin()
		<< "\nAvg: " << ms3.GetAvg()
		<< "\nMax: " << ms3.GetMax()
		<< endl;

	system("pause");
	return 0;
}