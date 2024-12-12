//******************************************************* 
// 
// Homework: 2
// 
// Name: Annette Ambriz
// 
// Class: C Programming, 2024
// 
// Date: 09/19/24
// 
// Description: Program which determines gross pay
// and outputs are sent to standard output (the screen).
// 
// 
//******************************************************** 

#include <stdio.h>
int WageCalculatorWithLoop ( )
{
    int numberOfEmployees = 0;

    printf ("*** Pay Calculator ***\n");

    // Prompt to capture how many employees to process
    printf ("\nEnter the number of employees to process: ");
    scanf ("%d", &numberOfEmployees);

    for (int idx = 1; idx <= numberOfEmployees; idx++) {
        int clockNumber;    // employee clock number
        float grossPay;     // gross pay for week (wage * hours)
        float hours;        // number of hours worked per week
        float wageRate;     // hourly wage

        // Prompt for input values from the screen
        printf ("\nEnter clock number for employee: ");
        scanf ("%d", &clockNumber);
        printf ("\nEnter hourly wage for employee: ");
        scanf ("%f", &wageRate);
        printf ("\nEnter the number of hours the employee worked: ");
        scanf ("%f", &hours);

        // calculate gross pay
        grossPay = wageRate * hours;

        // print out employee information
        printf ("\n\n\t----------------------------------------------------------\n");
        printf ("\tClock # Wage Hours Gross\n");
        printf ("\t----------------------------------------------------------\n");

        // print the data for the current employee
        printf ("\t%06i %5.2f %5.1f %7.2f\n",clockNumber, wageRate, hours, grossPay);
    }

    return (0); // success

} // main