#pragma once
#include <fstream> 
#include <cstdlib> 
#include <iostream> 
#include <string> 
#include <map> 
#include <algorithm>
class IniParser {
private:
	std::map <std::string, std::map <std::string, std::string>> MapData;
public:

	IniParser();
	~IniParser();
	void IniParser::Initialize(const char*);

	void IniParser::Parse(const char*);

	bool IniParser::IsHaveSection(const std::string &) const;

	bool IniParser::IsHaveParam(std::string, std::string) const;

	template <typename T>
	T getValue(std::string const &section_name, std::string const &param_name) const;

};
