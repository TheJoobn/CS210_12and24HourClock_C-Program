/* TITLE: 12 and 24 hour clock with menu. */

/* AUTHOR: Jaden B. Knutson - 3/16/2023 */

/* PROGRAM DESCRIPTION:  */
/* Chada Tech wants their clients to be able to view a 12- and a 24-hour clock on their website rather than just
the standard 12-hour clock. This program asks the user whther they want to input using regular or military time.
Inputs if its AM or PM if regular time is picked. Next, the is calculated and assigned a variable, along with
minute and second. A menu and a 12 and 24 hour clock will popup with the initial time entered. The user then enters
options from a the displayed menu that will either add time to the clock, or end the program. Users have an options 1-3 thatof add
1 second, 1 minute, or 1 hour to the current time on both clocks. Once a user is ready to end the program, they pick option 4.*/
/*--------------------------------------------------------*//*--------------------------------------------------------*/
/* Program Header */

#include <iostream>
#include <vector>
#include <sstream> 
#include <string>
using namespace std;


/*--------------------------------------------------------*/
/* GLOBAL VARIABLES */

/* Keep track of time in 24 hour format */
int currentHour = -1;
int currentMinute = -1;
int currentSecond = -1;

/* Boolean used to terminate the program if option 4 is picked from menu */
bool playAgain = true;


/* NOT CURRENTLY USED - used for display of menu*/
    //const char* strings[] = { "1. Add One Hour", "2. Add One Minute", "3. Add One Second", "4. Exit" };
    //unsigned int numStrings;
    //unsigned char width;


/*--------------------------------------------------------*/
/* Function Table of Contents and Early Initialization */

/* FUNCTIONS #1 - Time Getters */
int getHour(); /* Retrieves the current hour. */
int getMinute(); /* Retrieves the current minute. */
int getSecond(); /* Retrieves the current second. */

/* FUNCTIONS #2 - Time Setters */
void setHour(int hourS); /* Sets the new hour total. */
void setMinute(int minuteS); /* Sets the new minute total. */
void setSecond(int secondS); /* Sets the new second total. */

/* FUNCTIONS #3 - Time Adders */
void addOneHour(); /* Adds 1 hour to the time. */
void addOneMinute(); /* Adds 1 minute to the time. */
void addOneSecond(); /* Adds 1 second to the time. */

/* FUNCTIONS #4 - String Formatters */
string twoDigitString(unsigned int n);
string nCharString(size_t n, char c);
string formatTime24(unsigned int h, unsigned int m, unsigned int s); /* Formats string for 24 hour time. */
string formatTime12(unsigned int h, unsigned int m, unsigned int s); /* Formats string for 12 hour time. */

/* FUNCTIONS #5 - Time/Menu Input, Clock/Menu Output */
void inputClockType(); /* Inputs the current time in military or regular time. */
//void printMenu(char* strings[], unsigned int numStrings, unsigned char width); /* Outputs the menu, */ /*USING SUBSTITUTE*/
unsigned int getMenuChoice(unsigned int maxChoice); /* Inputs menu choices. */
void mainMenu(); /* Applys user choice for menu options. */
void displayClocks(unsigned int h, unsigned int m, unsigned int s); /* Outputs both 12 and 24 clocks. */

/* SUBSTITUTE for print menu function. */
void printMenuSub();

/*--------------------------------------------------------*//*--------------------------------------------------------*/
/*--------------------------------------------------------*/
/* END OF FUNCTION AND GLOBAL VARIABLE LIBRARY */






/* MAIN   MAIN   MAIN   MAIN   MAIN   MAIN   MAIN   MAIN */
/*--------------------------------------------------------*/
/*--------------------------------------------------------*/
/*--------------------------------------------------------*/
/*--------------------------------------------------------*/
/*--------------------------------------------------------*//*--------------------------------------------------------*/
/* START Main */
int main() {

    /* Inputs, validates, and assigns starter clock type and time: */
    /* (R)egular Time vs (M)ilitary TIme. AM vs PM. Number validation for hour, minute, second. */
    inputClockType();
    cout << endl;

    /* Outputs The Chosen Startin Times as 12 and 24 hour clocks.*/
    cout << "Chosen Starting Time." << endl;;
    displayClocks(currentHour, currentMinute, currentSecond);
    printMenuSub(); /* SIMPLE METHOD: Delete if solve correctly--------->*/

    /* The program runs until option 4 is chosen from menu. This turns playAgain to false. */
    while (playAgain == true) { /* false = program terminated. */
        mainMenu(); /* Opens menu where user can increment the 12 and 24 hour clocks. */
        printMenuSub(); /* SIMPLE METHOD: Delete if solve correctly--------->*/
        cout << endl;
    } /* END While */

    /* Goodbye Message Output. */
    cout << endl;
    cout << "Thank you for using this clock program. Have a nice day!" << endl;
    cout << endl;
    cout << "*PROGRAM TERMINATED*   Timestamp: (3/19/2023 12:44PM)" << endl;
    cout << endl;

} /*END Main*/





