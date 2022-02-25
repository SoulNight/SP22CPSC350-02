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
#include <iostream>
#include <string>
using namespace std;

int main(){

    // Creating object
    FileProcessor createFile;

    // Declaration of variables
    string fileName;
    string outFile;

    // Input - from user
    cout << "\nEnter the name of the input file: ";
    cin >> fileName;

    cout << "Enter the name of the output file: ";
    cin >> outFile;

    createFile.processFile(fileName, outFile); // Function call to create file

    return 0;
}
