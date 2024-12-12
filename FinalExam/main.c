//********************************************************
//
// Assignment: Final Exam
//
// Name: Annette Ambriz
//
// Class: C Programming, Fall 2024
//
// Description: This file contains answers to the final exam
//
// Date: 12/3/24
//********************************************************

#include <ctype.h> // isdigit function
#include <stdbool.h>
#include <stdio.h>
#include <string.h>    // string functions

// 1) (Macro) Write a macro for each of the following. DO NOT provide a function

#define TRIANGLE_PERIMETER(a, b, c) ((a) + (b) + (c))

/*
2) (C Function) Write a function definition which will determine how much money is in a jar that 
contains several coins, consisting of dollars, half-dollars, quarters, dimes, nickels, and pennies. 
Use the following to test your program, but your program should work for any amount of coins.

0 dollars, 11 half-dollars, 7 quarters, 3 dimes, 12 nickels, and 17 pennies (Answer: $8.32).
*/

// define constants
#define DOLLAR 1.00
#define HALF_DOLLAR 0.50
#define QUARTER 0.25
#define DIME 0.10
#define NICKEL 0.05
#define PENNY 0.01

double calcJarChangeTotal(int dollars, int halfDollars, int quarters, int dimes, int nickels, int pennies) {
    double total = 0;

    double totalDollars = dollars * DOLLAR;
    double totalHalfDollars = halfDollars * HALF_DOLLAR;
    double totalQuarters = quarters * QUARTER;
    double totalDimes = dimes * DIME;
    double totalNickels = nickels * NICKEL;
    double totalPennies = pennies * PENNY;

    total = totalDollars + totalHalfDollars + totalQuarters + totalDimes + totalNickels + totalPennies;

    printf("Total Jar Change: $%.2f\n", total);
    return total;
}

/*
3) (Function Definition) Write a function that takes the values of a two-card blackjack HAND as 
input, and returns the point total of the hand. The value of the cards '2' through '9' is equal to 
their face value, the cards 'T', 'K', 'Q', 'J' are worth 10 points and the ace ('A') is worth 11 
points unless it comes with another ace, then that second ace is worth 1 point. The program should 
be able to catch incorrect input. 

   Enter cards: A Q   
   The score is 21

   Enter cards: A A   
   The score is 12

   Enter cards: T 7   
   The score is 17

   Enter cards: A 5   
   The score is 16

   Enter cards: 7 #   
   *** Would be invalid, # is not a valid card

   Enter cards: Z 4   
   *** Would be invalid, Z is not a valid card

Hint:  I've used a value of 'T' for the 10 card so you can simply pass in two characters, 
       instead of strings, as parameters to this function.
*/

int blackJackValue (char card1, char card2);  /* prototype to get started */

// define constants
#define T_K_Q_J_A_CARD_VALUE 10

// define a flag for card1 is an A
bool card1IsA = false;

// **************************************************
// Function: getNonIntCardFaceValue
//
// Description: A helper function to calculate the card face value given a non digit card.
//
//
// Parameters:  card - char value representing a card.
//
// Returns:     int - Returns 10 value for 'T', 'K', 'J', 'Q' 'A'. Returns 0 for
//                      all other invalid chars
//
// ***************************************************
int getNonIntCardFaceValue (char card) {
    int cardValue = 0;

    // Check if card is a valid face card, if so assign value
    switch (card) {
        case 'T':
        case 'K':
        case 'J':
        case 'Q':
        case 'A':
            cardValue = T_K_Q_J_A_CARD_VALUE;
            break;

        // for all invalid card chars, card value is set to 0
        default:
            cardValue = 0;
            break;
    }
    return cardValue;
}

// **************************************************
// Function: getIntCardFaceValue
//
// Description: A helper function to calculate the card face value given a digit card.
//
//
// Parameters:  card - char value representing a card.
//
// Returns:     int - Returns digit value for numbers 2-9. Returns 0 for
//                    all other invalid card digits
//
// ***************************************************
int getIntCardFaceValue (char card) {
    int cardValue = 0;

    // Check if card is a legal card digit
    if (card > '1' && card <= '9') {
        // If so calculate card value using ASCII standard codes
        cardValue = card - '0';
    }
    return cardValue;
}

