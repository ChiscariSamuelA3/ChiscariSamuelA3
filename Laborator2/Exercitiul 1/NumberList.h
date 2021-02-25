#pragma once

class NumberList
{
	int numbers[20];
	int count;

public:
	void Init();          

	bool Add(int x);      
	void Sort();          

	void Print();         

	bool Insert(int pozitie, int numar);

	void Remove(int pozitie);
};