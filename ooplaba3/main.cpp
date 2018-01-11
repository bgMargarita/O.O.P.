#include <iostream>
#include "WavCore.h"
#include <string>
#include "WavHeaderException.h"
#include "WavException.h"
using namespace std;
int main() {
	string fileName;
	cin >> fileName;
	WavCore wav(fileName);

}