#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
	char s[100], cuv[10][20];
	int n = 0;
	scanf("%[^\n]", s);

	char *p = strtok(s, " ");
	while (p)
	{
		strcpy(cuv[n++], p);
		p = strtok(NULL, " ");
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (strlen(cuv[i]) < strlen(cuv[j]))
			{
				swap(cuv[i], cuv[j]);
			}
			else if (strlen(cuv[i]) == strlen(cuv[j]))
			{
				if (strcmp(cuv[i], cuv[j]) > 0)
				{
					swap(cuv[i], cuv[j]);
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
		printf("%s\n", cuv[i]);

	return 0;
}
