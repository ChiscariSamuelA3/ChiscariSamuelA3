#include "NumberList.h"
#include <iostream>
using namespace std;
int main()
{
	NumberList l;
	l.Init();
	int x;
	x = 0;
	
	while (l.Add(x));

	l.Print();
	l.Sort();
	l.Print();
	l.Insert(3, 20);
	l.Print();
	l.Remove(2);
	l.Print();

	return 0;
}