#pragma once
#include <iostream>

using namespace std;

template <class T>
class Vector
{
	int lungime;
	int vDim;
	T* v;
	void resize();
	
public:

	Vector() : lungime(0), vDim(1), v(new T[1]) {}
	int GetDim();
	void push(T elem);
	T pop();
	void remove(int index);
	void insert(T elem, int index);
	void sort(bool (*sortFunction)(T& elem1, T& elem2) = nullptr)
	{
		for (int i = 0; i < lungime - 1; i++)
		{
			for (int j = i + 1; j < lungime; j++)
			{
				if (sortFunction == nullptr)
				{
					if (v[i] < v[j])
					{
						swap(v[i], v[j]);
					}
				}
				else
				{
					bool rez = sortFunction(v[i], v[j]);
					if (!rez)
					{
						swap(v[i], v[j]);
					}
				}
			}
		}
	}
	T& get(int index) const;
	void set(T elem, int index);
	int count();
	int firstIndexOf(T& elem, bool (*isEqual)(T& elem1, T& elem2) = nullptr)
	{
		for (int i = 0; i < lungime; i++)
		{
			if (isEqual == nullptr)
			{
				if (elem == v[i])
				{
					return i;
				}
			}
			else
			{
				bool rez = isEqual(v[i], elem);
				if (rez)
				{
					return i;
				}
			}
		}
		return -1;
	}
	void getElements();
	void swapVec(Vector<T>& w);

};

template <class T>
void Vector<T>::resize()
{
	vDim *= 2;
	T* vAux = new T[vDim];

	for (int i = 0; i < lungime; i++)
	{
		vAux[i] = v[i];
	}

	delete[] v;
	v = vAux;
}

template <class T>
int Vector<T>::GetDim()
{
	return vDim;
}

template <class T>
void Vector<T>::push(T elem)
{
	if (vDim <= lungime + 1)
	{
		resize();
	}

	v[lungime++] = elem;
}

template <class T>
T Vector<T>::pop()
{
	if (lungime - 1 >= 0)
	{
		return v[lungime - 1];
	}
}

template <class T>
void Vector<T>::remove(int index)
{
	if (index >= 0 && index <= lungime - 1)
	{

		while (index != lungime)
		{
			v[index] = v[index + 1];
			index++;
		}
		lungime--;
	}
}

template <class T>
void Vector<T>::insert(T elem, int index)
{
	int lg = lungime;
	if (index < 0 || index >= lg)
	{
		return;
	}
	if (lg + 1 >= vDim)
	{
		resize();
	}

	while (lg > index)
	{
		v[lg] = v[lg - 1];
		lg--;
	}

	v[index] = elem;
	lungime++;
}

template <class T>
T& Vector<T>::get(int index) const
{
	if (index >= 0 && index <= lungime - 1)
	{
		return v[index];
	}
}

template <class T>
void Vector<T>::set(T elem, int index)
{
	if (index >= 0 && index <= lungime - 1)
	{
		v[index] = elem;
	}
}

template <class T>
int Vector<T>::count()
{
	return lungime;
}

template <class T>
void Vector<T>::getElements()
{

	for (int i = 0; i < lungime; i++)
	{
		cout << v[i] << " ";
	}
	cout << endl << endl;
}

template <class T>
void Vector<T>::swapVec(Vector<T>& w)
{
	//vDim - capacitate vector

	while (this->vDim < w.lungime)
		this->resize();
	while (this->lungime > w.vDim)
		w.resize();

	if (this->lungime > w.lungime)
	{
		for (int i = 0; i < w.lungime; i++)
			swap(this->v[i], w.v[i]);
		for (int i = w.lungime; i < this->lungime; i++)
		{
			w.v[i] = this->v[i];
		}
		swap(w.lungime, this->lungime);
		
	}
	else if (this->lungime < w.lungime)
	{
		for (int i = 0; i < this->lungime; i++)
			swap(this->v[i], w.v[i]);
		for (int i = this->lungime; i < w.lungime; i++)
		{
			this->v[i] = w.v[i];
		}
		swap(w.lungime, this->lungime);
			
	}
	else
	{
		for (int i = 0; i < this->lungime; i++)
			swap(this->v[i], w.v[i]);
	}
}