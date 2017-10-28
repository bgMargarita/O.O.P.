#pragma once
#include <cmath>
#include <map>
#include <queue>
#include <iostream>
#include <fstream>
#include <set> 
#include <list>
#include <vector>


template <typename T>
class StaticMultiset
{
private:
	std::multiset <T> Data;
	mutable std::map <T, int> CashedCountUnder;
	mutable std::map <T, int> CashedCountAbove;
	T max, min;
	mutable double CashedAvg;
	bool CashUpdate;
	

	


public:
	void AddNum(const T &num) {

		if (Data.empty()) {
			max = num;
			min = num;
			CashedCountAbove[num] = 0;
			CashedCountUnder[num] = 0;
		}
		else {
			if (num < min)
				min = num;
			
			if (num > max)
				max = num;
			CashedCountAbove[num] = 0;
			CashedCountUnder[num] = 0;
			for (auto &it : Data)
				{
				if (num < it)
				{
					CashedCountAbove[num]++;
					CashedCountUnder[it]++;
				}
				if (num > it)
				{
					CashedCountUnder[num]++;
					CashedCountAbove[it]++;
				}

				}

			}
		Data.insert(num);
		CashUpdate = 0;

	};

	void AddNums(const std::multiset<T> &numbers)
	{
		for (auto &i : numbers)
		{
			AddNum(i);
		}
	};
	void AddNums(const std::vector<T>& numbers)
	{
		for (auto &i : numbers)
		{
			AddNum(i);
		}
	};
	void AddNums(const std::list<T>& numbers)
	{
		for (auto &i : numbers)
			AddNum(i);
	};
	void AddNumsFromFile(const char* filename)
	{
		std::ifstream file;
		file.open(filename);
		T x;
		if (!file.good) return;
		while (file << x)
		{
			add_Num(x);
		}
	};
	T GetMax() const
	{
		return max;
	};

	T GetMin() const
	{
		return min;
	};

	double GetAvg() const
	{

		if (!CashUpdate)
		{
			double avg = 0;
			int temp = 0;
			for (auto &i : Data)
				temp += i;
			avg = temp / Data.size();
			CashedAvg = avg;
		}
		return CashedAvg;

	};
	
	int GetCountUnder(float threshold) const
	{
		if (CashedCountUnder.count(threshold))
		{
			return CashedCountUnder.at(threshold);
		};

		int counter = 0;
		for (auto &i : Data)
		{
			if (i < threshold)
				counter++;
		}
		CashedCountUnder[threshold] = counter;

		return CashedCountUnder.at(threshold);
	};
	int GetCountAbove(float threshold) const
	{
		if (CashedCountAbove.count(threshold)) 
		{
			return CashedCountAbove.at(threshold);
		};
		int counter = 0;
		for (auto &i : Data)
		{
			if (i > threshold)
				counter++;
		}
		CashedCountAbove[threshold] = counter;
		

		return CashedCountAbove.at(threshold);
	};
	

};


