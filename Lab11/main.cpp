#include <iostream>
#include <vector>
#include "MyVector.h"

using namespace std;


void sortare(vector<string>& vect, bool(*compara)(string x, string y))
{
	for (int i = 0; i < vect.size() - 1; i++)
	{
		for (int j = 0; j < vect.size() - 1 - i; j++)
		{
			if (compara(vect[j], vect[j + 1]))
			{
				swap(vect[j], vect[j + 1]);
			}
		}
	}

}




int main()
{
	
	//1
	/*
	vector<string> vec;

	vec.push_back("cc");
	vec.push_back("bbbb");
	vec.push_back("aaaa");
	vec.push_back("baaaaa");
	
	auto comp = [](string x, string y)
	{
		if (x.length() != y.length())//daca au lungime diferita, sortam in functie de lungime
		{
			return x.length() > y.length();
		}
		else//daca au lungime egala, sortam lexicografic
		{
			return x > y;
		}
	};

	
	sortare(vec, comp);

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << endl;
	}
	*/
	
	//3

	MyVector v(15);
	for (int i = 0; i < 10; i++)
	{
		int nr = rand() % 100;
		v.Add(nr);
	}
	cout << "Vector initial:\n ";
	v.afisare();

	auto modifica1 = [](int& x)
	{
		x += 10000;
	};

	cout << "Iterare:\n";
	v.Iterate(modifica1);
	v.afisare();

	auto modifica2 = [](int x)
	{
		return (x % 2 == 1);
	};

	cout << "Filtrare:\n";
	v.Filter(modifica2);
	v.afisare();

	


	return 0;
}