/*--------------------------------------------------------*//*--------------------------------------------------------*/
/*--------------------------------------------------------*/
/*--------------------------------------------------------*/
/*--------------------------------------------------------*/
/*--------------------------------------------------------*/
/* MAIN   MAIN   MAIN   MAIN   MAIN   MAIN   MAIN   MAIN */










/* FUNCTIONS #1:  getHour(),  getMinute(),  getSecond() */
/*--------------------------------------------------------*/
/*--------------------------------------------------------*//*--------------------------------------------------------*/
/* START getHour function */
int getHour() {
    return currentHour;
} /* END Function */



/*--------------------------------------------------------*/
/* START getMinute function */
int getMinute() {
    return currentMinute;
} /* END Function */



/*--------------------------------------------------------*/
/* START getSecond and setSecond functions */
int getSecond() {
    return currentSecond;
} /* END Function */



/*--------------------------------------------------------*//*--------------------------------------------------------*/
/*--------------------------------------------------------*/










/* FUNCTIONS #2:  setHour(),  setMinute(),  setSecond() */
/*--------------------------------------------------------*/
/*--------------------------------------------------------*//*--------------------------------------------------------*/
/* START setHour function*/
void setHour(int hourS) {
    currentHour = hourS; /* Increments hour by 1 hour. */
} /* END Function */



/*--------------------------------------------------------*/
/* START setMinute function*/
void setMinute(int minuteS) {
    currentMinute = minuteS; /* Increments hour by 1 minute. */
} /* END Function */



/*--------------------------------------------------------*/
void setSecond(int secondS) {
    currentSecond = secondS; /* Increments hour by 1 second. */
} /* END Function */



/*--------------------------------------------------------*//*--------------------------------------------------------*/
/*--------------------------------------------------------*/










/* FUNCTIONS #3:  addOneHour(),  addOneMinute(),  addOneSecond() */
/*--------------------------------------------------------*/
/*--------------------------------------------------------*//*--------------------------------------------------------*/
/* START addOneour() - Adds one hour to time */
void addOneHour() {

    /* Increments hour if in range. */
    if (getHour() < 23) {
        setHour(getHour() + 1);
    } /* END If */

    /* Otherwise hour is set to 0. */
    else {
        setHour(0);
    } /* END Else */
} /* END Function */





/*--------------------------------------------------------*/
/* START addOneMinute() - Adds one minute to time */
void addOneMinute() {

    /* Increments minute if in range. */
    if (getMinute() < 59) {
        setMinute(getMinute() + 1);
    } /* END If */

    /* Otherwise minute is set to 0 and add 1 to hour. */
    else {
        setMinute(0);
        addOneHour();
    } /* END Else */
} /* END Function */





/*--------------------------------------------------------*/
/* START addOneSecond() - Adds one second to time */
void addOneSecond() {

    /* Increments second if in range. */
    if (getSecond() < 59) {
        setSecond(getSecond() + 1);
    } /* END If */

    /* Otherwise second is set to 0 and add 1 to minute. */
    else {
        setSecond(0);
        addOneMinute();
    } /* END Else */
} /* END Function */





/*--------------------------------------------------------*//*--------------------------------------------------------*/
/*--------------------------------------------------------*/










/* FUNCTIONS #4:  twoDigitString(),  nCharString(),  formatTime24(),  formatTime12() */
/*--------------------------------------------------------*/
/*--------------------------------------------------------*//*--------------------------------------------------------*/
/* START twoDigitString() - WORKING (capitalize T at the end)*/
string twoDigitString(unsigned int n) {

    /* Variable */
    string strReturn = ""; /* Initializes string for twoDigResult. */

    /* Adds 0 in front of single digits, assigns double digits to string*/
    if (n < 10) { /* If number is less than 10, add a zero in front. */
        strReturn = "0" + to_string(n);
    } /* END if */
    else { /* Otherwise we just add n to string. */
        strReturn = to_string(n);
    } /* END Else */

    return strReturn; /* Returns a two digit string to twoDigResult*/
} /* END Function */





