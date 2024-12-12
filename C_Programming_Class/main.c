//********************************************************
//
// Assignment 5 - Functions
//
// Name: Annette Ambriz
//
// Class: C Programming, Fall 2024
//
// Date: 10/11/2024
//
// Description: Program which determines overtime and
// gross pay for a set of employees with outputs sent
// to standard output (the screen).
//
// Functions called by a combination of by value and by
// reference.
//
//********************************************************

#include <stdio.h>

// Constants
#define SIZE 5
#define OVERTIME_RATE 1.5f
#define STD_WORK_WEEK 40.0f

// Function prototypes to process inputs
void processInput (long int clockNumber [], float hours[], float wageRate[]);
int long getClockNumber ();
float getHours ();
float getWageRate ();

// Function prototypes to calculate outputs
void calculateOutputs (float wageRate[], float hours[], float normalPay[], float overtimeHrs[],
    float overTimePay[], float grossPay[]);
int calculateOverTime (float hours);
float calculateOverTimePay (float wageRate, float overTimeHours);
float calculateRegularPay (float wageRate);

// Function prototypes to display outputs
void displayResults (long int clockNumber[], float wageRate[], float hours[], float normalPay[],
    float overtimeHrs[], float overTimePay[], float grossPay[]);
void printHeader (void);
void printEmp  (long int clockNumber[], float wageRate[], float hours[], float normalPay[],
    float overtimeHrs[], float overTimePay[], float grossPay[]);

int main ()
{
    // Variable Declarations
    long int clockNumber [SIZE]; // unique employee identifier
    float grossPay [SIZE]; // weekly gross pay - normal pay + overtimePay
    float hours [SIZE]; // hours worked in a given week
    float normalPay [SIZE]; // normal weekly pay without any overtime
    float overtimeHrs[SIZE]; // overtime hours worked in a given week
    float overtimePay [SIZE]; // overtime pay for a given week
    float wageRate [SIZE]; // Hourly pay for each employee

    printf ("\n*** Pay Calculator ***\n");

    // Call worker bee function to process input
    processInput(clockNumber, hours, wageRate);

    // Call worker bee function to calculate outputs
    calculateOutputs(wageRate, hours, normalPay, overtimeHrs, overtimePay, grossPay);

    // Call worker bee function to display outputs
    displayResults(clockNumber, wageRate, hours, normalPay, overtimeHrs, overtimePay, grossPay);

    return 0;

}  // main

//**************************************************************
// Function: processInput
//
// Purpose: Runs functions to obtain input from user
//
// Parameters: clockNumber array - array to store unique employee ids
//             hours array - array to store hours worked by each employee
//             wageRate array - array to store wage rate of each employee
//
// Returns: Void
//
//**************************************************************

void processInput (long int clockNumber [], float hours[], float wageRate[])
{
    // Process each employee one at a time
    for (int i = 0; i < SIZE; i++) {

        // Call getClockNumber to get employee number
        clockNumber[i] = getClockNumber();

        // Call getWageRate to get the wage rate
        wageRate[i] = getWageRate();

        // Call getHours for the number of hours worked
        hours[i] = getHours();
    } // for
} // processInput

//**************************************************************
// Function: getWageRate
//
// Purpose: Obtains wageRate from user, the rate at which the
// employee is paid and stores the result in a local variable
// that is passed back to the calling function.
//
// Parameters: None
//
// Returns: wageRate - a pay rate for an employee
//
//**************************************************************

float getWageRate ()
{
    float wageRate; // employee wage rate

    // Prompt the user for the clock number
    printf("Enter your wage rate number: ");
    scanf("%f", &wageRate);

    // return wageRate back to the calling function
    return wageRate;
} // getWageRate

//**************************************************************
// Function: getClockNumber
//
// Purpose: Obtains input from user, the clock number for the
// employee and stores the result in a local variable
// that is passed back to the calling function.
//
// Parameters: None
//
// Returns: clockNumber - a clock number for an employee
//
//**************************************************************

int long getClockNumber ()
{
    int long clockNumber; // employee clock number

    // Prompt the user for the clock number
    printf("\nEnter clock number: ");
    scanf("%li", &clockNumber);

    // return clockNumber back to the calling function
    return clockNumber;

} // getHours

//**************************************************************
// Function: getHours
//
// Purpose: Obtains input from user, the number of hours worked
// for an employee and stores the result in a local variable
// that is passed back to the calling function.
//
// Parameters: None
//
// Returns: hoursWorked - hours worked in a given week
//
//**************************************************************

float getHours ()
{
    float hoursWorked; // hours worked in a given week

    // Prompt the user for the number of hours worked
    printf("Enter number of hours worked: ");
    scanf("%f", &hoursWorked);

    // return hoursWorked back to the calling function
    return hoursWorked;
} // getHours

