//********************************************************
//
// Assignment 7 - Structures and Strings
//
// Name: Annette Ambriz
//
// Class: C Programming, Fall 2024
//
// Date: 11/3/2024
//
// Description: Program which determines overtime and 
// gross pay for a set of employees with outputs sent 
// to standard output (the screen).
//
// This assignment also adds the employee name, their tax state,
// and calculates the state tax, federal tax, and net pay.   It
// also calculates totals, averages, minimum, and maximum values.
//
// Call by Value design
//
//********************************************************

// necessary header files
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// define constants
#define SIZE 5
#define STD_HOURS 40.0
#define OT_RATE 1.5
#define MA_TAX_RATE 0.05
#define NH_TAX_RATE 0.0
#define VT_TAX_RATE 0.06
#define CA_TAX_RATE 0.07
#define DEFAULT_TAX_RATE 0.08
#define NAME_SIZE 20
#define TAX_STATE_SIZE 3
#define FED_TAX_RATE 0.25
#define FIRST_NAME_SIZE 10
#define LAST_NAME_SIZE 10

// Define a structure type to store an employee name
// ... note how one could easily extend this to other parts
// parts of a name:  Middle, Nickname, Prefix, Suffix, etc.
struct name
{
    char firstName[FIRST_NAME_SIZE];
    char lastName [LAST_NAME_SIZE];
};

// Define a structure type to pass employee data between functions
// Note that the structure type is global, but you don't want a variable
// of that type to be global. Best to declare a variable of that type
// in a function like main or another function and pass as needed.
struct employee
{
    struct name empName;
    char taxState [TAX_STATE_SIZE];
    long int clockNumber;
    float wageRate;
    float hours;
    float overtimeHrs;
    float grossPay;
    float stateTax;
    float fedTax;
    float netPay;
};

// this structure type defines the totals of all floating point items
// so they can be totaled and used also to calculate averages
struct totals
{
    float total_wageRate;
    float total_hours;
    float total_overtimeHrs;
    float total_grossPay;
    float total_stateTax;
    float total_fedTax;
    float total_netPay;
};

// this structure type defines the min and max values of all floating
// point items so they can be display in our final report
struct min_max
{
    float min_wageRate;
    float min_hours;
    float min_overtimeHrs;
    float min_grossPay;
    float min_stateTax;
    float min_fedTax;
    float min_netPay;
    float max_wageRate;
    float max_hours;
    float max_overtimeHrs;
    float max_grossPay;
    float max_stateTax;
    float max_fedTax;
    float max_netPay;
};

// define prototypes here for each function except main
float getHours (long int clockNumber);
float calcOvertimeHrs (float hours);
float calcGrossPay (float wageRate, float hours, float overtimeHrs);
void printHeader (void);

void printEmp (char firstname [], char lastName [], char taxState [], 
               long int clockNumber, float wageRate, 
               float hours, float overtimeHrs, float grossPay,
               float stateTax, float fedTax, float netPay);
               
float calcStateTax (float grossPay, char taxState[]);
float calcFedTax (float grossPay);
float calcNetPay (float grossPay, float stateTax, float fedTax);

struct totals calcEmployeeTotals (float wageRate, 
                                  float hours,
                                  float overtimeHrs, 
                                  float grossPay,
                                  float stateTax,
                                  float fedTax,
                                  float netPay,
                                  struct totals employeeTotals);
                                 
struct min_max calcEmployeeMinMax (float wageRate, 
                                   float hours,
                                   float overtimeHrs, 
                                   float grossPay,
                                   float stateTax,
                                   float fedTax,
                                   float netPay,
                                   struct min_max employeeMinMax,
                                   int arrayIndex);
                                  
void printEmpStatistics (struct totals employeeTotals, 
                         struct min_max employeeMinMax,
                         int theSize);
                         
// Add your other function prototypes if needed here

