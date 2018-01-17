#include "Decomposition.h"
#include "ThreadPool.h"
#include <iostream>
using namespace std;
int main() {

	string filename;
	cin >>filename;
	ThreadPool threadpool(filename);
	threadpool.StartWork();

	return 0;

}