/*--------------------------------------------------------*/
/* START nCHarString() Function - */
string nCharString(size_t n, char c) {

    /* Variables */
    string charStrReturn = ""; /* Initializes return string to empty. */
    int i;

    /* START For - fills return string with speical character 'c' n amount of times. */
    for (i = 0; i < n; ++i) {
        charStrReturn += c;
    } /* END For */

    return charStrReturn; /* Returns the formated string*/
} /* END Function */





/*--------------------------------------------------------*/
/* START formatTime24() Function - Formats time in military format */
string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
    string time24Return = "";

    /* Formats return string in 24 hour clock format */
    time24Return = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s);

    return time24Return; /* Returns 24 hour time formated as hh:mm:ss*/
} /* END Function */





/*--------------------------------------------------------*/
/* START formatTime12() - Formats time in regular time */
string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
    string time12Return = "";

    /* Assigns hours 0 - 12 */
    if (h <= 12) {

        /* Special case hour 0: transforms to 12. */
        if (h == 0) { /* Military to regular time for hour 0 by adding 12. */
            time12Return += "12:"; /* Assigns hour to string*/
        } /* END If */
        /* Assigns hour less than 1-12 inclusive. */
        else if (h <= 12) {
            time12Return += twoDigitString(h) + ":";
        } /* END Else If*/

        /* Assigns minutes and seconds to string. */
        time12Return += twoDigitString(m) + ":";
        time12Return += twoDigitString(s);

        if (h == 12) { /* Speical case noon: Assigns PM. */
            time12Return += " P M";
        } /* END If */
        else { /* Otherwise assigns AM for the rest. */
            time12Return += " A M";
        } /* END Else */
    } /* END If */


    /* Assigns hours 13 - 24, converts from military time. */
    else {
        /* Military to regular time by subtracting 12. */
        time12Return += twoDigitString(h - 12) + ":";

        /* Assigns minutes and seconds to string. */
        time12Return += twoDigitString(m) + ":";
        time12Return += twoDigitString(s);
        time12Return += " P M"; /* Assigns PM */
    } /* END Else */

    return time12Return; /* Returns 12 hour time formated as hh:mm:ss*/
} /* END Function */
/*--------------------------------------------------------*//*--------------------------------------------------------*/
/*--------------------------------------------------------*/










