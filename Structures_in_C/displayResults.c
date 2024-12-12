//**************************************************************
// Function: displayResults
//
// Purpose: Runs functions to obtain display outputs to standard out
//
// Parameters:      employeeData struct employee array - array containing employee structures
//                                                       used to store employee data
//
// Returns: Void
//
//**************************************************************

#include <stdio.h>
#include "employee.h"

void displayResults (struct employee employeeData[])
{
    printHeader ();
    printEmp (employeeData);
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
// Parameters:      employeeData struct employee array - array containing employee structures
//                                                       used to store employee data
//
// Returns: Nothing (call by reference)
//
//**************************************************************

void printEmp  (struct employee employeeData[])
{
    // access and print each employee
    for (int i = 0; i < SIZE; ++i)
    {
        printf("%06li\t\t%5.2f\t\t%5.2f\t\t%5.2f\t\t%5.2f\t\t%5.2f\t\t%8.2f\n", employeeData[i].clockNumber, employeeData[i].wageRate,
            employeeData[i].hours, employeeData[i].overtimeHrs, employeeData[i].normalPay, employeeData[i].overTimePay, employeeData[i].grossPay);
    } //for
} //printEmp
