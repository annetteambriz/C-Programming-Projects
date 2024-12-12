#include <ctype.h>
#include <stdio.h>
#include <string.h>

/*********************************************************************
*
* Midterm
*
* Name: Annette Ambriz
*
* Class: C Programming Fall 2024
*
* Date: 10/27/2024
*
* Description: This file contains answers to the midterm
*
**********************************************************************/

// Question 1:

// **************************************************
// Function: calcAreaOfTriangle
//
// Description: Calculates the area of a triangle
//
//
// Parameters:  base - base of the triangle
//              height - height of the triangle
//
// Returns:     area - area of triangle
//
// ***************************************************
float calcAreaOfTriangle(float base, float height)
{
    float area; // area of the triangle
    // calculate area
    area = 0.5 * base * height;
    return area;
} //calcAreaOfTriangle

// **************************************************
// Function: calcAreaOfEllipse
//
// Description: Calculates the area of an ellipse
//
//
// Parameters:  a - a is the length of the Semi-major Axis
//              b - b is the length of the Semi-minor Axis
//
// Returns:     area - area of ellipse
//
// ***************************************************
float calcAreaOfEllipse(float a, float b)
{
    const float PI = 3.14159265358979323846;
    float area; // area of the ellipse
    // calculate area
    area = PI * a * b;
    return area;
} //calcAreaOfEllipse

// **************************************************
// Function: calcAreaOfSector
//
// Description: Calculates the area of a sector
//
//
// Parameters:  r - radius
//              a - angle in radians
//
// Returns:     area - area of sector
//
// ***************************************************
float calcAreaOfSector(float r, float a)
{
    float area; // area of the sector
    // calculate area
    area = 0.5 * (r * r) * a;
    return area;
} //calcAreaOSector

// **************************************************
// Function: calcAreaOfParallelogram
//
// Description: Calculates the area of a parallelogram
//
//
// Parameters:  b - base
//              h - vertical height
//
// Returns:     area - area of parallelogram
//
// ***************************************************
float calcAreaOfParallelogram(float b, float h)
{
    float area; // area of the parallelogram
    // calculate area
    area = b * h;
    return area;
} //calcAreaOfParallelogram

// **************************************************
// Function: calcAreaOfTrapezoid
//
// Description: Calculates the area of a trapezoid
//
//
// Parameters:  a - altitude
//              b - base
//              h - vertical height
//
// Returns:     area - area of trapezoid
//
// ***************************************************
float calcAreaOfTrapezoid(float a, float b, float h)
{
    float area; // area of the trapezoid
    // calculate area
    area = 0.5 * (a + b) * h;
    return area;
} //calcAreaOfTrapezoid

// **************************************************
// Function: calcAreaOfRectangle
//
// Description: Calculates the area of a rectangle
//
//
// Parameters:  w - width
//              h - height
//
// Returns:     area - area of rectangle
//
// ***************************************************
float calcAreaOfRectangle(float w, float h)
{
    float area; // area of the rectangle
    // calculate area
    area = w * h;
    return area;
} //calcAreaOfRectangle

// Question 2:

// **************************************************
// Function: frequency
//
// Description: Calculates the number of times an item x appears among
//              the first n elements of an Array
//              and returns that count as the frequency of x in theArray
//
//
// Parameters:  theArray - array to be searched for x's frequency
//              n - limit to check within the n number of elements in theArray
//              x - item to check it's frequency in theArray
//
// Returns:     frequency - the frequency of x in theArray
//
// ***************************************************
int frequency (int theArray[], int n, int x) {
    int frequency = 0; // variable to track the frequency count

    // loop through nth elements in theArray
    for (int i = 0; i < n; i++) {
        if (theArray[i] == x) {
            frequency += 1;
        }
    } // for
    return frequency;
} //frequency


// Question 3:

// **************************************************
// Function: checkLicenseYear
//
// Description: A helper function to calculate whether a two digit year integer
//              is a valid two digit year for an irish license plate
//
//
// Parameters:  year - two digit year
//
// Returns:     int - returns a True value (1) if the half year is valid,
//                    otherwise a False value (0)
//
// ***************************************************

int isValidLicenseYear(int year) {
    const int firstYear = 13;
    const int currentYear = 24;

    if (year >= firstYear && year <= currentYear)
        return 1;
    return 0;
}

// **************************************************
// Function: isValidLicenseCounty
//
// Description: A helper function to check whether a character represents
//              a valid Irish County
//
//
// Parameters:  county - A character value that represents the Irish County
//                       where the car was registered
//
// Returns:     int - returns a True value (1) if the county character represents
//              a valid Irish County, otherwise a False value (0)
//
// ***************************************************

int isValidLicenseCounty(char county) {
    // convert county char to upper case
    county = toupper(county);
    // check for valid country codes
    switch (county) {
        case 'C':
            break;
        case 'D':
            break;
        case 'G':
            break;
        case 'L':
            break;
        case 'T':
            break;
        case 'W':
            break;
        default:
            return 0;
    }
    return 1;
}


