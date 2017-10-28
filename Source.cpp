#include "Header.h"
#include <iostream>
using namespace std;
int main()
{
	StaticMultiset<int> staticmultiset;
	multiset<int> multi_set;
	int t = 34;
	
	for (int i = 4; i < 10; ++i) 
	{
		staticmultiset.AddNum(i);
	}
	//for (int i = 4; i < 30; ++i)
	//{
	//	staticmultiset.AddNum(10 * (i + i));
	//}
	//staticmultiset.AddNums(multi_set);
	
	staticmultiset.GetMin();
	staticmultiset.GetMax();
	staticmultiset.GetAvg();
	staticmultiset.GetCountUnder(456);

	system("pause");

}