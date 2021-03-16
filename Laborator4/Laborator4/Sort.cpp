#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h";
#include <iostream>
#include <stdarg.h>
#include <cstring>

using namespace std;

//valori random dintr-un interval specific
Sort::Sort(int nrElem, int valMin, int valMax)
{
	
	v = new int[nrElem];
	n = nrElem;
	int dif = valMax - valMin + 1;
	for (int i = 0; i < n; i++)
	{
		v[i] = valMin + rand() % dif;
	}
}

//lista de initializare
/*Sort::Sort(initializer_list<int> list)
{
	for (int x : list) //range for
	{

	}
}*/


//dintr-un vector existent dat ca parametru
Sort::Sort(int *vector, int nrElem)
{
	v = vector;
	n = nrElem;
}
//parametrii variadici
Sort::Sort(int count, ...)
{
	va_list list;
	va_start(list, count);

	v = new int[count];
	n = count;

	for (int arg = 0; arg < count; arg++)
	{
		v[arg] = va_arg(list, int);
	}
	va_end(list);
}
//sir de caractere
Sort::Sort(char* sir)
{
	int cnt = 0;
	n = 0;
	for (int i = 0; sir[i]; i++)
		if (sir[i] == ',')
			n++;
	n++;
	v = new int[n];
    
    char *p = strtok(sir, ",");

	while (p)
	{
		v[cnt++] = atoi(p);
		p = strtok(nullptr, ",");
	}

}
void Sort::Merge(Sort& s)
{
	int i = 0, j = 0, k = 0;
	int c[200];
	
	while (i < this->n && j < s.n)
	{
		if (this->v[i] < s.v[j])
		{
			c[k] = this->v[i];
			k++;
			i++;
		}
		else
		{
			c[k] = s.v[j];
			k++;
			j++;
		}
	}
	if (i <= this->n)
	{
		for (int index = i; index < this->n; index++)
		{
			c[k] = this->v[index];
			k++;
		}
	}
	if (j <= s.n)
	{
		for (int index = j; index < s.n; index++)
		{
			c[k] = s.v[index];
			k++;
		}
	}
	
	for (int i = 0; i < k; i++)
		cout << c[i] << " ";
	cout << endl;
}
void Sort::InsertSort(bool ascendent)
{
	for (int i = 1; i < n; i++)
	{
		int aux = v[i];
		int j = i - 1;
		while (j >= 0 && v[j] > aux)
		{
			v[j + 1] = v[j];
			--j;
		}
		v[j + 1] = aux;
	}

	if (ascendent == false)
	{
		inversare();
	}
}

void Sort::QuickSort(bool ascendent)
{
	quickSortAlg(0, n - 1);
	if (ascendent == false)
	{
		inversare();
	}
}
void Sort::quickSortAlg(int st, int dr)
{
	if (st < dr)
	{
		int index = partitionare(st, dr);

		quickSortAlg(st, index - 1);
		quickSortAlg(index + 1, dr);
	}
}
int Sort::partitionare(int st, int dr)
{
	int aux;
	int pivot = v[dr];
	int index = st - 1;
	for (int i = st; i <= dr - 1; i++)
	{

		if (v[i] < pivot)
		{
			index++;
			aux = v[index];
			v[index] = v[i];
			v[i] = aux;
		}
	}
	aux = v[index + 1];
	v[index + 1] = v[dr];
	v[dr] = aux;

	return index + 1;
}

void Sort::BubbleSort(bool ascendent)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
			if (v[j] > v[j + 1])
			{
				int aux = v[j];
				v[j] = v[j + 1];
				v[j + 1] = aux;
			}
	}

	if (ascendent == false)
	{
		inversare();
	}
}

void Sort::Print()
{
	for (int i = 0; i < n; i++)
	{
		cout << GetElementFromIndex(i) << " ";
		//cout << v[i] << " ";
	}

	cout << "\n";
}

int Sort::GetElementsCount()
{
	return n;
}

int Sort::GetElementFromIndex(int index)
{
	return v[index];
}

void Sort::inversare()
{
	for (int i = 0; i < n / 2; i++)
	{
		int aux = v[i];
		v[i] = v[n - i - 1];
		v[n - i - 1] = aux;
	}
}