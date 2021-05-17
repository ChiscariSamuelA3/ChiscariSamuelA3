#pragma once
class MyVector
{
	int* vec;
	int capacitate;
	int n;
public:
	bool Add(int elem); // return true if the value was added. As a result, the size of the vector increases with one.
	bool Delete(int index); // returns true if the value from the index was removed. As a result, the size of the vector decreases with one.
	
	MyVector(int);
	~MyVector();

	void Iterate(void(*callback)(int&));
	void Filter(bool (*callback)(int));

	void afisare();

};