/* FUNCTIONS #5:  inputClockType(),  printMenu(),  getMenuChoice(),  mainMenu(),  displayClocks() */
/*--------------------------------------------------------*/
/*--------------------------------------------------------*//*--------------------------------------------------------*/
/* START inputClockType() - (R)egular or (M)ilitary,  AM or PM,  Time Input. */
void inputClockType() {

    /* Local variables for input choices, Regular vs Military Time, AM vs PM */
    string userAMorPM = "";
    string userClockChoice = "";

    /* Booleans for Input Validation */
    bool correctClock = false;  /* Input must be:  r,  R,  m,  M. */
    bool correctAMorPM = false;  /* Input must be AM or PM, hour must be in range. */
    bool correctMinute = false;  /* Input minute must be in range. */
    bool correctSecond = false;  /* Input second must be in range. */

    /* Outputs question for Regular or Military Time. */
    cout << "Do you prefer to use (R)egular Time or (M)ilitary Time? " << endl;;

    /* Input must be:  r,  R, for Regular Time   or   m,  M, for Military Time */
    while (correctClock == false) { /* Input validation. */
        cout << "Enter R for Regular or M for Military:  ";
        cin >> userClockChoice; /* Input check for Clock Type. */
        if (userClockChoice == "R" || userClockChoice == "M" || userClockChoice == "r" || userClockChoice == "m") {
            correctClock = true;
        } /* END If */

    } /* END While */
    cout << endl;

    /* User Chooses Regular Time - If input is R, input using Regular Time. */
    if (userClockChoice == "R" || userClockChoice == "r") {
        cout << "You have chosen Regular Time." << endl;

        /* Input Validation for AM or PM */
        while (correctAMorPM == false) {
            cout << "Enter whether it's AM or PM: "; /* Asks for AM vs PM Input */
            cin >> userAMorPM;


/*COULD BE SEPERATE FUNCTION*/ /*COULD BE SEPERATE FUNCTION*/ /*COULD BE SEPERATE FUNCTION*/

            /* User chooses AM - If input is AM, Input using AM Hours. */
            if (userAMorPM == "AM" || userAMorPM == "am") {
                cout << endl;

                /* Input Validation AM Hours. */
                while (currentHour > 12 || currentHour < 1) {
                    cout << "Step 1. Enter the current hour (1-12): "; /* Asks for Hour Input */
                    cin >> currentHour; /* Inputs AM Clock Hour */
                } /* END While */

                /* Special case for 12 AM conversion to 24 Hour Time */
                if (currentHour == 12) {
                    currentHour -= 24; /* Converts 12 AM to 0. */
                    correctAMorPM = true;
                } /* END If */
                else { /* Catches most cases, subtracts 12 hours.  */
                    currentHour -= 12;
                    correctAMorPM = true;
                } /* END Else */
            } /* END If */


/*COULD BE SEPERATE FUNCTION*/ /*COULD BE SEPERATE FUNCTION*/ /*COULD BE SEPERATE FUNCTION*/

     /* User chooses PM - If input is PM, Input using PM Hours. */
            else if (userAMorPM == "PM" || userAMorPM == "pm") {
                cout << endl;

                /* Input Validation PM Hours. */
                while (currentHour > 12 || currentHour < 1) {
                    cout << "Step 1. Enter the current hour (1-12): "; /* Asks for Hour Input */
                    cin >> currentHour; /* Inputs PM Clock Hour */
                } /* END While */

                /* Special case for 12 PM conversion to 24 Hour Time */
                if (currentHour == 12) {
                    currentHour -= 12; /* Converts 12 PM to 12. */
                    correctAMorPM = true;
                } /* END If */
                else { /* Catches most cases, no conversion */
                    correctAMorPM = true;
                } /* END Else */
            } /* END If */
        } /* END While */
        currentHour += 12;
        cout << endl;
    } /* END If */


/*COULD BE SEPERATE FUNCTION*/ /*COULD BE SEPERATE FUNCTION*/ /*COULD BE SEPERATE FUNCTION*/

 /* User Chooses Military Time - If input is M, input hour in military time.*/
    else if (userClockChoice == "M" || userClockChoice == "m") {
        cout << "You have chosen Military Time." << endl;

        while (currentHour > 23 || currentHour < 0) {
            cout << "Step 1. Enter the current hour (0-23): "; /* Asks for Hour Input */
            cin >> currentHour; /* Inputs Militaty Clock Hour */

        } /* END While */
    } /* END If */
    cout << endl;


/*COULD BE SEPERATE FUNCTION*/ /*COULD BE SEPERATE FUNCTION*/ /*COULD BE SEPERATE FUNCTION*/

    /* Input Validation for Input Minute. */
    while (correctMinute == false) {
        cout << "Step 2. Enter the current minute (0-59): "; /* Asks for Minute Input */
        cin >> currentMinute; /* Inputs Clock Minute */

        /* Checks if Minute Input is in Range */
        if (currentMinute <= 59 && currentMinute >= 0) {
            correctMinute = true;
        } /* END If */
    } /* END While */
    cout << endl;

    /* Input Validation for Input Second. */
    while (correctSecond == false) {
        cout << "Step 3. Enter the current second (0-59): "; /* Asks for Second Input */
        cin >> currentSecond; /* Inputs Clock Second */

        /* Checks if Second Input is in Range */
        if (currentSecond <= 59 && currentSecond >= 0) {
            correctSecond = true;
        }/* END If */
    } /* END While */
    cout << endl;
    return; /* Not needed */
} /* END Function */





/*--------------------------------------------------------*//*--------------------------------------------------------*/
/* START getMenuChoice Function - Gets user input for menu choice */
unsigned int getMenuChoice(unsigned int maxChoice) {

    /* Return Variable Initialization. */
    unsigned int choiceReturn = 0;

    /*START while - Asks until acceptable answer is input: "1-4" */
    while (choiceReturn < 1 || choiceReturn > maxChoice) { /* Input validation. */
        cout << "Enter a menu choice 1-4: "; /* Asks user for menu number input. */
        cin >> choiceReturn; /* Inputs choice number. */
        cout << endl;
        cout << endl;
    } /* END while */

    return choiceReturn; /* Returns user choice number. */
} /* END Function */

         /* Gets menu choice 1 through maxChoice, inclusive
         * @param maxChoice, maximum choice index, a number between 2 and 9, inclusive
         * @return the first legal choice input, could be 1 through maxChoice, inclusive*/




