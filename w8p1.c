/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #8 (P1)
Full Name  :
Student ID#:
Email      :
Section    :

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#define MAX 3
#include <stdio.h>

// User Libraries

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *intValue)
{
	int n;
	while (*intValue <= 0)
	{
		if (*intValue <= 0)
		{
			printf("ERROR: Enter a positive value: ");
			scanf("%d", &n);
			intValue = &n;
		}
	}
	return *intValue;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *doubleVal)
{
	double n;
	while (*doubleVal <=0)
	{
		if (*doubleVal <=0)
		{
			printf("ERROR: Enter a positive value: ");
			scanf("%lf", &n);
			doubleVal = &n;
		}
	}
	return *doubleVal;
}
// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int n)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\nNOTE: A 'serving' is 64g\n", n);
	// getCatFoodInfo(n);
}
// 4. Get user input for the details of cat food product
void getCatFoodInfo(int n)
{
	int i;
	int posN[3], intVal;
	double posD[3], doVal;
	int posN2[3];
	double posD2[3];
	for (i = 0; i<n; i++)
	{
		printf("\nCat Food Product #%d\n", i + 1);
		printf("--------------------\n");
		printf("\nSKU           :");
		scanf("%d", &intVal);
		posN[i] = getIntPositive(&intVal);
		printf("\nPRICE         :$");
		scanf("%lf", &doVal);
		posD[i] = getDoublePositive(&doVal);	
		printf("\nWEIGHT (LBS)  :");
		scanf("%lf", &doVal);
		posD2[i] = getDoublePositive(&doVal);
		printf("\nCALORIES/SERV.:");
		scanf("%d", &intVal);
		posN2[i] = getIntPositive(&intVal);
		// printf("%d %lf\n", posN[i], posD[i]);
		printf("\n");
	}
	displayCatFoodHeader();
	displayCatFoodData(posN,posD,posD2, posN2);
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data

void displayCatFoodData(int *id, double *price ,double *weight, int *calserv)
{
	int i;
	for (i = 0; i < 3; i++)
		printf("%07d %10.2lf %10.1lf %8d\n", id[i], price[i], weight[i], calserv[i]);
}
// 7. Logic entry point

int main(){
	int constVal = 3;
	int CatFoodInfo[MAX];
	openingMessage(constVal);
	int i;
	for(i=1;i<=3;i++){
			getCatFoodInfo(i);	
	}
}