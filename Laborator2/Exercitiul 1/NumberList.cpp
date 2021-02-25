#include "NumberList.h"
#include <iostream>
using namespace std;

void NumberList::Init()
{
	count = 0;
	for (int i = 0; i < 10; ++i)
	{
		numbers[i] = 0;
	}
}

bool NumberList::Add(int x)
{
	if (count >= 10)
	{
		return false;
	}
	cin >> x;
	numbers[count++] = x;
	return true;
}

void NumberList::Sort()
{
	for (int i = 0; i < count - 1; ++i)
	{
		for (int j = i + 1; j < count; ++j)
			if (numbers[i] > numbers[j])
			{
				swap(numbers[i], numbers[j]);
			}
	}
}

void NumberList::Print()
{
	cout << '\n';
	for (int i = 0; i < count; ++i)
		cout << numbers[i] << " ";
}

bool NumberList::Insert(int pozitie, int numar)
{
	if (pozitie > 10)
		return false;
	count++;
	for (int i = count - 1; i >= pozitie; i--)
		numbers[i] = numbers[i-1];
	numbers[pozitie - 1] = numar;
	
	return true;
}

void NumberList::Remove(int pozitie)
{
	count--;
	for (int i = pozitie; i < count; i++)
		numbers[i] = numbers[i + 1];
	
}