//**************************************************************
// Function: calculateOutputs
//
// Purpose: Runs functions to calculate outputs of the program. Uses the number of
// hours worked to calculate the normalPay, overTimePay, grossPay per employee.
//
// Parameters:      wageRate array - array containing the wage rate of each employee
//                  hours array - array containing the hours worked of each employee
//                  normalPay array - array to store normal pay for each employee
//                  overtimeHrs array - array to store overtime hours worked for each employee
//                  overTimePay array - array to store overtime pay for each employee
//                  grossPay array - array to store the gross pay for each employee
//
// Returns: Void
//
//**************************************************************

void calculateOutputs (float wageRate[], float hours[], float normalPay[], float overtimeHrs[],
    float overTimePay[], float grossPay[])
{
    // Calculate output values for each employee one at a time
    for (int i = 0; i < SIZE; i++)
    {
        // Call function to calculate overtimeHrs
        overtimeHrs[i] = calculateOverTime(hours[i]);

        // Call function to calculate normalPay
        normalPay[i] = calculateRegularPay(wageRate[i]);

        // Call function to calculate overTimePay
        overTimePay[i] = calculateOverTimePay(wageRate[i], overtimeHrs[i]);

        // Calculate gross pay
        grossPay[i] = normalPay[i] + overTimePay[i];
    }
} // calculateOutputs

//**************************************************************
// Function: calculateOverTime
//
// Purpose: Calculates the overtime hours worked by an employee and stores
// the result in a local variable that is passed back to the calling function.
//
// Parameters: hours - hours worked by an employee
//
// Returns: overtimeHours - overtime hours worked in a given week
//
//**************************************************************

int calculateOverTime (float hours) {
    float overtimeHours;

    if (hours >= STD_WORK_WEEK)
        overtimeHours = hours - STD_WORK_WEEK;
    else
        overtimeHours = 0;

    return overtimeHours;
} //calculateOverTime

//**************************************************************
// Function: calculateOverTimePay
//
// Purpose: Calculates the calculateOverTimePay for an employee and stores
// the result in a local variable that is passed back to the calling function.
//
// Parameters: wageRate - wage rate for an employee
//             overTimeHours -overtime hours worked by an employee
//
// Returns: overTimePay - overtime pay for an employee in a given week
//
//**************************************************************

float calculateOverTimePay (float wageRate, float overTimeHours) {
    float overTimePay = OVERTIME_RATE * overTimeHours * wageRate;

    return overTimePay;
} //calculateOverTimePay

//**************************************************************
// Function: calculateRegularPay
//
// Purpose: Calculates the regular or "normal" pay for an employee and stores
// the result in a local variable that is passed back to the calling function.
//
// Parameters: wageRate - wage rate for an employee
//
// Returns: regularPay - regular pay for an employee in a given week
//
//**************************************************************

float calculateRegularPay (float wageRate) {
    float regularPay = wageRate * STD_WORK_WEEK;

    return regularPay;
} // calculateRegularPay


//**************************************************************
// Function: displayResults
//
// Purpose: Runs functions to obtain display outputs to standard out
//
// Parameters:      clockNumber array - array containing the unique id of each employee
//                  wageRate array - array containing the wage rate of each employee
//                  hours array - array containing the hours worked of each employee
//                  normalPay array - array containing the normal pay for each employee
//                  overtimeHrs array - array containing the overtime hours worked for each employee
//                  overTimePay array - array containing the overtime pay for each employee
//                  grossPay array - array containing the gross pay for each employee
//
// Returns: Void
//
//**************************************************************

void displayResults (long int clockNumber[], float wageRate[], float hours[], float normalPay[],
    float overtimeHrs[], float overTimePay[], float grossPay[])
{
    printHeader ();
    printEmp (clockNumber, wageRate, hours, normalPay, overtimeHrs, overTimePay, grossPay);
} // displayResults

//**************************************************************
// Function: printHeader
//
// Purpose: Prints the initial table header information.
//
// Parameters: None
//
// Returns: void
//
//**************************************************************

void printHeader (void)
{

    // print the table header
    printf("\nClock#\t\tWage\t\tHours\t\tOT\t\t\tNormalPay\tOvertimePay\t\tGross\n");
    printf("-------------------------------------------------------------------------------------\n");
} // printHeader

//*************************************************************
// Function: printEmp
//
// Purpose: Prints out all the employee information in a
// nice and orderly table format.
//
// Parameters:
//
//     clockNumber - Array of employee clock numbers
//     wageRate - Array of employee wages per hour
//     hours - Array of number of hours worked by an employee
//     overtimeHrs - Array of overtime hours for each employee
//     grossPay - Array of gross pay calculations for each employee
//     theSize - Number of employees to process
//
// Returns: Nothing (call by reference)
//
//**************************************************************

void printEmp  (long int clockNumber[], float wageRate[], float hours[], float normalPay[],
    float overtimeHrs[], float overTimePay[], float grossPay[])
{
    // access and print each employee
    for (int i = 0; i < SIZE; ++i)
    {
        printf("%06li\t\t%5.2f\t\t%5.2f\t\t%5.2f\t\t%5.2f\t\t%5.2f\t\t%8.2f\n", clockNumber [i], wageRate [i],
            hours [i], overtimeHrs [i], normalPay [i], overTimePay [i], grossPay [i]);
    } //for
} //printEmp
