/*
/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)
Full Name  :
Student ID#:
Email      :
Section    :

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////
*/
#include <stdio.h>
#define MAX 3
// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
    int id;
    double price;
    int weight;
    double calserv;
};

// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

int getIntPositive (int *intValue);
// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive (double *doubleVal);
// 3. Opening Message (include the number of products that need entering)
void openingMessage (int );
// 4. Get user input for the details of cat food product
void getCatFoodInfo(int );
// 5. Display the formatted table header
void displayCatFoodHeader();
// 6. Display a formatted record of cat food data
void displayCatFoodData(int *id, double *price ,double *weight, int *calserv);
// 7. Logic entry point
void start (void);