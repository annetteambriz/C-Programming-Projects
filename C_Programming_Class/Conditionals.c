//*******************************************************
//
// Assignment 3 - Conditionals
//
// Name: Annette Ambriz
//
// Class: C Programming, <replace with Semester and Year>
//
// Date: 09/26/2024
//
// Description: Program which determines overtime and
// gross pay for a set of employees with outputs sent
// to standard output (the screen).
//
//********************************************************

#include <stdio.h>

// Declare constants
#define STD_HOURS 40.0
#define NUM_EMPLOYEES 5
#define OVERTIME_RATE 1.5

int conditionals(void)
{
    printf ("\n*** Pay Calculator ***");

    // Process each employee
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        int clockNumber;     // Employee clock number
        float grossPay = 0;      // The weekly gross pay which is the normalPay + any overtimePay
        float hours;         // Total hours worked in a week
        float normalPay;     // Standard weekly normal pay without overtime
        float overtimeHrs = 0;   // Overtime hours worked beyond a normal week (40 hours)
        float overtimePay = 0;  // Any hours worked past the normal scheduled work week
        float wageRate;      // Hourly wage for an employee

        // Prompt the user for the clock number
        printf("\n\nEnter clock number: ");
        scanf("%d", &clockNumber);

        // Prompt the user for the wage rate
        printf("\nEnter wage rate: ");
        scanf("%f", &wageRate);

        // Prompt the user for the number of hours worked
        printf("\nEnter number of hours worked: ");
        scanf("%f", &hours);

        // Conditional check if overtime hours were worked
        if (hours > STD_HOURS) {
            // Calculate the overtime hours, normal pay, and overtime pay
            overtimeHrs = hours - STD_HOURS;
            overtimePay = OVERTIME_RATE * overtimeHrs * wageRate;
            normalPay = STD_HOURS * wageRate;
        } else {
            // Calculate the normal pay
            normalPay = hours * wageRate;
        }

        // Calculate the gross pay with normal pay and any additional overtime pay
        grossPay = normalPay + overtimePay;

        // Print out information on the current employee
        printf("\n\nClock#   Wage      Hours    OT     NormalPay   OverTimePay       GrossPay\n");
        printf("------------------------------------------------------------------------\n");
        printf("%06d   %5.2f   %5.1f   %5.1f     %5.2f     %5.2f          %8.2f\n",
                clockNumber, wageRate, hours, overtimeHrs, normalPay, overtimePay, grossPay);
    } // for

    return 0;
} // main
