/* ********************************************************************************
 * Tony Bautista
 * Spring 22 CPSC 350-02
 * February 24, 2022
 * Assignment 3
 * ---------------------------------------------------------------------------------
 * This program asks translates the user to input from American English stored in a
 * plain text file to Tutnese.
 * *********************************************************************************/

#include "Translator.h"
#include "Model.h"

// Constructor - initialization of member variables
Translator::Translator(){
  string checkLetter = "";
  string sentence = "";
  string word = "";
}

// Destructor
Translator::~Translator(){

}

/* ************************************************************************************************
 * Implementation of a member function - translateEnglishWord - from Translator
 * ------------------------------------------------------------------------------------------------
 * This function checks each letter of the word
 * ------------------------------------------------------------------------------------------------
 * Function has 1 @param: string word
 * return value and type - checkLetter and type string
 * ************************************************************************************************/

// Function - checks each letter of the word
string Translator::translateEnglishWord(string word){

    // Object creation
    Model model; // this is object of Model class to use translate functions

    string checkLetter; // variable

    for(int i = 0; i < word.length(); i++ )
    {
        if(word[i] != word[i + 1])
        {
            checkLetter += model.translateStringCharacter(word[i]);
        }
        else
        {
            checkLetter += model.translateDoubleCharacter(word[i]);
            ++i;
        }
    }
    return checkLetter;
}


/* ************************************************************************************************
 * Implementation of a member function - translateEnglishSentence - from Translator
 * ------------------------------------------------------------------------------------------------
 * This function extracts each word in the sentence then calls above function translateEnglishWord
 * ------------------------------------------------------------------------------------------------
 * Function has 1 @param: string sent
 * return value and type - string and type string
 * ************************************************************************************************/

string Translator::translateEnglishSentence(string sent){

    // Declaration - variables
    string sentence;
    string word;
    char c;

    // For loop - checks to see if the letter is alphabet
    for(char c: sent)
    {
        if(!(isalpha(c)))
        {
            sentence += translateEnglishWord(word) + " ";
            word = "";
        }
        else
        {
            word += c;
        }
    }

    sentence += translateEnglishWord((word));

    return sentence;
}
