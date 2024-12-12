class Math
{
    // private data numbers
    private:
    int num1;
    int num2;
    int num3;
    int num4;
    int num5;
    int num6;

    public:
        Math (int first, int second, int third, int fourth, int fifth, int sixth); // the class constructor
        int Largest (); // member to return the largest number
        int Smallest (); // member to return the smallest number
};

/**
Definitions for the class member functions follow.
The syntax of each of the member functions in the class is in the form:
<return type> <class name>::<function name> <function arguments>

There are two member functions. The first is a function automatically
called when you make an instance of the class. It is called a class
constructor and its job is to initialize the data in the class to the
values provided by the caller. Note that there is NEVER a return type
for a constructor.
The first member function is Math. Its job is to initialize the data
in the class to those values provided by whoever calls it. Note that
there are no defaults provided here, so all three values must be provided.
*/
Math::Math (int first, int second, int third, int fourth, int fifth, int sixth)
{
    num1 = first; // save the first int
    num2 = second ; // save the second int
    num3 = third; // save the third int
    num4 = fourth; //save the fourth and so on...
    num5 = fifth;
    num6 = sixth;

    return;
}

/*
The second member function is Largest. It examines the data held by the
class and returns the largest of the six data values.
*/

int Math::Largest ()
{
    int answer; // answer will be the largest we find

    answer = num1; // assume the first is the largest
    if (num2 > answer) // if the second number is larger
        answer = num2; // then update the answer
    if (num3 > answer) // now look at the third number
        answer = num3; // update the answer if we found a greater one
    if (num4 > answer)
        answer = num4;
    if (num5 > answer)
        answer = num5;
    if (num6 > answer)
        answer = num6;
    return answer; // return the answer to the caller
}

/*
The third member function is Smallest. It examines the data held by the
class and returns the smallest of the six data values.
*/
int Math::Smallest ()
{
    int answer; // answer will be the smallest we find

    answer = num1; // assume the first is the smallest
    if (num2 < answer) // if the second number is smallest
        answer = num2; // then update the answer
    if (num3 < answer) // now look at the third number
        answer = num3; // update the answer if we found a smaller one
    if (num4 < answer) // and so forth...
        answer = num4;
    if (num5 < answer)
        answer = num5;
    if (num6 < answer)
        answer = num6;
    return answer; // return the answer to the caller
}

#include <iostream>
using namespace std;
int main ()
{

    Math Object1 (10, 20, 30, 22, 11, 400); // The object type is Math
    Math Object2 (5, 10, 6, 22, 1, 10); // The object type is Math


    // use the cout object to print the information
    int solution;

    solution = Object1.Largest();
    cout << "Largest is " << solution << endl;

    solution = Object2.Smallest();
    cout << "Smallest is " << solution << endl;

    return 0;
}
