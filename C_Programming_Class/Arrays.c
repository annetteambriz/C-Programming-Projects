//*******************************************************
//
// Assignment 4 - Arrays
//
// Name: Annette Ambriz
//
// Class: C Programming, Fall 2024
//
// Date: 10/1/2024
//
// Description: Program which determines overtime and
// gross pay for a set of employees with outputs sent
// to standard output (the screen).
//
//********************************************************
#include <stdio.h>
// Constants
#define SIZE 5 // number of employees to process
#define STD_HOURS 40.0 // normal work week hours before overtime
#define OT_RATE 1.5 // time and half overtime setting

int arrays() {

    // Declare variables needed for the program
    long int clockNumber [SIZE]; // unique employee identifier
    float grossPay [SIZE]; // weekly gross pay - normal pay + overtimepay
    float hours [SIZE]; // hours worked in a given week
    float normalPay [SIZE]; // normal weekly pay without any overtime
    float overtimeHrs[SIZE]; // overtime hours worked in a given week
    float overtimePay [SIZE]; // overtime pay for a given week
    float wageRate [SIZE]; // Hourly pay for each employee

    // Variables to store totals and averages
    float totalGrossPay = 0.0;
    float totalHours = 0.0;
    float totalNormalPay = 0.0;
    float totalOvertimePay = 0.0;
    float totalWageRate = 0.0;

    float averageGrossPay = 0.0;
    float averageHours = 0.0;
    float averageNormalPay = 0.0;
    float averageOvertimePay = 0.0;
    float averageWageRate = 0.0;


    printf ("\n*** Pay Calculator ***\n");
    // Process each employee one at a time
    for (int i = 0; i < SIZE; i++)
    {
        // Prompt the user for the clock number
        printf("\nEnter clock number: ");
        scanf("%li", &clockNumber[i]);

        // Prompt the user for the wage rate
        printf("Enter wage rate: ");
        scanf("%f", &wageRate[i]);

        // Prompt the user for the number of hours worked
        printf("Enter number of hours worked: ");
        scanf("%f", &hours[i]);

        // Conditional check if overtime hours were worked
        if (hours[i] >= STD_HOURS)
        {
            // Calculate arrays normalPay and overtimePay
            overtimeHrs[i] = hours[i] - STD_HOURS;
            overtimePay[i] = OT_RATE * overtimeHrs[i] * wageRate[i];
            normalPay[i] = STD_HOURS * wageRate[i];
            }
        else
        {
            // Calculate arrays normalPay
            overtimeHrs[i] = 0;
            overtimePay[i] = 0;
            normalPay[i] = hours[i] * wageRate[i];
            }
        // Calculate Gross Pay
        grossPay[i] = normalPay[i] + overtimePay[i];

        // Calculate totals
        totalWageRate = totalWageRate + wageRate[i];
        totalHours = totalHours + hours[i];
        totalOvertimePay = totalOvertimePay + overtimePay[i];
        totalNormalPay = totalNormalPay + normalPay[i];
        totalGrossPay = totalGrossPay + grossPay[i];

        // Calculate averages
        averageWageRate = totalWageRate / SIZE;
        averageHours = totalHours / SIZE;
        averageOvertimePay = totalOvertimePay / SIZE;
        averageNormalPay = totalNormalPay / SIZE;
        averageGrossPay = totalGrossPay / SIZE;
    }

    // A nice table header
    printf("\n------------------------------------------------------------------------");
    printf("\nClock#   Wage      Hours    OT    NormalPay   OverTimePay  GrossPay");
    printf("\n------------------------------------------------------------------------\n");

    for (int i = 0; i < SIZE; i++)
    {
        printf("%06li   ", clockNumber [i]);
        printf("%5.2f   ", wageRate [i]);
        printf("%5.2f   ", hours [i]);
        printf("%5.2f   ", overtimeHrs [i]);
        printf("%5.2f   ", normalPay [i]);
        printf("%5.2f    ", overtimePay [i]);
        printf("%8.2f     \n", grossPay [i]);
    }
    // Print averages and totals
    printf("------------------------------------------------------------------------\n");
    printf("Total    ");
    printf("%5.2f   ", totalWageRate);
    printf("%5.2f   ", totalHours);
    printf("%5.2f   ", totalOvertimePay);
    printf("%5.2f   ", totalNormalPay);
    printf("%5.2f   ", totalOvertimePay);
    printf("%5.2f   ", totalGrossPay);

    printf("\nAverage  ");
    printf("%5.2f   ", averageWageRate);
    printf("%5.2f   ", averageHours);
    printf("%5.2f   ", averageOvertimePay);
    printf("%5.2f   ", averageNormalPay);
    printf("%5.2f   ", averageOvertimePay);
    printf("%5.2f   ", averageGrossPay);

    return(0);
}