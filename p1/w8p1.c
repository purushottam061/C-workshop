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
#include <stdio.h>

// User Libraries
#include "w8p1.h"

//helper functioin
void displayError()
{
	printf("ERROR: Enter a positive value: ");
}

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

int getIntPositive(int* intPosPoi)
{
	int temp;
	while(1)
	{
		scanf("%d",&temp);
		if(temp<=0)
		{
			displayError();
		} 
		else
		{
			if(intPosPoi!=NULL)
			{
				*intPosPoi=temp;
			}
			return temp;
		}
	}
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* douPosPoi)
{
	double temp;
	while(1)
	{
		scanf("%lf",&temp);
		if(temp<=0)
		{
			displayError();
		} 
		else
		{
			if(douPosPoi!=NULL)
			{
				*douPosPoi=temp;
			}
			return temp;
		}
	}
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int fNum)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n");
	printf("\nEnter the details for %d dry food bags of product data for analysis.\n",fNum);
	printf("NOTE: A 'serving' is %dg\n",SUGG_SERV);
}

// 4. Get user input for the details of cat food product

CatFoodInfo getCatFoodInfo(const int number)
{
	CatFoodInfo temp;
	printf("\nCat Food Product #%d\n",number);
	printf("--------------------\n");
	printf("SKU           :");
	temp.skuNum=getIntPositive(NULL);
	printf("PRICE         :$");
	getDoublePositive(&temp.prodPrice);
	printf("WEIGHT (LBS)  :");
	temp.weight=getDoublePositive(NULL);
	printf("CALORIES/SERV.:");
	getIntPositive(&temp.calPerSuggSer);
	return temp;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int skuNum, const double* price, const double *weight, const int calPerServ)
{
	printf("%07d %10.2lf %10.1lf %8d\n",skuNum,*price,*weight,calPerServ);
}

// 7. Logic entry point
void start()
{
	CatFoodInfo cFood[MAX_FOOD];
	openingMessage(MAX_FOOD);

	for(int i=0;i<MAX_FOOD;i++)
	{
		cFood[i]=getCatFoodInfo(i+1);
	}

	displayCatFoodHeader();
	for(int i=0;i<MAX_FOOD;i++)
	{
		displayCatFoodData(cFood[i].skuNum,&cFood[i].prodPrice,&cFood[i].weight,cFood[i].calPerSuggSer);
	}
}
