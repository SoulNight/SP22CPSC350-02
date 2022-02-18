/* ********************************************************************************
 * Tony Bautista
 * Spring 22 CPSC 350-02
 * February 17, 2022
 * Assignment 2
 * ---------------------------------------------------------------------------------
 * This program asks the user to input any letter or set of letters, and any non
 * letter. The program will output the letter count, how many alphabet letters, how
 * many non-alphabets, the average letters, and how many pairs of letters.
 * *********************************************************************************/

#include "parse.h"
using namespace std;

int main()
{
    Parser parse; // object creation

    parse.requestInput(); // function call
    parse.parseAlphabet(); // function call
    parse.parseNonAlphabet(); // function call
    parse.outputToConsole(); // function call
    parse.save("Output.txt"); // function call - saving to file

    return 0;
}
