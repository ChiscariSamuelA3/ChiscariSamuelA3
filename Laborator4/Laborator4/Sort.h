#pragma once
#include <initializer_list>

class Sort
{
	// add data members
	void inversare();
	void quickSortAlg(int, int);
	int partitionare(int, int);
	int *v, n;
public:
	// add constuctors

	Sort(int nrElem, int valMin, int valMax);
	//Sort(initializer_list<int> list);
	Sort(int nrElem, int *vector) :n(nrElem), v(vector) {}
	Sort(int *vector, int nrElem);
	Sort(int count, ...);
	Sort(char* sir);

	void InsertSort(bool ascendent = false);
	void QuickSort(bool ascendent = false);
	void BubbleSort(bool ascendent = false);
	void Merge(Sort& s);//interclaseaza lista sortata curenta cu lista sortata din s


	void Print();
	int  GetElementsCount();
	int  GetElementFromIndex(int index);
};