#include "Decomposition.h"
#include <fstream>
#include <iostream>

void decomposition::Factorize(uint64_t val) {
	number = val;
	uint64_t CurVal = val;
	for (uint64_t temp = 2; temp * temp <= CurVal; temp++) {
		while (!(CurVal %temp)) {

			CurVal /= temp;
			data.push_back(temp);
		}
	}
	if (CurVal != 1)
		data.push_back(CurVal);
}
void decomposition::GetDecompositiontoFile(const std::string &input, const std::string &output)
{
	std::ifstream fin(input);
	std::ofstream fout(output);

	uint64_t num;
	while (fin >> num)
	{
		Factorize(num);
		fout << GetDecomposition();
	}
	fin.close();
	fout.close();

}
std::string decomposition::GetDecomposition()
{
	std::string res = std::to_string(number) + " = ";
	for (int i = 0; i < data.size() - 1; ++i) {
		res += std::to_string(data[i]) + " * ";
	}
	res += std::to_string(data.back()) + "\n";
	return res;

}
bool decomposition::CheckDecomopisition()
{
	uint64_t  check = 1;
	for (auto it : data)
		check *= it;

	return (check == number);

};