int main ()
{

    int i;  // loop and array index
    
    // Set up a local variable to store the employee information
    // Initialize the name, tax state, clock number, and wage rate
    struct employee employeeData[SIZE] = {
        { {"Connie", "Cobol"}, "MA", 98401, 10.60},
        { {"Mary", "Apl"}, "NH", 526488, 9.75 },
        { {"Frank", "Fortran"}, "VT", 765349, 10.50 },
        { {"Jeff", "Ada"}, "NY", 34645, 12.25 },
        { {"Anton", "Pascal"},"CA",127615, 8.35 }
    };
    
    // set up structure to store totals and initialize all to zero
    struct totals employeeTotals  = {0,0,0,0,0,0,0};
    
    // set up structure to store min and max values and initialize all to zero
    struct min_max employeeMinMax = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    // Call functions as needed to read and calculate information
    for (i = 0; i < SIZE; ++i) 
    { 

        // Prompt for the number of hours worked by the employee 
        employeeData[i].hours = getHours (employeeData[i].clockNumber); 

        // Calculate the overtime hours
        employeeData[i].overtimeHrs = calcOvertimeHrs (employeeData[i].hours);
       
        // Calculate the weekly gross pay
        employeeData[i].grossPay = calcGrossPay (employeeData[i].wageRate, 
                                                 employeeData[i].hours, 
                                                 employeeData[i].overtimeHrs);
        // Calculate the state tax                                       
        employeeData[i].stateTax = calcStateTax (employeeData[i].grossPay,
                                                 employeeData[i].taxState);
        // Calculate the federal tax                                                   
        employeeData[i].fedTax = calcFedTax (employeeData[i].grossPay);
 
        // Calculate the net pay after taxes   
        employeeData[i].netPay = calcNetPay (employeeData[i].grossPay, 
                                             employeeData[i].stateTax, 
                                             employeeData[i].fedTax);
        
        // Keep a running sum of the employee totals                                     
        employeeTotals = calcEmployeeTotals (employeeData[i].wageRate, 
                                             employeeData[i].hours,
                                             employeeData[i].overtimeHrs, 
                                             employeeData[i].grossPay,
                                             employeeData[i].stateTax,
                                             employeeData[i].fedTax,
                                             employeeData[i].netPay,
                                             employeeTotals);
                                             
        // Keep a running update of the employee minimum and maximum values                                     
        employeeMinMax = calcEmployeeMinMax (employeeData[i].wageRate, 
                                             employeeData[i].hours,
                                             employeeData[i].overtimeHrs, 
                                             employeeData[i].grossPay,
                                             employeeData[i].stateTax,
                                             employeeData[i].fedTax,
                                             employeeData[i].netPay,
                                             employeeMinMax,
                                             i);
       
    } // for

    // Print the column headers
    printHeader();

    // print out final information on each employee
    for (i = 0; i < SIZE; ++i) 
    { 
        printEmp (employeeData[i].empName.firstName,
                  employeeData[i].empName.lastName,
                  employeeData[i].taxState,
                  employeeData[i].clockNumber, 
                  employeeData[i].wageRate, 
                  employeeData[i].hours,
                  employeeData[i].overtimeHrs, 
                  employeeData[i].grossPay,
                  employeeData[i].stateTax,
                  employeeData[i].fedTax,
                  employeeData[i].netPay);
    } // for
    
    // print the totals and averages for all float items
    printEmpStatistics (employeeTotals, employeeMinMax, SIZE);

    return (0); // success

} // main

//**************************************************************
// Function: getHours 
// 
// Purpose: Obtains input from user, the number of hours worked 
//          per employee and stores the result in a local variable 
//          that is passed back to the calling function. 
// 
// Parameters: 
//
//   clockNumber - The unique employee ID
// 
// Returns: theHoursWorked - hours worked in a given week
//  
//**************************************************************

float getHours (long int clockNumber) 
{ 

    float theHoursWorked; // hours worked in a given week 

    // Read in hours for employee 
    printf("\nEnter hours worked by emp # %06li: ", clockNumber); 
    scanf ("%f", &theHoursWorked); 

    // return hours back to the calling function
    return (theHoursWorked); 
    
} // getHours

//**************************************************************
// Function: printHeader
// 
// Purpose: Prints the initial table header information.
// 
// Parameters: none
// 
// Returns: void
//  
//**************************************************************

