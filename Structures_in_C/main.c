/*********************************************************************
**
** HOMEWORK: #6 Structures
**
** Name: Annette Ambriz
**
** Class: C Programming
**
** Date: 10/17/2024
**
** Description: This program prompts the user for the number of hours
** worked for each employee. It then calculates gross pay
** including overtime and displays the results in table. Functions
** and structures are used.
**
** Call by Value design
**
/**********************************************************************/

#include <stdio.h>
#include "employee.h"

int main ()
{
    // Set up a local variable to store the employee information
    struct employee employeeData[SIZE];

    printf ("\n*** Pay Calculator ***\n");

    // Call worker bee function to process input
    processInput(employeeData);

    // Call worker bee function to calculate outputs
    calculateOutputs(employeeData);

    // Call worker bee function to display outputs
    displayResults(employeeData);

    return 0;
}  // main