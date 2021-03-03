#define _CRT_SECURE_NO_WARNINGS
#include "Math.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>

using namespace std;

int Math::Add(int x, int y) {
	return x + y;
}
int Math::Add(int x, int y, int z) {
	return x + y + z;
}
int Math::Add(double x, double y) {
	return x + y;
}
int Math::Add(double x, double y, double z) {

	return x + y + z;
}
int Math::Mul(int x, int y) {
	return x * y;

}
int Math::Mul(int x, int y, int z) {
	return x * y * z;

}

int Math::Mul(double x, double y) {
	return x * y;

}
int Math::Mul(double x, double y, double z) {
	return x * y * z;
}
int Math::Add(int count, ...) {

	va_list list;//lista parametrilor
	va_start(list, count);//initializam lista
	int sum = 0;
	for (int arg = 0; arg < count; arg++) {
		sum += va_arg(list, int);

	}
	va_end(list);//deinitializeaza lista

	return sum;
}

char* Math::Add(const char* s1, const char* s2) {

	if (s1 == nullptr || s2 == nullptr)
		return nullptr;

	char* s = new char[100];
	strcpy(s, "");

	if (strlen(s1) > strlen(s2))//avem nevoie sa "aliniem" caracter cu caracter
		swap(s1, s2);

	int l1 = strlen(s1), l2 = strlen(s2);
	int dif = l2 - l1;//adunare directa pe o lungime egala, apoi verificam transportul ramas
	int r = 0;//transportul sumei
	int sum = 0;

	for (int i = l1 - 1; i >= 0; i--)
	{
		int c1 = s1[i] - '0';
		int c2 = s2[i + dif] - '0';
		sum = c1 + c2 + r;
		r = sum / 10;

		int sumCif = sum % 10;
		char* sumCh = new char[5];
		sprintf(sumCh, "%d", sumCif);
		strcat(s, sumCh);
		delete[] sumCh;
	}
	for (int i = dif - 1; i >= 0; i--)
	{
		sum = r + (s2[i] - '0');
		r = sum / 10;
		
		int sumCif = sum % 10;
		char* sumCh = new char[5];
		sprintf(sumCh, "%d", sumCif);
		strcat(s, sumCh);
		delete[] sumCh;
	}
	if (r != 0)
	{
		char* rCh = new char[5];
		sprintf(rCh, "%d", r);
		strcat(s, rCh);
		delete[] rCh;
	}

	int n = strlen(s);
	for (int i = 0; i < n / 2; i++)
		swap(s[i], s[n - i - 1]);

	return s;
}

char* Math::Mul(const char* x, int y)
{
	char* s = new char[100];

	int l = strlen(x);
	int p = 0;
	for (int i = l - 1; i >= 0; i--, p /= 10)
	{
		
		int c = x[i] - '0';
		p += c * y;
		char* cif = new char[5];
		int u = p % 10;
		sprintf(cif, "%d", u);
		s[i] = cif[0];
		delete[] cif;
		
		
	}
	
	for (int i = 0; i < l / 2; i++)
		swap(s[i], s[l - i - 1]);
	while (p)
	{
		char* cif = new char[5];
		int u = p % 10;
		sprintf(cif, "%d", u);

		s[l++] = cif[0];
		p /= 10;
	}
	s[l] = '\0';
	for (int i = 0; i < l / 2; i++)
		swap(s[i], s[l - i - 1]);

	return s;
}