// **************************************************
// Function: blackJackValue
//
// Description: A function to calculate the blackJack hand value for two given chars
//              representing cards.
//
//
// Parameters:  card1 - char value representing a card.
//              card2 - char value representing a card.
//
// Returns:     int - Returns hand value for given cards.
//                    Returns 0 for invalid card(s).
//
// ***************************************************
int blackJackValue (char card1, char card2) {
    // Convert chars to upper
    char card1ToUpper = toupper(card1);
    char card2ToUpper = toupper(card2);

    // Create card array to process cards
    char cardArray[2] = { card1ToUpper, card2ToUpper };
    // Initialize variables
    int totalCardPoints = 0;
    int cardValue = 0;

    // Iterate through cards array
    for (int i = 0; i < 2; i++) {
        // Check if card is a number
        if (isdigit(cardArray[i])) {
            // Calculate digit card value
            cardValue = getIntCardFaceValue(cardArray[i]);
            // Check if digit is an invalid card value
            if (cardValue == 0) {
                printf("Invalid card value for card with digit: %d\n", cardArray[i]- '0');
                return 0;
            }
            // Else add card value to total
            totalCardPoints += cardValue;
        }
        // If card is not a digit
        else {
            // Get non digit card value
            cardValue = getNonIntCardFaceValue(cardArray[i]);

            // Check for invalid card value
            if (cardValue == 0) {
                printf("Invalid card value for card with ASCII code: %d\n", cardArray[i]);
                return 0;
            }
            // Else check if card1 is an A, if true set flag
            if (i == 0 && cardArray[0] == 'A') {
                card1IsA = true;
                totalCardPoints += cardValue;
            }
            // Check if card1 is an A and card2 is an A
            else if (card1IsA && cardArray[i] == 'A') {
                // If true set card2 A value to 1
                cardValue = 1;
                totalCardPoints += cardValue;
            }
            // All other valid card values with no special case
            else {
                totalCardPoints += cardValue;
            }
        }
    }
    printf("Total two-card BlackJack hand: %d\n", totalCardPoints);
    return totalCardPoints;
}


/*
 * 4) (Function Definition) Write a function to determine if a given word is legal. A word is
illegal if it contains no vowels. For this problem, the letter Y is considered to be a
legal vowel. Pass in a word to this function, and it will determine if the word is
legal or not. You can make the following assumptions about the word you a 
passing to this function.

         1) The string being passed is a combination of letters only (no non-letter check needed)
         2) The string being passed is null terminated
         3) Letters may be capital or lower case, and it has no effect on whether it's a word

          Examples:   

                sch  - is illegal, no vowels            
                apple - legal, contains a vowel 
                APPle - legal, uppercase letter combinations do not matter          
                try - legal, no vowel, but contains the letter 'y'
*/

// function prototype to get started, or better yet, use pointers
int isLegal (char theString[]);

// **************************************************
// Function: isLegal
//
// Description: A function to calculate if a given word is a "legal"
//              word. A word is legal if it contains a vowel or 'Y'.
//
//
// Parameters:  theString - char array representing a word.
//
//
// Returns:     int - Returns 1 for a true "isLegal" evaluation of the theString.
//                    Otherwise, returns 0 for an illegal word.
//
// ***************************************************
int isLegal (char theString[]) {
    int length = strlen(theString);

    for (int i = 0; i < length; i++) {
        char currentUpperCasedLetter = toupper(theString[i]);

        if (currentUpperCasedLetter == 'A' || currentUpperCasedLetter == 'E' || currentUpperCasedLetter == 'I' ||
            currentUpperCasedLetter == 'O' || currentUpperCasedLetter == 'U' || currentUpperCasedLetter == 'Y') {
            printf("Legal word, containing a vowel");
            return 1;
        }
    }
    printf("Illegal word, containing no vowel");
    return 0;
}

