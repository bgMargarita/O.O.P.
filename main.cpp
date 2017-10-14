#include "IniParser.h" 
#include "Exception.h"
using namespace std;
int main()
{

	try {
		IniParser iniParser;
		iniParser.Initialize("lab01_input_correct_09.txt");
		iniParser.Parse("lab01_input_correct_09.ini");
		iniParser.IsHaveParam("COMMON", "LogNCMD");
		cout << iniParser.getValue<string>("COMMON", "LogNCMD") << endl;
		cout << iniParser.getValue<string>("DEBUG", "PlentySockMaxQSize") << endl;
		cout << iniParser.getValue<int>("DEBUG", "PlentySockMaxQSize") << endl;
		cout << iniParser.getValue<string>("1", "PlentySo8998ze") << endl;

	}
	catch (wrongFile &e) {
		cout << e.what() << endl;
	}
	system("pause");
	return 0;
}