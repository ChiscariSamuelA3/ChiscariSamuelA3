#include "MyVector.h"
#include <iostream>

using namespace std;

MyVector::MyVector(int maxCapacity)
{
	n = 0;
	capacitate = maxCapacity;
	vec = new int[capacitate];
}

bool MyVector::Add(int elem)
{
	if (n + 1 == capacitate)
	{
		return false;
	}

	vec[n++] = elem;
	return true;
}

bool MyVector::Delete(int index)
{
	if (index < 0 || index > n)
	{
		return false;
	}

	n--;
	for (int i = index; i < n; i++)
		vec[i] = vec[i + 1];

	return true;
}

void MyVector::Iterate(void(*callback)(int& x))
{
	for (int i = 0; i < n; i++)
	{
		callback(vec[i]);
	}
}

void MyVector::Filter(bool(*callback)(int x))
{
	for (int i = 0; i < n; i++)
	{
		if (callback(vec[i]))
		{
			Delete(i);
			i--;
		}
	}
}

void MyVector::afisare()
{
	for (int i = 0; i < n; i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}

MyVector::~MyVector()
{
	delete[] vec;
}