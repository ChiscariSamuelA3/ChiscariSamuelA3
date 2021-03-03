#include "Math.h"
#include <iostream>

using namespace std;

int main()
{
	cout << Math::Add(2, 3) << endl;
	cout << Math::Add(2, 4, 4) << endl;
	cout << Math::Add(1.43, 2.61) << endl;
	cout << Math::Add(1.44, 2.16, 1.5) << endl;
	cout << Math::Mul(4, 5) << endl;
	cout << Math::Mul(4, 5, 5) << endl;
	cout << Math::Mul(2.5, 5.4) << endl;
	cout << Math::Mul(2.5, 5.4, 2.1) << endl << endl;

	int a = 1, b = 2, c = 3;
	cout << Math::Add(3, a, b, c) << endl ;

	char* s = Math::Add("83", "35");
	cout << s << endl; //118
	delete[] s;

	char* s2 = Math::Add("250", "750");
	cout << s2 << endl; //1000
	delete[] s2;

	
	char* s3 = Math::Mul("123", 3);
	cout << s3<<endl;// 369
	delete[] s3;
	
	

	return 0;
}