/*--------------------------------------------------------*//*--------------------------------------------------------*/
/* START mainMenu Function - Uses user menu choice to increment time or end program. */
void mainMenu() {
    int menuResult = getMenuChoice(4);

    while (playAgain != false) {

        /* Option One adds 1 hour to time. */
        if (menuResult == 1) {
            addOneHour();
            break;
        } /* END If */

        /* Option Two adds 1 minute to time. */
        else if (menuResult == 2) {
            addOneMinute();
            break;
        } /* END Else If*/

        /* Option Three adds 1 second to time. */
        else if (menuResult == 3) {
            addOneSecond();
            break;
        } /* END Else If*/

        /* Option Four terminates program. */
        else if (menuResult == 4) {
            playAgain = false;
            break;
        } /* END Else If*/

        /* Input Validation for user menu choice. */
        else {
            cout << "Input Error.";
        } /* END Else If */

    } /* END While */
    cout << "Time after choosing: Option " << menuResult << endl;; /* Outputs user choice. */
    displayClocks(currentHour, currentMinute, currentSecond); /* Outputs 12/24 clock with new time. */
} /* END Function */





/*--------------------------------------------------------*//*--------------------------------------------------------*/
/* START displayClocks Function - Ouputs clock in 12 and 24 hour time. (SIMPLE CHEATER SUBSTITUTE JUST IN CASE)*/
void displayClocks(unsigned int h, unsigned int m, unsigned int s) {
    cout << nCharString(26, '*') << nCharString(3, ' ') << nCharString(26, '*') << endl; /* Creates top row of stars*/
    cout << "*" << nCharString(6, ' ') << "12-Hour Clock" << nCharString(5, ' ') << "*" << nCharString(3, ' ');
    cout << "*" << nCharString(6, ' ') << "24-Hour Clock" << nCharString(5, ' ') << "*" << endl;
    cout << endl;
    cout << "*" << nCharString(6, ' ') << formatTime12(h, m, s) << nCharString(6, ' ') << "*" << nCharString(3, ' ');
    cout << "*" << nCharString(8, ' ') << formatTime24(h, m, s) << nCharString(8, ' ') << "*" << endl;
    cout << nCharString(26, '*') << nCharString(3, ' ') << nCharString(26, '*') << endl;
} /* END Function */





/*--------------------------------------------------------*//*--------------------------------------------------------*/
/* START printMenuSub() - SIMPLE METHOD - Outputs a menu of options*/

void printMenuSub() {
    //for (unsigned int i = 0; i < numStrings; ++i) {
        //cout << nCharString(numStrings-width , width) << endl; 
        //cout << nCharString(numStrings, width) << "1 - Add One Hour";

    //cout << nCharString(numStrings, width) << endl;;
    cout << nCharString(26, '*') << endl;
    cout << nCharString(1, '*') << "  1 - Add One Hour " << nCharString(5, ' ') << nCharString(1, '*') << endl;
    cout << endl;
    cout << nCharString(1, '*') << "  2 - Add One Minute " << nCharString(3, ' ') << nCharString(1, '*') << endl;
    cout << endl;
    cout << nCharString(1, '*') << "  3 - Add One Second " << nCharString(3, ' ') << nCharString(1, '*') << endl;
    cout << endl;
    cout << nCharString(1, '*') << "  4 - Exit Program " << nCharString(5, ' ') << nCharString(1, '*') << endl;
    cout << nCharString(26, '*') << endl;
} /* END Function */





/*--------------------------------------------------------*//*--------------------------------------------------------*/
/* NOT WORKING - START printMenu() - Outputs a menu of options */
//void printMenu(char* strings[], unsigned int numStrings, unsigned char width) {

    //for (unsigned int i = 0; i < numStrings; ++i) {
        //cout << strings[i] << nCharString(width - strlen(strings[i]), ' ') << endl;
    //}

//} /* END Function */