void printHeader (void) 
{ 

    printf ("\n\n*** Pay Calculator ***\n");

    // print the table header
    printf("\n--------------------------------------------------------------");
    printf("-------------------");
    printf("\nName                Tax  Clock# Wage   Hours  OT   Gross ");
    printf("  State  Fed      Net");
    printf("\n                   State                           Pay   ");
    printf("  Tax    Tax      Pay");
    
    printf("\n--------------------------------------------------------------");
    printf("-------------------");

} // printHeader

//************************************************************* 
// Function: printEmp 
// 
// Purpose: Prints out all the information for an employee
//          in a nice and orderly table format.
// 
// Parameters: 
//
//   firstName - the employee first name
//   lastName - the employee last name
//   taxState - the state where the employee works
//   clockNumber - unique employee ID
//   wageRate - hourly wage rate
//   hours - Hours worked for the week
//   overtimeHrs - overtime hours worked in a week
//   grossPay - gross pay for the week
//   stateTax - the calculated state tax
//   fedTax - the calculated federal tax
//   netPay - the calculated take home pay after taxes
// 
// Returns: void
//  
//**************************************************************

void printEmp (char firstName [], char lastName [], char taxState [], 
               long int clockNumber, float wageRate, 
               float hours, float overtimeHrs, float grossPay,
               float stateTax, float fedTax, float netPay)
{

    // Used to format the employee name
    char name [FIRST_NAME_SIZE + LAST_NAME_SIZE + 1];
    
    // While you could just print the first and last name in the printf
    // statement that follows, you could also use various C string library
    // functions to format the name exactly the way you want it.  Breaking
    // the name into first and last members additionally gives you some 
    // flexibility in printing.  This also becomes more useful if we decide
    // later to store other parts of a person's name. I really did this just 
    // to show you how to work with some of the common string functions.
    strcpy (name, firstName);
    strcat (name, " "); // add a space between first and last names
    strcat (name, lastName);
    
    // Print out a single employee
    printf("\n%-20.20s %-2.2s  %06li %5.2f  %4.1f  %4.1f %7.2f %6.2f %7.2f %8.2f",
             name, taxState, clockNumber, wageRate, hours,
             overtimeHrs, grossPay, stateTax, fedTax, netPay);
          
} // printEmp

//************************************************************* 
// Function: printEmpStatistics 
// 
// Purpose: Prints out the totals and averages of all 
//          floating point value items for all employees
//          that have been processed.
// 
// Parameters: 
//
//   employeeTotals - a structure containing a running total 
//                    of all employee floating point items 
//   employeeMinMax - a structure containing all the minimum 
//                    and maximum values of all employee 
//                    floating point items
//   theSize - the total number of employees processed, used 
//             to check for zero or negative divide condition.
// 
// Returns: void
//  
//**************************************************************

void printEmpStatistics (struct totals employeeTotals, 
                         struct min_max employeeMinMax,
                         int theSize)
{
    
    // print a separator line
    printf("\n--------------------------------------------------------------");
    printf("-------------------");
   
    // print the totals for all the floating point fields

    // DONE TODO - replace the zeros below with the correct reference to the
    //        reference to the member total item
    printf("\nTotals:                         %5.2f %5.1f %5.1f %7.2f %6.2f %7.2f %8.2f",
             employeeTotals.total_wageRate,
             employeeTotals.total_hours,
             employeeTotals.total_overtimeHrs,
             employeeTotals.total_grossPay,
             employeeTotals.total_stateTax,
             employeeTotals.total_fedTax,
             employeeTotals.total_netPay);
    
    // make sure you don't divide by zero or a negative number
    if (theSize > 0)       
    {
        // print the averages for all the floating point fields
        // DONE TODO - replace the zeros below with the correct reference to the
        //        the average calculation using with the correct total item
        printf("\nAverages:                       %5.2f %5.1f %5.1f %7.2f %6.2f %7.2f %8.2f",
                 employeeTotals.total_wageRate/theSize,
                 employeeTotals.total_hours/theSize,
                 employeeTotals.total_overtimeHrs/theSize,
                 employeeTotals.total_grossPay/theSize,
                 employeeTotals.total_stateTax/theSize,
                 employeeTotals.total_fedTax/theSize,
                 employeeTotals.total_netPay/theSize);
    } // if
    
    // print the min and max values
    // Done TODO - replace the zeros below with the correct reference to the
    //        to the min member field
    printf("\nMinimum:                        %5.2f %5.1f %5.1f %7.2f %6.2f %7.2f %8.2f",
             employeeMinMax.min_wageRate,
             employeeMinMax.min_hours,
             employeeMinMax.min_overtimeHrs,
             employeeMinMax.min_grossPay,
             employeeMinMax.min_stateTax,
             employeeMinMax.min_fedTax,
             employeeMinMax.min_netPay);

    // Done TODO - replace the zeros below with the correct reference to the
    //        to the max member field   
    printf("\nMaximum:                        %5.2f %5.1f %5.1f %7.2f %6.2f %7.2f %8.2f",
             employeeMinMax.max_wageRate,
             employeeMinMax.max_hours,
             employeeMinMax.max_overtimeHrs,
             employeeMinMax.max_grossPay,
             employeeMinMax.max_stateTax,
             employeeMinMax.max_fedTax,
             employeeMinMax.max_netPay);
           
}  // printEmpStatistics

