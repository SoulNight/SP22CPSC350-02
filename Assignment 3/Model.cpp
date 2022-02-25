/* ********************************************************************************
 * Tony Bautista
 * Spring 22 CPSC 350-02
 * February 24, 2022
 * Assignment 3
 * ---------------------------------------------------------------------------------
 * This program asks translates the user to input from American English stored in a
 * plain text file to Tutnese.
 * *********************************************************************************/

#include "Model.h"
#include <string>
using namespace std;

// Constructor - Model
Model::Model() {
  bool isVowel = false;
}

// Destructor - Model
Model::~Model() {

}

/* ************************************************************************************************
 * Implementation of a member function - translateStringCharacter
 * ------------------------------------------------------------------------------------------------
 * This function translates the characters of the sentence into the perspective letter, and word
 * ------------------------------------------------------------------------------------------------
 * Function has 1 @param: char C
 * Returns: proper letter or word
 * ************************************************************************************************/

string Model::translateStringCharacter(char c){

    // switch statement that translates every letter of the sentence
    switch(c)
    {
        case 'a':
            return "a";
            break;
        case 'A':
            return "A";
            break;
        case 'b':
            return "bub";
            break;
        case 'B':
            return "Bub";
            break;
        case 'c':
            return "cash";
            break;
        case 'C':
            return "Cash";
            break;
        case 'd':
            return "dud";
        case 'D':
            return "Dud";
            break;
        case 'e':
            return "e";
            break;
        case 'E':
            return "E";
            break;
        case 'f':
            return "fuf";
            break;
        case 'F':
            return "Fuf";
            break;
        case 'g':
            return "gug";
            break;
        case 'G':
            return "Gug";
            break;
        case 'h':
            return "hash";
            break;
        case 'H':
            return "Hash";
            break;
        case 'i':
            return "i";
            break;
        case 'I':
            return "I";
            break;
        case 'j':
            return "jay";
            break;
        case 'J':
            return "Jay";
            break;
        case 'k':
            return "kuk";
            break;
        case 'K':
            return "Kuk";
            break;
        case 'l':
            return "lul";
            break;
        case 'L':
            return "Lul";
            break;
        case 'm':
            return "mum";
            break;
        case 'M':
            return "Mum";
            break;
        case 'n':
            return "nun";
            break;
        case 'N':
            return "Nun";
            break;
        case 'o':
            return "o";
            break;
        case 'O':
            return "O";
            break;
        case 'p':
            return "pub";
            break;
        case 'P':
            return "Pub";
            break;
        case 'q':
            return "quack";
            break;
        case 'Q':
            return "Quack";
            break;
        case 'r':
            return "rug";
            break;
        case 'R':
            return "Rug";
            break;
        case 's':
            return "sus";
            break;
        case 'S':
            return "Sus";
            break;
        case 't':
            return "tut";
            break;
        case 'T':
            return "Tut";
            break;
        case 'u':
            return "u";
            break;
        case 'U':
            return "U";
            break;
        case 'v':
            return "vuv";
            break;
        case 'V':
            return "Vuv";
            break;
        case 'w':
            return "wack";
            break;
        case 'W':
            return "Wack";
            break;
        case 'x':
            return "ex";
            break;
        case 'X':
            return "Ex";
            break;
        case 'y':
            return "yub";
            break;
        case 'Y':
            return "Yub";
            break;
        case 'z':
            return "zub";
            break;
        case 'Z':
            return "Zub";
            break;
    }
    return 0;
}
/* ************************************************************************************************
 * Function  - translateDoubleCharacter
 * ------------------------------------------------------------------------------------------------
 * This function checks whether the letter in sentence is a vowel, then an if statement is used to
 * check if the letter is upper or lowercase. The if statement the returns the proper translation
 * of Squat, squat, squa, Squa.
 * ------------------------------------------------------------------------------------------------
 * Function has 1 @param: char C
 * Returns: consonants and vowel translation of string characters
 * ************************************************************************************************/

string Model::translateDoubleCharacter(char c)
{
    bool isVowel; //set to false in constructor

    switch (c)
    {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
            isVowel = true;
            break;
        default:
            isVowel = false;
            break;
    }


// If Statement for double letters of vowels and consonants
    if(isVowel){ // if vowel is true, return needed output + calling function translateStringCharacter for proper output
        if(isupper(c))
        {
            return ("Squat" + translateStringCharacter(c));// Upper case output for double vowels
        }
        else
        {
            return ("squat" + translateStringCharacter(c)); // else for lower case output of double vowels
        }
    }
    else // if consonant, return needed output + calling function translateStringCharacter for proper output
    {
        if(isupper(c))
        {
            return ("Squa" + translateStringCharacter(c)); // Upper case output for double consonants
        }
        else
        {
            return ("squa" + translateStringCharacter(c)); // else for lower case output for lower case consonants
        }
    }
}
