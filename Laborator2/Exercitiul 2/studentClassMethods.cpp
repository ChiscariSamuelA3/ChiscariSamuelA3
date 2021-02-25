#define _CRT_SECURE_NO_WARNINGS
#include "studentClass.h";
#include <iostream>

using namespace std;

void Student::setName()
{
	char text[256];
	cin.getline(text, 256);
	strcpy(name, text);
}

char* Student::getName()
{
	return name;
}

void Student::setMath(float x)
{
	math = x;
}

float Student::getMath()
{
	return math;
}

void Student::setEnglish(float x)
{
	english = x;
}

float Student::getEnglish()
{
	return english;
}

void Student::setHistory(float x)
{
	history = x;
}

float Student::getHistory()
{
	return history;
}

float Student::getAverage()
{
	return (math + english + history) / 3.;
}

