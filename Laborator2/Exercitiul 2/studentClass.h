#pragma once

class Student
{
private:
	char name[256];
	float math;
	float english;
	float history;

public:
	void setName();
	char* getName();

	void setMath(float x);
	float getMath();

	void setEnglish(float x);
	float getEnglish();

	void setHistory(float x);
	float getHistory();

	float getAverage();
};