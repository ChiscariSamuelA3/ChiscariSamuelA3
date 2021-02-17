#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

int atoiImp(char *text)
{
	int nr = 0;
	for (int i = 0; text[i] != '\n' && text[i]; i++)
		nr = nr * 10 + text[i] - '0';
	return nr;
}
int main()
{
	FILE *fis;
	fis = fopen("in.txt", "r");

	if (fis == NULL)
	{
		printf("Eroare la deschidere!");
		exit(1);
	}

	char line[100];
	int sum = 0;
	bool neg = false;

	while (fgets(line, sizeof(line), fis))
	{
		if (line[0] == '-')
		{
			neg = true;
			strcpy(line, line + 1);
		}
		if (neg == true)
		{
			sum -= atoiImp(line);
			neg = false;
		}
		else sum += atoiImp(line);
	}

	printf("%d", sum);

	fclose(fis);

	return 0;
}
