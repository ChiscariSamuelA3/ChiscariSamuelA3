#define _CRT_SECURE_NO_WARNINGS
#include "studentClass.h";
#include "globalFunctions.h";
#include <iostream>

int comparaNume(Student s1, Student s2)
{
	char nume1[256], nume2[256];
	strcpy(nume1, s1.getName());
	strcpy(nume2, s2.getName());

	if (strcmp(nume1, nume2) == 0)
		return 0;
	else if (strcmp(nume1, nume2) > 0)
		return 1;
	else return -1;
}

int comparaMate(Student s1, Student s2)
{
	float nota1, nota2;
	nota1 = s1.getMath();
	nota2 = s2.getMath();

	if (nota1 == nota2)
		return 0;
	else if (nota1 > nota2)
		return 1;
	else return -1;
}

int comparaEngl(Student s1, Student s2)
{
	float nota1, nota2;
	nota1 = s1.getEnglish();
	nota2 = s2.getEnglish();

	if (nota1 == nota2)
		return 0;
	else if (nota1 > nota2)
		return 1;
	else return -1;
}

int comparaIst(Student s1, Student s2)
{
	float nota1, nota2;
	nota1 = s1.getHistory();
	nota2 = s2.getHistory();

	if (nota1 == nota2)
		return 0;
	else if (nota1 > nota2)
		return 1;
	else return -1;
}

int comparaMedie(Student s1, Student s2)
{
	float medie1, medie2;
	medie1 = s1.getAverage();
	medie2 = s2.getAverage();

	if (medie1 == medie2)
		return 0;
	else if (medie1 > medie2)
		return 1;
	else return -1;
}