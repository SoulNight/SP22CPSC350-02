/* ********************************************************************************
 * Tony Bautista
 * Spring 22 CPSC 350-02
 * February 24, 2022
 * Assignment 3
 * ---------------------------------------------------------------------------------
 * This program asks translates the user to input from American English stored in a
 * plain text file to Tutnese.
 * *********************************************************************************/


#include <string>

using namespace std;

/* ************************************************************************************************
 * Base Class - Translator
 * ------------------------------------------------------------------------------------------------
 * @param: string word, string sent
 * ************************************************************************************************/

class Translator{
public:

    // Constructor
    Translator();

    // Destructor
    ~Translator();

    // Member functions/prototypes
    string translateEnglishWord(string word);
    string translateEnglishSentence(string sent);
};
