#define _CRT_SECURE_NO_WARNINGS
#include "studentClass.h";
#include "globalFunctions.h";
#include <iostream>

using namespace std;

int main()
{
	Student s1, s2;
	float x;
	cout << "Numele primului student: ";
	s1.setName();
	cout << "Numele celui de-al doilea student: ";
	s2.setName();
	cout << endl;

	s1.setMath(8.5);
	s1.setHistory(7.8);
	s1.setEnglish(9.3);
	cout << "Notele primului student: \n";
	cout << "-Matematica: " << s1.getMath() << "\n";
	cout << "-Istorie: " << s1.getHistory() << "\n";
	cout << "-Engleza: " << s1.getEnglish() << "\n";

	s2.setMath(7.7);
	s2.setHistory(8.4);
	s2.setEnglish(7.9);
	cout << "Notele celui de-al doilea student: " << endl;
	cout << "-Matematica: " << s2.getMath() << "\n";
	cout << "-Istorie: " << s2.getHistory() << "\n";
	cout << "-Engleza: " << s2.getEnglish() << "\n";
	cout << endl;

	char numeS1[256], numeS2[256];
	float medieS1, medieS2;

	strcpy(numeS1, s1.getName());
	strcpy(numeS2, s2.getName());

	medieS1 = s1.getAverage();
	medieS2 = s2.getAverage();

	cout << "Media studentului " << numeS1 << " este: " << medieS1 << "\n";
	cout << "Media studentului " << numeS2 << " este: " << medieS2 << "\n";

	cout << "Numele studentilor in ordine alfabetica este:\n";
	if (comparaNume(s1, s2) == -1)
		cout << numeS1 << ", " << numeS2 << "\n";
	else cout << numeS2 << ", " << numeS1 << "\n";

	if (comparaMate(s1, s2) == 1)
		cout << numeS1 << " are nota mai mare la matematica\n";
	else if(comparaMate(s1, s2) == -1)
		cout << numeS2 << " are nota mai mare la matematica\n";
	else cout << "Studentii au notele egale la matematica\n";

	if (comparaEngl(s1, s2) == 1)
		cout << numeS1 << " are nota mai mare la engleza\n";
	else if (comparaEngl(s1, s2) == -1)
		cout << numeS2 << " are nota mai mare la engleza\n";
	else cout << "Studentii au notele egale la engleza\n";

	if (comparaIst(s1, s2) == 1)
		cout << numeS1 << " are nota mai mare la istorie\n";
	else if (comparaIst(s1, s2) == -1)
		cout << numeS2 << " are nota mai mare la istorie\n";
	else cout << "Studentii au notele egale la istorie\n";

	if (comparaMedie(s1, s2) == 1)
		cout << numeS1 << " are media mai mare\n";
	else if (comparaMedie(s1, s2) == -1)
		cout << numeS2 << " are media mai mare\n";
	else cout << "Studentii au mediile egale.\n";

}