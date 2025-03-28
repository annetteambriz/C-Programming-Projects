//******************************************************* 
// 
// Homework: 1 (Chapter 4/5) 
// 
// Name: Annette Ambriz
// 
// Class: C Programming, Fall 2024
// 
// Date: 09-11-2024
// 
// Description: Program which determines gross pay and outputs 
// to the screen.   This version does not use file pointers
//
// Non file pointer solution 
// 
//******************************************************** 
 
#include <stdio.h>  
int WageCalculator()
{ 
 
    int clockNumber; // employee clock number 
    float gross;     // gross pay for week (wage * hours) 
    float hours;     // number of hours worked per week 
    float wageRate;  // hourly wage 
 
    printf ("\n\t*** Pay Calculator ***\n");
 
    // Prompt for input values from the screen 
    printf ("\n\tEnter clock number for employee: "); 
    scanf ("%d", &clockNumber); 
    printf ("\n\tEnter hourly wage for employee: "); 
    scanf ("%f", &wageRate); 
    printf ("\n\tEnter the number of hours the employee worked: "); 
    scanf ("%f", &hours); 
 
    // calculate gross pay
    gross = wageRate * hours; 
 
    // print out employee information 
    printf ("\n\n\t----------------------------------------------------------\n"); 
    printf ("\tClock # Wage Hours Gross\n"); 
    printf ("\t----------------------------------------------------------\n"); 
 
    printf ("\t%06i %5.2f %5.1f %7.2f\n", clockNumber, wageRate, hours, gross); 
 
    return (0); // success
 
} // main


/* Example output:
 *
*** Pay Calculator ***

Enter clock number for employee: 8898

Enter hourly wage for employee: 100

Enter the number of hours the employee worked: 1


----------------------------------------------------------
Clock # Wage Hours Gross
----------------------------------------------------------
008898 100.00   1.0  100.00

Process finished with exit code 0
*/