// test cases (["Add One Hour", "Add One Minute", "Add One Second", "Exit Program"], 4, 26 or 57)
 /* Prints menu
 * @param *strings[], nonempty array of choices
 * @param width, width of each line, will be comfortably bigger than the longest string

     * In your own program feel free to change the function signature. For now, please first get it to work as is.
     * You may assume <string> and <iostream> have been imported.
     * You may assume a function nCharString has been implemented, and you will want to call it for stars and spaces.
     * string nCharString(size_t n, char c) produces a string of n c's. For example, nCharString(5, '*') returns "*****"
     * and nCharString (7,' ') will return 7 spaces.
     */
     // TODO: Your code here. Use the comments to see the expected format of the menu.

     // first print width *'s followed by an endl

     /** Next, for each string s in the array:
      * cout a star, a space, the item Number a space a hyphen another space, s,
      * and enough spaces to get to a length of width - 1 (enough will depend on the length of the current menu item).

      * Close the line with a star and an endl. The goal is that the stars on the right align with each other and each line
      * has the same width, passed in as a parameter.
      * (Hint: calculate the needed number of spaces and use nCharString to produce them)
      * Skip a line after each line except the last line
      */

      // outside the loop print another width *s followed by an endl

/*--------------------------------------------------------*//*--------------------------------------------------------*/
/*--------------------------------------------------------*/
/* END OF PROGRAM FUNCTIONS*/






















/* INDIVIDUAL TEST CASES */
/*--------------------------------------------------------*//*--------------------------------------------------------*/
/*--------------------------------------------------------*/
    /* DISPLAY CLOCKS FUNCTION CALL 12 AND 24*/
    /*--------------------------------------------------------*/
    //cout << "hello from main Display clocks" << endl;
    //cout << "clock from main.cpp : " << endl;
    //displayClocks(currentHour, currentMinute, currentSecond);
    //cout << endl;
    /*--------------------------------------------------------*/
     /*DONE DONE DONE DONE DONE DONE DONE DONE*/



        /* 24 HOUR CONVERSION FUNCTION CALL */
    /*--------------------------------------------------------*/
    /* format time to 24 hour military time */
    //string time24Result = formatTime24(currentHour, currentMinute, currentSecond);
    //cout << "time24Result is: " << time24Result << endl;
    //cout << endl;
    /*--------------------------------------------------------*/
    /* DONE FOR NOW */



     /* 12 HOUR CONVERSION FUNCTION CALL */
    /*--------------------------------------------------------*/
    /* format time to 12 hour time */
    //string time12Result = formatTime12(currentHour, currentMinute, currentSecond);
    //cout << "time12Result is: " << time12Result << endl;
    //cout << endl;
    /*--------------------------------------------------------*/
     /* DONE FOR NOW */



    /* TWO DIGIT RETURN FUNCTION CALL */
    /*--------------------------------------------------------*/
    /*two digit fucntion call*/
   // string twoDigResult = twoDigitString(12);
   // cout << "hello from main two digit" << endl;
  //  cout << "twoDigResult is: " << twoDigResult << endl;
   // cout << endl;
    /*--------------------------------------------------------*/
    /*DONE DONE DONE DONE DONE DONE DONE DONE*/



    /* SPECIAL CHARACTER FORMATTING FUNCTION CALL */
    /*--------------------------------------------------------*/
    /* formatting symbol function call */
  //  string nCharResult = nCharString(5, '*');
   // cout << "hello from main n char" << endl;
   // cout << "nCharResult is: " << nCharResult << endl;
   // cout << endl;
    /*--------------------------------------------------------*/
    /*DONE DONE DONE DONE DONE DONE DONE DONE*/



    /* /* ILLUSTRATED MENU FUNCTION CALL */ /*PLEASE FIX ME*/
    /*--------------------------------------------------------*/

    //string menuResult = printMenu();
    //cout << "hello from main MAIN (MENU)" << endl;
    //cout << "menuResult is: " << menuResult << endl;
    //cout << endl;
    //printMenu([, 5, 5);
    /*--------------------------------------------------------*/
     /* NOT NOT NOT */



    /* MAIN MENU CHOICE 1-4*/
    /*--------------------------------------------------------*/
  //  cout << "hello from main menu choice" << endl;
   // int menuResult = getMenuChoice(4);
   // cout << "menuResult is : " << menuResult << endl;
   // cout << endl;
    /*--------------------------------------------------------*/
     /*DONE DONE DONE DONE DONE DONE DONE DONE*/




/*--------------------------------------------------------*//*--------------------------------------------------------*/
/*--------------------------------------------------------*/
