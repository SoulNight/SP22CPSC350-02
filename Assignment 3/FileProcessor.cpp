/* ********************************************************************************
 * Tony Bautista
 * Spring 22 CPSC 350-02
 * February 24, 2022
 * Assignment 3
 * ---------------------------------------------------------------------------------
 * This program asks translates the user to input from American English stored in a
 * plain text file to Tutnese.
 * *********************************************************************************/

#include "FileProcessor.h"
#include "Translator.h"
#include <fstream>
#include <iostream>
using namespace std;

// Constructor
FileProcessor::FileProcessor(){
  string convertedSentence = "";
}

// Destructor
FileProcessor::~FileProcessor(){

}

/* ************************************************************************************************
 * Implementation of a member function - FileProcessor
 * ------------------------------------------------------------------------------------------------
 * This function reads information from a text file, and outputs translated information to an
 * output file.
 * ------------------------------------------------------------------------------------------------
 * Function has 2 @param: string inputName, string output
 * return value and type - none
 * ************************************************************************************************/

void FileProcessor::processFile(string inputName, string outputName){

    // creating object
    Translator TranslatorFile;

    ifstream inFile(inputName, ios::in); // reads information from inFile
    ofstream outFile(outputName, ios::out); // writes information to outfile

    // Declaration - of string variables for while loop
    string sentenceInput;
    string convertedSentence;

    // If - statement for a file that couldn't be opened
    if(!inFile.is_open()){
        cout << "Could not open file " << inputName << endl;
        exit(EXIT_FAILURE);
    }

    // While loop - gets info from input file and converts info for translation
    while(getline(inFile, sentenceInput))
    {
        convertedSentence = TranslatorFile.translateEnglishSentence(sentenceInput);
        outFile << convertedSentence << endl;
    }

    inFile.close(); // closes file that info came from
    outFile.close(); // close output file that was created
}
