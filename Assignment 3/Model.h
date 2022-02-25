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
 * Base Class - Model
 * ------------------------------------------------------------------------------------------------
 * @param: char c
 * ************************************************************************************************/

class Model{
public:

    // Constructor
    Model();

    // Destructor
    ~Model();

    // Member functions/prototypes
    string translateStringCharacter(char c);
    string translateDoubleCharacter(char c);
};
