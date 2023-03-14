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


// ----------------------------------------------------------------------------
// defines/macros
#define SUGG_SERV 64
#define MAX_FOOD 3
#define LBS_TO_KG 2.20462


// ----------------------------------------------------------------------------
// structures
typedef struct
{
    int skuNum;
    double prodPrice;
    int calPerSuggSer;
    double weight;
}CatFoodInfo;

typedef struct {
    //Same as CatFoodInfo
    int sku;
    double price;
    int calPerServ;
    double pounds;
    //p2 only
    double kg;
    int grams;
    double totalServ;
    double costPerServ;
    double costPerCal;
}ReportData;

// ----------------------------------------------------------------------------
// function prototypes

//Helper Prototype
void displayError();

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int*);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double*);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int);

// 4. Get user input for the details of cat food product
CatFoodInfo getCatFoodInfo(const int);

// 5. Display the formatted table header
void displayCatFoodHeader(void);
// 6. Display a formatted record of cat food data
void displayCatFoodData(const int, const double*, const double*, const int);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double*, double*);

// 9. convert lbs: g
int convertLbsG(const double*, int*);

// 10. convert lbs: kg / g
void convertLbs(const double*, double*, int*);

// 11. calculate: servings based on gPerServ

double calculateServings(const int, const int, double*);
// 12. calculate: cost per serving

double calculateCostPerServing(const double*, const double*, double*);


// 13. calculate: cost per calorie
double calculateCostPerCal(const double *productPrice, const double*, double*);


// 14. Derive a reporting detail record based on the cat food product data

ReportData calculateReportData(const CatFoodInfo);
// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table

void displayReportData(const ReportData, const int);

// 17. Display the findings (cheapest)

void displayFinalAnalysis();
// ----------------------------------------------------------------------------

// 7. Logic entry point 

void start();
