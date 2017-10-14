#include <fstream> 
#include <cstdlib> 
#include <iostream> 
#include <string> 
#include <map> 
#include <algorithm>
#include "IniParser.h" 
#include "Exception.h"
; using namespace std;
IniParser::IniParser() {};
IniParser::~IniParser() {};
void IniParser::Initialize(const char* filename_cstr) {
	string s;
	ifstream fin(filename_cstr);
	if (!fin.is_open()) throw wrongFile("File doesn't exist or can't be read");
	while (fin)
	{
		getline(fin, s);
		cout << s << endl;
	}
}

void IniParser::Parse(const char* filename_cstr)
{

	ifstream fin;
	fin.open(filename_cstr);
	string s;
	string param_name;
	string param_value;
	string last_section_name;
	while (getline(fin, s))
	{

		if (s.find(';') != string::npos)
		{
			int position = s.find(';');
			s = s.substr(0, position);
		}

		string str(s);
		s = "";

		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] != ' ') s = s + str[i];
		}
		if (s.length() >= 3)
		{
			int position1 = s.find('[');
			int position2 = s.find(']');

			if (position1 != string::npos && position2 != string::npos)
				last_section_name = s.substr(position1 + 1, position2 - 1);

			if (s.find('=') != string::npos)
			{
				int position = s.find('=');
				param_name = s.substr(0, position);
				param_value = s.substr(position+1, s.length());
			}
		}
		if (last_section_name != "" && param_name != "")
		{
			MapData[last_section_name][param_name] = param_value;
			param_name = "";
		}
	};
};
bool IniParser::IsHaveSection(const string &section_name) const
{
	auto search = MapData.find(section_name);
	if (search != MapData.end())
		return true;

	else throw NoSuchSection("Section not found");
	return false;
};
bool IniParser::IsHaveParam(string section_name, string param_name) const {
	auto search = MapData.find(section_name);
	if (search != MapData.end())
	{
		auto search2 = search->second.find(param_name);
		if (search2 != search->second.end())
			return true;
		else throw NoSuchParam("Parametre not found");

	}
	return false;


};

template<>
string IniParser::getValue<string>(string const &section_name, string const &param_name) const
{
	string temp;
	if (IsHaveParam(section_name, param_name))
		temp = MapData.at(section_name).at(param_name);
	else throw NoSuchParam("Parametre not found");
	return temp;
};

template<>
int IniParser::getValue<int>(string const &section_name, string const &param_name) const
{
	int temp;
	if (!stoi(MapData.at(section_name).at(param_name))) throw wrongType("Data type cannot be cast");
	temp = stoi(MapData.at(section_name).at(param_name));
	return temp;
};

template<>
double IniParser::getValue<double>(string const &section_name, string const &param_name) const {
	double temp;
	if (!stod(MapData.at(section_name).at(param_name))) throw wrongType("Data type cannot be cast");
	temp = stod(MapData.at(section_name).at(param_name));
	return temp;

};