/*
5) (C Function) Write a function definition that will return in a structure the following characteristics of a given string:
*/
struct stringStats
{
    int stringLength;
    int upperCaseCount;
    int lowerCaseCount;
    int digitCount;
    int otherCharCount;
};

// function prototype to get started, or better, use pointers */
struct stringStats getStringStats (char theString[]);

// **************************************************
// Function: getStringStats
//
// Description: A function to calculate various stats about a given word.
//
//
// Parameters:  theString - char array representing a word.
//
//
// Returns:     stringStats struct - Returns a stringStats struct
//                          containing all the calculated stats for the word.
//
// ***************************************************
struct stringStats getStringStats (char theString[]) {
    struct stringStats string_stats = {0, 0, 0, 0, 0};

    // Iterate through theString array, until terminating char
    for (int i = 0; theString[i] != '\0'; i++) {
        // Increment string length with each char
        string_stats.stringLength++;

        if (isupper(theString[i])) {
            // Increment upperCaseCount if upper case
            string_stats.upperCaseCount++;
        } else if (islower(theString[i])) {
            // Increment lowerCaseCount if lower case
            string_stats.lowerCaseCount++;
        } else if (isdigit(theString[i])) {
            // Increment digitCount if is digit
            string_stats.digitCount++;
        } else {
            // Increment for all other characters
            string_stats.otherCharCount++;
        }
    }
    return string_stats;
}

/*
6) (C Function) Write a function that takes simple bets on horse races using the following rules 
that will return the number of dollars you won based on a specific bet from a specific house race.
*/
#define RACES 10
#define W_PAY_OUT_MULTIPLIER 5.0
#define P_PAY_OUT_MULTIPLIER 2.0
#define S_PAY_OUT_MULTIPLIER 1.5

// race results
struct raceResult
{
int raceNumber;           // The unique Race Number
int winningHorseNumber;   // 1st place horse number for the race
int placeHorseNumber;     // 2nd place horse number for the race
int showHorseNumber;      // 3rd place horse number for the race
};


// assume you can access this array that contains the results of horse races for a given day
struct raceResult theDailyResults[RACES];

// Struct representing your specific race wager
struct raceWager
{
    int raceNumber;      // the race number where you bet your horse
    int myHorseNumber;   // the horse you bet on
    float myBetAmount;   // how much money you are betting
    char betType;        // W for "Win", P for "Place", or S for "Show"
};

// **************************************************
// Function: determineWinnings
//
// Description: A helper function to calculate winnings based on a wager and
//              a race result.
//
//
// Parameters:  wager - a raceWager struct containing a horseNumber,
//                      bet amount and bet type used to determine winnings.
//              race - a raceResult struct containing winningHorseNumber,
//                      placeHorseNumber, and showHorseNumber
//
//
// Returns:     double - Returns value of winnings determined by bet type
//                       and winning horse place. Otherwise, returns 0 for an illegal bet.
//
// ***************************************************
double determineWinnings(struct raceWager wager, struct raceResult race) {
    double winning = 0;

    // Determine winnings based on the bet type
    switch (wager.betType) {
        // Winning bet
        case 'W':
            // Check if my horse is the winning horse
            if (wager.myHorseNumber == race.winningHorseNumber) {
                winning = wager.myBetAmount * W_PAY_OUT_MULTIPLIER;
            }
            break;

        // Place bet
        case 'P':
            // Check if my horse is the winning horse or the place horse
            if (wager.myHorseNumber == race.winningHorseNumber || wager.myHorseNumber == race.placeHorseNumber) {
                winning = wager.myBetAmount * P_PAY_OUT_MULTIPLIER;
            }
        break;

        // Show bet
        case 'S':
            // Check if my horse was the winning horse or the place horse or the show horse
            if (wager.myHorseNumber == race.winningHorseNumber || wager.myHorseNumber == race.placeHorseNumber ||
                wager.myHorseNumber == race.showHorseNumber) {
                winning = wager.myBetAmount * S_PAY_OUT_MULTIPLIER;
                }
        break;

        default:
            printf("Invalid bet type: %c\n", wager.betType);
            printf("Or race not found.");
    }
    return winning;
}

