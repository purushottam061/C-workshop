/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
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

// User-Defined Libraries
#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

//Error Functions
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
	printf("SKU\t\t:");
	temp.skuNum=getIntPositive(NULL);
	printf("PRICE\t\t:$");
	getDoublePositive(&temp.prodPrice);
	printf("WEIGHT (LBS)\t:");
	temp.weight=getDoublePositive(NULL);
	printf("CALORIES/SERV.\t:");
	getIntPositive(&temp.calPerSuggSer);
	return temp;
}


// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("\nSKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int skuNum, const double* price, const double *weight, const int calPerServ)
{
	printf("%07d %10.2lf %10.1lf %8d\n",skuNum,*price,*weight,calPerServ);
}


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* lbsPtr, double* kgPtr)
{
    if(kgPtr!=NULL)
    {
        *kgPtr=*lbsPtr/LBS_TO_KG;
    }
    return *lbsPtr/LBS_TO_KG;
}


// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* lbsPtr, int* gPtr)
{
    if(gPtr!=NULL)
    {
        *gPtr=(*lbsPtr/LBS_TO_KG)*1000;
    }
    return (*lbsPtr/LBS_TO_KG)*1000;
}


// 10. convert lbs: kg and g
void convertLbs(const double* lbs, double* kgPtr, int* gPtr)
{
    *kgPtr=convertLbsKg(lbs,NULL);
    convertLbsG(lbs,gPtr);
}


// 11. calculate: servings based on gPerServ
double calculateServings(const int gramServSize, const int totGram, double* resultNOS)
{
    if(resultNOS!=NULL)
    {
        *resultNOS=totGram/gramServSize;
    }
    return totGram/(double)gramServSize;
}


// 12. calculate: cost per serving
double calculateCostPerServing(const double* prodPrice, const double* numOfServ, double* resultCPS)
{
    if(resultCPS!=NULL)
    {
        *resultCPS=(*prodPrice/(*numOfServ));
    }
    return (*prodPrice/(*numOfServ));
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* prodPrice, const double* totNumOfCal, double* resultCPC)
{
    if(resultCPC!=NULL)
    {
        *resultCPC=(*prodPrice/(*totNumOfCal));
    }
    return (*prodPrice/(*totNumOfCal));
}

// 14. Derive a reporting detail record based on the cat food product data
ReportData calculateReportData(const CatFoodInfo cf)
{
    ReportData temp;
    double tempTotCal=0;
    //CatFoodInfo Struct copy to ReportData Struct
    temp.sku=cf.skuNum;
    temp.price=cf.prodPrice;
    temp.pounds=cf.weight;
    temp.calPerServ=cf.calPerSuggSer;

    //calcualted values
    temp.kg=convertLbsKg(&temp.pounds,NULL);
    convertLbsG(&temp.pounds,&temp.grams);
    temp.totalServ=calculateServings(SUGG_SERV,temp.grams,NULL);
    calculateCostPerServing(&temp.price,&temp.totalServ,&temp.costPerServ);
    tempTotCal=temp.calPerServ*temp.totalServ;
    temp.costPerCal=calculateCostPerCal(&temp.price,&tempTotCal,NULL);

    return temp;
}


// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("\nAnalysis Report (Note: Serving = %dg)\n", SUGG_SERV);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const ReportData rd, const int isCheap)
{
    printf("\n%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf",rd.sku,rd.price,rd.pounds,rd.kg,rd.grams,rd.calPerServ,rd.totalServ,rd.costPerServ,rd.costPerCal);
    if(isCheap>0)
    {
        printf(" ***");
    }
}


// 17. Display the findings (cheapest)
void displayFinalAnalysis(const CatFoodInfo cf)
{
    printf("\n\nFinal Analysis\n");
    printf("--------------\n");
    printf("Based on the comparison data, the PURRR-fect economical option is:\n");
    printf("SKU:%07d Price: $%.2lf\n",cf.skuNum,cf.prodPrice);
    printf("\nHappy Shopping!");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
    CatFoodInfo catF[MAX_FOOD];

    ReportData reportD[MAX_FOOD];
    openingMessage(MAX_FOOD);
    int cheapProdIndex=0;
    //letting any highest arbiratory number for cost per serving for first//
    int cheapCostPerServ=10000000;

    for(int i=0;i<MAX_FOOD;i++)
    {
        catF[i]=getCatFoodInfo(i+1);
        reportD[i]=calculateReportData(catF[i]);
        if(cheapCostPerServ>reportD[i].costPerServ)
        {
            cheapCostPerServ=reportD[i].costPerServ;
            cheapProdIndex=i;
        }
    }

    displayCatFoodHeader();
    for(int i=0;i<MAX_FOOD;i++)
    {
        displayCatFoodData(catF[i].skuNum,&catF[i].prodPrice,&catF[i].weight,catF[i].calPerSuggSer);
    }

    displayReportHeader();
    for(int i=0;i<MAX_FOOD;i++)
    {
        //Is it cheap//
        if(i==cheapProdIndex)
        {
            //Here 10 is just arbiratory  number to denote it is the cheapest among all, any positive number greater than zero will work fine//
            displayReportData(reportD[i],10);
        }
        else
        {
            displayReportData(reportD[i],0);
        }
    }
    
    displayFinalAnalysis(catF[cheapProdIndex]);

}