//*************************************************************
// Function: calcOvertimeHrs
//
// Purpose: Calculates the overtime hours worked by an employee
//          in a given week.
//
// Parameters:
//
//   hours - Hours worked in a given week
//
// Returns: theOvertimeHrs - overtime hours worked by an employee 
//                                            in a given week
//
//**************************************************************

float calcOvertimeHrs (float hours)
{
    
    float theOvertimeHrs; // calculated overtime hours for employee
  
    // Any overtime ?
    if (hours >= STD_HOURS)
    {
        theOvertimeHrs = hours - STD_HOURS;
    }
    else // no overtime
    {
          theOvertimeHrs = 0;
    }

    // return overtime hours back to the calling function
    return (theOvertimeHrs);

} // calcOvertimeHrs

//*************************************************************
// Function: calcGrossPay
//
// Purpose: Calculates the gross pay based on the the normal pay
//          and any overtime pay for a given week.
//
// Parameters:
//
//   wageRate - the hourly wage rate
//   hours - the hours worked in a given week
//   overtimeHrs - hours worked above normal hours
//
// Returns: theGrossPay - total weekly gross pay for an employee
//
//**************************************************************

float calcGrossPay (float wageRate, float hours, float overtimeHrs)
{
    
    float theGrossPay;    // gross pay earned in a given week
    float theNormalPay;   // normal pay without any overtime hours
    float theOvertimePay; // overtime pay
  
    // calculate normal pay and any overtime pay
    theNormalPay = wageRate * (hours - overtimeHrs);
    theOvertimePay = overtimeHrs * (OT_RATE * wageRate);
  
    // calculate gross pay for employee as normalPay + any overtime pay
    theGrossPay = theNormalPay + theOvertimePay;
  
    // return the calculated gross pay value back
    return (theGrossPay);

} // calcGrossPay

//*************************************************************
// Function: calcStateTax
//
// Purpose: Calculates the State Tax owed based on gross pay
//
// Parameters:
//
//   grossPay - the grossPay for a given week
//   taxState - the physical state where the employee works
//
// Returns: theStateTax - calculated state tax owed
//
//**************************************************************

float calcStateTax (float grossPay, char taxState[])
{
    
    float theStateTax; // calculated state tax
    
    theStateTax = grossPay;  // initialize to gross pay
    
    // Make sure tax state is all uppercase
    if (islower(taxState[0]))
        taxState[0] = toupper(taxState[0]); // make upper case
    if (islower(taxState[1]))
        taxState[1] = toupper(taxState[1]); // make upper case
        
    // calculate state tax based on where employee resides
    if (strcmp(taxState, "MA") == 0)
        theStateTax *= MA_TAX_RATE;
    else if (strcmp(taxState, "NH") == 0)
        theStateTax *= NH_TAX_RATE;
        
    // DONE TODO:  Fix the state tax calculations for VT and CA ...
    //        right now both are set to zero
    else if (strcmp(taxState, "VT") == 0)
        theStateTax *= VT_TAX_RATE;
    else if (strcmp(taxState, "NH") == 0)
        theStateTax *= NH_TAX_RATE;
    else if (strcmp(taxState, "CA") == 0)
        theStateTax *= CA_TAX_RATE;
    else
        theStateTax *= DEFAULT_TAX_RATE;  // any other state
     
    // return the calculated state tax back  
    return (theStateTax);
       
} // calcStateTax

