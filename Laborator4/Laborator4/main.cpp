#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Sort.h"

using namespace std;

int main()
{
	Sort s1(10, 15, 35);
	cout << "Lungime vector 1: " << s1.GetElementsCount() << "\n";
	cout << "Sortare prin insertie:\n";
	s1.InsertSort();
	s1.Print();
	cout << "\n";
	
	//Sort sInit({ 1, 2, 3, 4, 5 ,6 });

	int vector2[] = { 18, 10, 34, 11, 12 };
	int nrElem2 = sizeof(vector2) / sizeof(vector2[0]);
	Sort s2(nrElem2, vector2);
	cout << "Lungime vector 2: " << s2.GetElementsCount() << "\n";
	cout << "Quick Sort:\n";
	s2.QuickSort(true);
	s2.Print();
	cout << "\n";

	
	
	int vector3[] = { 45, 12, 30, 11, 12, 14, 99 };
	int nrElem3 = sizeof(vector3) / sizeof(vector3[0]);
	Sort s3(vector3, nrElem3);
	cout << "Lungime vector 3: " << s3.GetElementsCount() << "\n";
	cout << "Bubble Sort:\n";
	s3.BubbleSort(true);
	s3.Print();
	cout << "\n";
	cout << "INTERCLASARE: \n";
	s2.Merge(s3);
	Sort s4(6, 12, 9, 14, 20, 18, 47);
	cout << endl;
	cout << "Lungime vector 4: " << s4.GetElementsCount() << "\n";
	cout << "Sortare prin insertie:\n";
	s4.InsertSort();
	s4.Print();
	cout << "\n";

	char *sir = new char[256];
	strcpy(sir, "72,15,19,10,3,11");
	Sort s5(sir);
	cout << "Lungime vector 5: " << s5.GetElementsCount() << "\n";
	cout << "Bubble Sort:\n";
	s5.BubbleSort(true);
	s5.Print();
	cout << "\n";
	delete[] sir;

	return 0;
}
