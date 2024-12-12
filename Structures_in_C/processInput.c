//**************************************************************
// Function: processInput
//
// Purpose: Runs functions to obtain input from user
//
// Parameters: employeeData struct employee array - array containing employee structures
//                                                  used to store employee data
//
// Returns: Void
//
//**************************************************************

#include <stdio.h>
#include "employee.h"

void processInput (struct employee employeeData[])
{
    // Process each employee one at a time
    for (int i = 0; i < SIZE; i++) {

        // Call getClockNumber to get employee number
        employeeData[i].clockNumber = getClockNumber();

        // Call getWageRate to get the wage rate
        employeeData[i].wageRate = getWageRate();

        // Call getHours for the number of hours worked
        employeeData[i].hours = getHours();
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