//*************************************************************
// Function: calcFedTax
//
// Purpose: Calculates the Federal Tax owed based on the gross 
//          pay
//
// Parameters:
//
//   grossPay - the grossPay for a given week
//
// Returns: theFedTax - calculated federal tax owed
//
//**************************************************************

float calcFedTax (float grossPay)
{
    
    float theFedTax; // The calculated Federal Tax
   
    // Done TODO:  Fix the fedTax calculation to be the gross pay
    //        multiplied by the Federal Tax Rate (use constant
    //        provided).

    // Fed Tax is the same for all regardless of state
    theFedTax = FED_TAX_RATE;
    
    // return the calculated federal tax back
    return (theFedTax);
    
} // calcFedTax

//*************************************************************
// Function: calcNetPay
//
// Purpose: Calculates the net pay as the gross pay minus any
//          state and federal taxes owed. Essentially, your 
//          "take home" pay.
//
// Parameters:
//
//   grossPay - the grossPay for a given week
//   stateTax - the state taxes owed
//   fedTax   - the fed taxes owed
//
// Returns: theNetPay - calculated take home pay (minus taxes)
//
//**************************************************************

float calcNetPay (float grossPay, float stateTax, float fedTax)
{
    
    float theNetPay;      // total take home pay (minus taxes)
    float theTotalTaxes;  // total taxes owed
    
    // calculate the total state and federal taxes
    theTotalTaxes = stateTax + fedTax;
    
    // Done TODO:  Fix the netPay calculation to be the gross pay minus the
    //        the total taxes paid

    // calculate the net pay
    theNetPay = grossPay - theTotalTaxes;
    
    // return the calculated net pay back
    return (theNetPay);
    
} // calcNetPay

//*************************************************************
// Function: calcEmployeeTotals
//
// Purpose: Accepts various floating point values from an
//          employee and adds to a running total.
//
// Parameters:
//
//   wageRate       - hourly wage rate
//   hours          - hours worked in a given week
//   overtimeHrs    - overtime hours worked in a week
//   grossPay       - the grossPay for a given week
//   stateTax       - the state taxes owed
//   fedTax         - the fed taxes owed
//   netPay         - total take home page (after taxes)
//   employeeTotals - structure containing a running totals 
//                    of all fields above
//
// Returns: employeeTotals - updated employeeTotals structure
//
//**************************************************************

struct totals calcEmployeeTotals (float wageRate, 
                                  float hours,
                                  float overtimeHrs, 
                                  float grossPay,
                                  float stateTax,
                                  float fedTax,
                                  float netPay,
                                  struct totals employeeTotals)
{
    
    // add current employee data to our running totals
    employeeTotals.total_wageRate += wageRate;
    employeeTotals.total_hours += hours;
    employeeTotals.total_overtimeHrs += overtimeHrs;
    employeeTotals.total_grossPay += grossPay;
    employeeTotals.total_stateTax += stateTax;
    employeeTotals.total_fedTax += fedTax;
    employeeTotals.total_netPay += netPay;
    
    // return all the updated totals to the calling function
    return (employeeTotals);
    
} // calcEmployeeTotals

//*************************************************************
// Function: calcEmployeeMinMax
//
// Purpose: Accepts various floating point values from an
//          employee and adds to a running update of min
//          and max values
//
// Parameters:
//
//   wageRate       - hourly wage rate
//   hours          - hours worked in a given week
//   overtimeHrs    - overtime hours worked in a week
//   grossPay       - the grossPay for a given week
//   stateTax       - the state taxes owed
//   fedTax         - the fed taxes owed
//   netPay         - total take home page (after taxes)
//   employeeTotals - structure containing a running totals 
//                    of all fields above
//   arrayIndex - the array index of the current set of element
//                members being processed for the Array of 
//                Employee structure
//
// Returns: employeeMinMax - updated employeeMinMax structure
//
//**************************************************************

