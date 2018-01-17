#pragma once
#include <vector>
#include <cstdint>
#include <string>
class decomposition {

public:
	std::string GetDecomposition();
	bool CheckDecomopisition();
	void Factorize(uint64_t);
	void GetDecompositiontoFile(const std::string &, const std::string &);
private:
	uint64_t number;
	std::vector<int> data;

};
