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
 * Base Class - FileProcessor
 * ------------------------------------------------------------------------------------------------
 * @param: string inputFile, string outputFile
 * ************************************************************************************************/

class FileProcessor{
public:

    // Constructor
    FileProcessor();

    // Destructor
    ~FileProcessor();

    // Member functions/prototypes
    void processFile(string inputFile, string outputFile);
};