// ********************************************************************************************************
// Function: irishLicensePlateValidator
//
// Description: Validates if given parameters create a valid Irish Licence Plate
//              Since 2013, a valid Irish License plate MUST consist of all four main items
//              and the rules below:
//
//              1. Two digit year - 2013 would be 13, 2014 would be 14, through 24 for 2024. Any other year is invalid.
//              2. Half Year - A '1' indicates the car was sold between Jan-Jun, while a '2' between July-Dec
//              3. County - A character value that represents the Irish County where the car was registered.
//                          Accept 'C' or 'c' for "Cork", 'D' or 'd' for "Dublin", 'G' or 'g' for "Galway", 'L' or
//                          'l' for "Limerick", 'T' or 't' for "Tiperary", and 'W' or 'w' for "Waterford".
//              4. SSSSSS – A one to six-digit sequence number, starting with the first vehicle registered in
//                          the county/city that year/period. Cannot be prefixed with any zero values.
//
//
// Parameters:
//              year - integer representing a year
//              halfYear - integer representing the half of the year the car was sold
//              county - a character representing the Irish county where the car is registered
//              sequence - a one to six-digit sequence number
//
// Returns:     isValid -  returns a True value (1) if the license plate is valid,
//                         otherwise a False value (0)
//
// *********************************************************************************************************

int irishLicensePlateValidator (int year, int halfYear, char county, int sequence ) {
    // conditional statement that represents a valid half year
    const int isValidHalfYear = halfYear == 1 || halfYear == 2;

    // conditional statement that represents a valid license sequence
    const int isValidSequence = sequence > 0 && sequence <= 999999;

    // check conditions for a valid irish license plate
    if (isValidLicenseYear(year) && isValidHalfYear && isValidSequence && isValidLicenseCounty(county))
        return 1;
    return 0;

} //irishLicensePlateValidator


// Question 4:

/*
* Answer:
*   int min = (value1 < value2 ? value1 : value2) < (value3 < value4 ? value3 : value4) ? (value1 < value2 ? value1 : value2) : (value3 < value4 ? value3 : value4);
*/

// **************************************************
// Function: findMin
//
// Description: A function used to test conditional expression operator above
//
//
// Parameters:  num1, num2, num3, num4 - arbitrary integers
//
// Returns:     int - returns minimum value of given nums
//
// ***************************************************

int findMin(int num1, int num2, int num3, int num4) {
    const int value1 = num1;
    const int value2 = num2;
    const int value3 = num3;
    const int value4 = num4;

    int min =
    (value1 < value2 ? value1 : value2) < (value3 < value4 ? value3 : value4) ?
            (value1 < value2 ? value1 : value2) :
                    (value3 < value4 ? value3 : value4);

    return min;
} // findMin

// Question 5:

// **************************************************
// Function: getLetterGrade
//
// Description: A function to calculate the letter grade given
//              a test score
//
//
// Parameters:  testScore - integer value representing a test score
//
// Returns:     char - letter grade for that test score. Returns 'I' for
//                      an invalid test score value
//
// ***************************************************

char getLetterGrade(int testScore) {
    // local variable to store letter grade
    char letterGrade;

    // check testScore against letter grade score ranges
    // invalid test score
    if (testScore < 0 || testScore > 100)
        letterGrade = 'I';
    // test scores 90-100
    else if (testScore >= 90)
    //(testScore <= 100 && testScore >= 90)
        letterGrade = 'A';
    // test scores 80-89
    else if (testScore >= 80)
        letterGrade = 'B';
    // test scores 70-79
    else if (testScore >= 70)
        letterGrade = 'C';
    // test scores 60-69
    else if (testScore >= 60)
        letterGrade = 'D';
    // test scores 0-59
    else
        letterGrade = 'F';

    return letterGrade;
} // getLetterGrade

// Question 6:

// Define a structure to hold county totals
struct countyTotals {
    int totalCorkCodes;
    int totalDublinCodes;
    int totalGalwayCodes;
    int totalLimerickCodes;
    int totalTiperaryCodes;
    int totalWaterfordCodes;
    int totalInvalidCountyCodes;
};

// **************************************************
// Function: getCountyTotals
//
// Description: A function to calculate the total of each valid and invalid Irish county codes
//              from an array of county codes.
//
//
// Parameters:  countyCodes - an array of Irish county codes
//              size - integer value representing the number of county codes in countyCodes array
//
// Returns:     struct - returns a countyTotals struct
//
// ***************************************************

struct countyTotals getCountyTotals(int size, char countyCodes[]) {
    // create local countyTotals struct to store values of county totals
    struct countyTotals totals = {};
    // iterate through all elements in countyCodes array
    for (int i = 0; i < size; i++) {
        // check that each county code is a valid county code and update the struct field for that code
        // else update the number of invalid county codes
        char currentCountyCode = toupper(countyCodes[i]);
        switch (currentCountyCode) {
            case 'C':
                totals.totalCorkCodes += 1;
                break;
            case 'D':
                totals.totalDublinCodes += 1;
                break;
            case 'G':
                totals.totalGalwayCodes += 1;
                break;
            case 'L':
                totals.totalLimerickCodes += 1;
                break;
            case 'T':
                totals.totalTiperaryCodes += 1;
                break;
            case 'W':
                totals.totalWaterfordCodes += 1;
                break;
            default:
                totals.totalInvalidCountyCodes += 1;
        } // switch
    } // for

