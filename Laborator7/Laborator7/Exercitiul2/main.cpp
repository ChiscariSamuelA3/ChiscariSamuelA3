#include "Vector.h"
#include <iostream>

using namespace std;
bool sortFunction(int &a, int &b)
{
	return a < b;
}
bool isEqual(int &a, int &b)
{
	return a == b;
}
int main()
{
	Vector<int> v;
	
	for (int i = 0; i < 5; i++)
	{
		int nr = rand() % 100;
		cout << v.GetDim() << endl;
		v.push(nr);
	}
	
	cout << "push: Au fost adaugate " << v.count() << " elemente in vector\n";
	v.getElements();
	cout << "pop: Ultimul element este: " << v.pop() << endl << endl;

	int poz = 3;
	v.remove(poz);
	cout << "remove: Elementul de pe pozitia " << poz << " a fost sters\n";
	v.getElements();
	
	v.insert(11, poz);
	cout << "insert: Element nou inserat pe pozitia " << poz << endl;
	v.getElements();

	//v.sort();
	v.sort(&sortFunction);
	cout << "sort: Vectorul sortat este:\n";
	v.getElements();

	
	cout << "get: Elementul pentru care s-a returnat o referinta constanta: ";
	cout << v.get(poz) << endl << endl;

	v.set(34, poz);
	cout << "set: Element inlocuit pe pozitia " << poz << endl;
	v.getElements();

	cout << "count: In vector sunt " << v.count() << " elemente.\n\n";

	int *nr = new int[3];
	nr[0] = 41;
	nr[1] = 34;
	cout << "firstIndexOf: elementul 34 pe pozitia: " << v.firstIndexOf(*(nr + 1)) << endl;
	cout << "firstIndexOf: elementul 41 pe pozitia: " << v.firstIndexOf(*nr, &isEqual) << endl << endl;

	Vector<int> w;
	for (int i = 0; i < 10; i++)
	{
		int nr = rand() % 50;
		//cout << w.GetDim() << endl;
		w.push(nr);
	}

	cout << "Primul vector v: \n";
	v.getElements();
	cout << "Al doilea vector w: \n";
	w.getElements();

	cout << "Interschimbarea vecotrilor: \n";
	v.swapVec(w);
	
	cout << "Primul vector v: \n";
	v.getElements();

	cout << "Al doilea vector w: \n";
	w.getElements();

	return 0;
}