struct min_max calcEmployeeMinMax (float wageRate, 
                                   float hours,
                                   float overtimeHrs, 
                                   float grossPay,
                                   float stateTax,
                                   float fedTax,
                                   float netPay,
                                   struct min_max employeeMinMax,
                                   int arrayIndex)
{
    
    // if this is the first set of data items, set 
    // them to the min and max
    if (arrayIndex == 0)
    {
        /* set the min to the first element members */
        employeeMinMax.min_wageRate = wageRate; 
        employeeMinMax.min_hours = hours;
        employeeMinMax.min_overtimeHrs = overtimeHrs; 
        employeeMinMax.min_grossPay = grossPay;
        employeeMinMax.min_stateTax = stateTax;
        employeeMinMax.min_fedTax = fedTax;
        employeeMinMax.min_netPay = netPay;
        
        // set the max to the first element members
        employeeMinMax.max_wageRate = wageRate; 
        employeeMinMax.max_hours = hours;
        employeeMinMax.max_overtimeHrs = overtimeHrs; 
        employeeMinMax.max_grossPay = grossPay;
        employeeMinMax.max_stateTax = stateTax;
        employeeMinMax.max_fedTax = fedTax;
        employeeMinMax.max_netPay = netPay;
        
    } // if
    
    else if (arrayIndex >= 1) // process if other array elements
    {
        
        // check if current Wage Rate is the new min and/or max
        if (wageRate < employeeMinMax.min_wageRate)
        {
            employeeMinMax.min_wageRate = wageRate;
        }
        
        if (wageRate > employeeMinMax.max_wageRate)
        {
            employeeMinMax.max_wageRate = wageRate;
        }

        // check if current Hours is the new min and/or max
        if (wageRate < employeeMinMax.min_hours)
        {
            employeeMinMax.min_hours = wageRate;
        }

        if (wageRate > employeeMinMax.max_hours)
        {
            employeeMinMax.max_hours = wageRate;
        }

        // check if current Overtime hours is the new min and/or max
        if (wageRate < employeeMinMax.min_overtimeHrs)
        {
            employeeMinMax.min_overtimeHrs = wageRate;
        }

        if (wageRate > employeeMinMax.max_overtimeHrs)
        {
            employeeMinMax.max_overtimeHrs = wageRate;
        }

        // check if current Gross Pay is the new min and/or max
        if (wageRate < employeeMinMax.min_grossPay)
        {
            employeeMinMax.min_grossPay = wageRate;
        }

        if (wageRate > employeeMinMax.max_grossPay)
        {
            employeeMinMax.max_grossPay = wageRate;
        }

        // check if current State Tax is the new min and/or max
        if (wageRate < employeeMinMax.min_stateTax)
        {
            employeeMinMax.min_stateTax = wageRate;
        }

        if (wageRate > employeeMinMax.max_stateTax)
        {
            employeeMinMax.max_stateTax = wageRate;
        }


        // check if current Fed Tax is the new min and/or max
        if (wageRate < employeeMinMax.min_fedTax)
        {
            employeeMinMax.min_fedTax = wageRate;
        }

        if (wageRate > employeeMinMax.max_fedTax)
        {
            employeeMinMax.max_fedTax = wageRate;
        }

        // check if current Net Pay is the new min and/or max
        if (wageRate < employeeMinMax.min_netPay)
        {
            employeeMinMax.min_netPay = wageRate;
        }

        if (wageRate > employeeMinMax.max_netPay)
        {
            employeeMinMax.max_netPay = wageRate;
        }
        // Done TODO: do the same checking for the other min and max items
        //       ... just repeat the two "if statements" with the right
        //       reference between the specific min and max fields and
        //       employeeData array of structures item.
        
        
    } // else if
    
    // return all the updated min and max values to the calling function
    return (employeeMinMax);
} // calcEmployeeMinMax