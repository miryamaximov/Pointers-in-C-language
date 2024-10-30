#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

//הפונקציה מקבלת: מערך דגמי המכוניות, מערך מספר המכוניות לכל דגם, מערך מספרי הרישוי למכוניות לכל דגם
//במשתנים נוספים מקבלת את הדגם ומספר הרישוי של הרכב שרוצים להוסיף
void addCar(char*** models, int** numCarsModel, char**** cars, int* numOfModels, char* model, char* license)
{
	int index = -1;

	for (int i = 0; i < *numOfModels; i++)
		if (strcmp(model, (*models)[i]) == 0)
			index = i;


	if (index == -1) //הדגם לא קיים עדיין
	{
		index = *numOfModels;
		*models = (char**)realloc(*models, sizeof(char*) * ((*numOfModels) + 1));
		(*models)[*numOfModels] = _strdup(model);
		*numCarsModel = (int*)realloc(*numCarsModel, (sizeof(int) * ((*numOfModels) + 1)));
		(*numCarsModel)[*numOfModels] = 0;
		*cars = (char***)realloc(*cars, sizeof(char**) * ((*numOfModels) + 1));
		(*cars)[*numOfModels] = NULL;
		(*numOfModels)++;
		printf("Model successfully added...\n");
	}
	(*cars)[index] = (char**)realloc((*cars)[index], sizeof(char*) * (1 + (*numCarsModel)[index]));
	(*cars)[index][(*numCarsModel)[index]] = _strdup(license);
	(*numCarsModel)[index]++;
	printf("Car successfully added...\n");
}

void rentCar(char*** models, int** numCarsModel, char**** cars, int* numOfModels)
{
	int index = -1;
	char model[50];
	printf("Enter the model you want to rent:\n");
	getchar();
	gets(model);
	for (int i = 0; i < *numOfModels; i++)
		if (strcmp(model, (*models)[i]) == 0)
			index = i;
	if (index == -1)
	{
		printf("We have no car of this model to rent, enter another model:\n");
		getchar();
		gets(model);
	}

	printf("Your car: model - %s, license - %s\n", (*models)[index], (*cars)[index][0]);

	for (int i = 0; i < (*numCarsModel)[index]; i++)
		(*cars)[index][i] = (*cars)[index][i + 1];


	(*numCarsModel)[index]--;


	//טיפול במקרה שזהו הרכב האחרון מדגם זה
	if ((*numCarsModel)[index] == 0)
	{
		(*cars)[index] = NULL;
		(*cars) = (char***)realloc((*cars), sizeof(char**) * (*numOfModels) - 1);
		(*models)[index] = _strdup((*models)[(*numOfModels) - 1]);
		(*models) = (char**)realloc((*models), sizeof(char*) * (*numOfModels) - 1);
		(*numCarsModel)[index] = (*numCarsModel)[(*numOfModels) - 1];
		(*numCarsModel) = (int*)realloc((*numCarsModel), sizeof(int) * (*numOfModels) - 1);
		(*numOfModels)--;
	}
	printf("Car successfully rented...\n");
}

void main()
{
	char** models = NULL;
	int* numCarsModel = NULL;
	char*** cars = NULL;
	int numOfModels = 0;
	char model[50], license[50];
	int choice;
	printf("Enter 1 to add a car, 2 to rent a car, 0 to finish.\n");
	scanf("%d", &choice);
	while (choice != 0)
	{
		if (choice == 1)
		{
			printf("Enter the model and the license id:\n");
			getchar();
			gets(model);
			gets(license);
			addCar(&models, &numCarsModel, &cars, &numOfModels, model, license);
		}
		if (choice == 2)
		{
			if (numOfModels == 0)
				printf("Sorry, we have no cars...\n");
			else
			rentCar(&models, &numCarsModel, &cars, &numOfModels);
		}

		printf("Enter 1 to add a car, 2 to rent a car, 0 to finish.\n");
		scanf("%d", &choice);
	}


	//free 

	free(numCarsModel);
	free(models);
	free(cars);

}