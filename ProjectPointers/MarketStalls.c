#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

void addStand(float*** matKG, int** sizeArr, int* len, char*** names)
{
	char name[100];
	printf("Enter the name of the stand:\n");
	getchar();
	gets(name);

	*matKG = (float**)realloc(*matKG, sizeof(float*) * ((*len) + 1));
	*sizeArr = (int*)realloc(*sizeArr, sizeof(int) * ((*len) + 1));
	*names = (char**)realloc(*names, sizeof(char*) * ((*len) + 1));

	(*matKG)[*len] = NULL;
	(*sizeArr)[*len] = 0;
	(*names)[*len] = _strdup(name);
	(*len)++;
	printf("Stand successfully added...\n");
}

void addWeight(float** matKG, int* sizeArr, int len, char** names)
{
	int  ind;
	float wheight;
	if (!matKG)
	{
		printf("There are not stand in the market...\n");
		return;
	}

	for (int i = 0; i < len; i++)
	{
		printf("To choose %s ,press %d:\n", names[i], i + 1);
	}
	scanf("%d", &ind);  //ind -1 מיקום הדוכן במערך השמות
	printf("Enter wheight you want to add to %s stand:\n", names[ind - 1]);
	scanf("%f", &wheight);
	sizeArr[ind - 1]++;
	matKG[ind - 1] = (float*)realloc(matKG[ind - 1], sizeof(float) * sizeArr[ind - 1]);
	matKG[ind - 1][sizeArr[ind - 1] - 1] = wheight;
	printf("Weight added successfully...\n");
}

void printSumDay(float** matKG, int* sizeArr, int len, char** names)
{
	float sumStand = 0, sumAll = 0;
	for (int i = 0; i < len; i++)
	{
		printf("stand %s:\n", names[i]);
		sumStand = 0;
		printf("The list of weights:\n");
		for (int j = 0; j < sizeArr[i]; j++)
		{
			printf("%.2f\t", matKG[i][j]);
			sumStand += matKG[i][j];
		}
		printf("\nnumber of sales: %d\n", sizeArr[i]);
		printf("sum all: %.2f\n", sumStand);
		sumAll += sumStand;
	}
	printf("sum all the market: %.2f\n", sumAll);
}


void finish(float*** matKG, int** sizeArr, int len, char*** names)
{
	if (!(*matKG))
	{
		printf("There are not stand in the market...\n");
		return;
	}
	for (int i = 0; i < len; i++)
	{
		free(names[i]);
	}
	printf("we did it!!!!!!!\n");
}


void main()
{
	int* sizeArr = NULL;
	char** names = NULL;
	float** matKG = NULL;
	int len = 0;
	int x;
	printf("To add stand press 1: \n");
	printf("To add weighing in the stand press 2: \n");
	printf("To sum up this day press 3: \n");
	printf("To finish press 4: \n");
	scanf("%d", &x);
	while (x != 4)
	{
	if (x == 1)
		addStand(&matKG, &sizeArr, &len, &names);
	if(x==2)
		addWeight(matKG, sizeArr, len, names);
	if(x==3)
		printSumDay(matKG, sizeArr, len, names);
	 printf("Enter choice:\n");
	 scanf("%d", &x);
	}
	finish(&matKG, &sizeArr, len, &names);

}
