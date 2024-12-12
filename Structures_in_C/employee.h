// Constants
#define SIZE 2
#define OVERTIME_RATE 1.5f
#define STD_WORK_WEEK 40.0f

// Define a global structure to pass employee data between functions
// Note that the structure type is global, but you don't want a variable
// of that type to be global. Best to declare a variable of that type
// in a function like main or another function and pass as needed.
struct employee {
    long int clockNumber;
    float wageRate;
    float hours;
    float normalPay;
    float overtimeHrs;
    float overTimePay;
    float grossPay;
};

// Function prototypes
// Process inputs
void processInput (struct employee employeeData[]);
int long getClockNumber ();
float getHours ();
float getWageRate ();

// Calculate outputs
void calculateOutputs (struct employee employeeData[]);
int calculateOverTime (float hours);
float calculateOverTimePay (float wageRate, float overTimeHours);
float calculateRegularPay (float wageRate);

// Display outputs
void displayResults (struct employee employeeData[]);
void printHeader (void);
void printEmp  (struct employee employeeData[]);