    // print structure contents to confirm correct values
    printf("Contents of the countyTotals structure are:\n"
           "totalCorkCodes: %i\n"
           "totalDublinCodes: %i\n"
           "totalGalwayCodes: %i\n"
           "totalLimerickCodes: %i\n"
           "totalTiperaryCodes: %i\n"
           "totalWaterfordCodes: %i\n"
           "totalInvalidCountyCodes: %i\n",
           totals.totalCorkCodes,
           totals.totalDublinCodes,
           totals.totalGalwayCodes,
           totals.totalLimerickCodes,
           totals.totalTiperaryCodes,
           totals.totalWaterfordCodes,
           totals.totalInvalidCountyCodes);

    return totals;
} // getCountyTotals

//Question: 7
// **************************************************
// Function: toCelsius
//
// Description: A function to calculate Celsius from Fahrenheit
//
//
// Parameters:  fahrenheit - a float representing Fahrenheit
//
//
// Returns:     float - returns a float representing Celsius
//
// ***************************************************

float toCelsius(float fahrenheit) {
    return (fahrenheit - 32.00) * (5.0 / 9.0);
}

// **************************************************
// Function: toFahrenheit
//
// Description: A function to calculate Fahrenheit from Celsius
//
//
// Parameters:  celsius - a float representing Celsius
//
// Returns:     float - returns a float representing Fahrenheit
//
// ***************************************************

float toFahrenheit(float celsius) {
    return (celsius * (9 / 5)) + 32;
}

// **************************************************
// Function: printCelsiusAndFahrenheit
//
// Description: A function to prints charts showing the Fahrenheit equivalents
//              of all Celsius temperatures from 0 to 100 degrees, and the Celsius
//              equivalents of all Fahrenheit temperatures from 32 to 212 degree
//
//
// Parameters:  None
//
// Returns:     None
//
// ***************************************************
void printCelsiusAndFahrenheit() {

    // Calculate and print Celsius to Fahrenheit for temperatures from 0 to 100 degrees
    printf("\nCelsius\t\tFahrenheit\n");
    for(int i = 0; i <= 100; i++) {
        printf("%i\t\t\t%5.2f\n", i, toFahrenheit(i));
    }

    // Calculate and print Fahrenheit to Celsius for temperatures from 32 to 212 degrees
    printf("\nFahrenheit\tCelsius\n");
    for(int i = 32; i <= 212; i++) {
        printf("%0i\t\t\t\t%5.2f\n", i, toCelsius(i));
    }
}

// Question 8:
/*
 * The following data models, model the data below
        Name: Mr. James Tiberius Kirk
        Date of Birth: March 22, 2233
        Address: 23 Falling Rock, Riverside, Iowa 52327-0021 Planet Earth
        Rank: Captain
        Last Promotion Date: April 12, 2224
        Ship: USS Enterprise
        Nickname: Jim
        Starfleet ID: 02341232
        Hourly Pay: 456.78
        Favorite Saying: "Bones???"
        Starting Stardate: 41153.7
        Martial Status: Single
        Starfleet Graduation Date: June 23, 2212
 */

// a structure representing a date
struct date {
    int day;
    int month;
    int year;
};

// a structure representing an address
struct address {
    int address;
    char streetName[100];
    char city[50];
    char state[100];
    char zipCode[10];
    char planet[100];
};

// a structure representing a Federation Employee
struct federationEmployee {
    char name[100];
    struct date dateOfBirth;
    struct address address;
    char rank[20];
    struct date lastDateOfPromotion;
    char shipName[50];
    char nickName[100];
    int starFleetId;
    float hourlyRate;
    char favoriteSaying[100];
    float startingStarDate;
    char maritalStatus[10];
    struct date starFleetGradDate;
};

// Question 9:
/*
 * My Compiler/IDE: c compiler / CLion from JetBrains
 * 4 Likes/Dislikes
 * 1. Like: I like that I didn't have to specify the compiler.
 * 2. Like: Works for my current needs.
 * 3. Like: Provides adequate error messages when compiling.
 * 4. Dislike: Since I did not have to choose the compiler, I haven't learned too much or
 *    have experience using other compilers.
 */

int main(void)
{
    // printf("%d\n", irishLicensePlateValidator(13, 1, 'D', 21));
    // int theArray[] = {5, 7, 23, 8, 23, 67, 23};
    // printf("%d", frequency(theArray, 6, 23));
    // printf("%d", findMin(-1, 4, 1, 22));
    // printf("%c", getLetterGrade(100));
    // char countyCodes [ ] = {'C', 'c', 'E', 'G', 'G', 'L', 'l', 'l', 'T', 'W', 'J', 'd'};
    // getCountyTotals(12, countyCodes);
    //printCelsiusAndFahrenheit();

    return 0;
}