// **************************************************
// Function: myHorseBet
//
// Description: A function to calculate winnings based on a wager and
//              a race result.
//
//
// Parameters:  myBet - a raceWager struct containing a horseNumber,
//                      bet amount and bet type used to determine winnings.
//              theDailyResults - a raceResult struct array containing winningHorseNumber,
//                      placeHorseNumber, and showHorseNumber.
//
//
// Returns:     float -  Returns value of winnings determined by bet type
//                       Otherwise, returns 0 for an illegal bet or if race number is not found.
//
// ***************************************************
float myHorseBet (struct raceWager myBet, struct raceResult theDailyResults[]) {
    // Find the race result for my given bet's race number
    struct raceResult race = theDailyResults[myBet.raceNumber];

    // Calculate winnings
    double myWinnings = determineWinnings(myBet, race);

    return myWinnings;
}

/*
7) (C++ Program) In our lecture week that we covered C++, a class was created that would take 
three numbers, and called a member function named Largest that would return the largest of 
three numbers in a given object. Extend this C++ class so that:

a. The object will now contain 6 integer values instead of 3
b. The Largest member function will be updated to return the largest of 6 integer values
c. Add a new member function called Smallest that will return the smallest of 6 values
*/

/*
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


The second member function is Largest. It examines the data held by the
class and returns the largest of the six data values.


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


The third member function is Smallest. It examines the data held by the
class and returns the smallest of the six data values.

int Math::Smallest ()
{
    int answer; // answer will be the smallest we find

    answer = num1; // assume the first is the smallest
    if (num2 < answer) // if the second number is the smallest
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
*/

/*
8) (Code Segment)  Set up structures and reporting structures about race and horse 
details to support everything asked in question 8 (question 6?).

      // Add supporting structures - expect many structure types 
      // here ... 
*/
      struct date
      {
          int mouth;
          int day;
          int year;
      };

    struct trackDetails {
        char trackName[20];
        char city_Location[30];
        char state_Location[30];
        int length_of_track;
    };

    struct jockeyDetails {
        char name[20];
        int age;
        int weight;
        double height;
        int careerAge;
    };

  // add a structure to store details on each horse

    struct horse_details_and_past_performance
      {
        int programNumber;           // 1 - the program number
        char horseName[50];          // 8 - horse name
        char horseGender;            // 10 - gender of the horse
        int horseNumber;
        char horseBreed[20];
        int horseAge;
        int number_of_Winning_Wins;
        int number_of_placeWins;
        int number_of_showWins;
        struct jockeyDetails jockeys[10]; // Jockeys that have raced with the horse
        struct trackDetails tracks[40]; // Track locations the horse has raced
      };

    // add a structure to store details on each race
    struct race_details
    {
        struct date raceDate;                       // A - the date of the race
        int raceNumber;                             // C - the specific race number identifier
        struct trackDetails trackDetails;           // E - the name of the track where the race was held
        struct jockeyDetails jockeyDetails[15];                 // the Jockeys that raced
        struct horse_details_and_past_performance horses[15];       // the horses that raced
    };

      int main  (  )
      {

         // NOTE:  You don't have to populate any of these!!!
         //
         // struct customer myRaces[10];
         // struct book myHorses[20];

          // blackJackValue('A', '5');
          //
          // // 0 dollars, 11 half-dollars, 7 quarters, 3 dimes, 12 nickels, and 17 pennies (Answer: $8.32).
          // calcJarChangeTotal(0, 11, 7, 3, 12, 17);
          // char str1[5] = "try";
          // isLegal(str1);


         // nothing else needs to be added to main
         return (0);
      };
