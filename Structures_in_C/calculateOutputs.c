//**************************************************************
// Function: calculateOutputs
//
// Purpose: Runs functions to calculate outputs of the program. Uses the number of
// hours worked to calculate the normalPay, overTimePay, grossPay per employee.
//
// Parameters:      employeeData struct employee array - array containing employee structures
//                                                       used to store employee data
//
// Returns: Void
//
//**************************************************************

#include "employee.h"

void calculateOutputs (struct employee employeeData[])
{
    // Calculate output values for each employee one at a time
    for (int i = 0; i < SIZE; i++)
    {
        // Call function to calculate overtimeHrs
        employeeData[i].overtimeHrs = calculateOverTime(employeeData[i].hours);

        // Call function to calculate normalPay
        employeeData[i].normalPay = calculateRegularPay(employeeData[i].wageRate);

        // Call function to calculate overTimePay
        employeeData[i].overTimePay = calculateOverTimePay(employeeData[i].wageRate, employeeData[i].overtimeHrs);

        // Calculate gross pay
        employeeData[i].grossPay = employeeData[i].normalPay + employeeData[i].overTimePay;
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
