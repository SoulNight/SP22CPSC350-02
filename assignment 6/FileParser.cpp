/*
FileParser.cpp is a class that takes handles grabbing text from desired files
*/
#include "FileParser.h"
#include <fstream>

/*
    Default Constructor: initializes values as needed
*/
FileParser::FileParser(){
}

/*
    Destructor
*/
FileParser::~FileParser(){
}


/*
extractInfo();
This function uses the ifstream class to convert a file to usable text
@param (string cmdLine representing a filepath to either be taken from command line or user
@return string syntax representing the information in a file
*/
string* FileParser::extractInfo(string fileName)
{
  ifstream inFS;
  string fileLine;
  inFS.open(fileName);

  //this loop just calculates how many lines in a file
  while(getline(inFS, fileLine))
  {
    numLines++;
  }
  inFS.close();

  inFS.open(fileName);
  fileArray = new string[numLines];
  int count = 0;
  while(getline(inFS,fileLine))
  {
    if(count == numLines)
      break;
    // adds each line to a string array
    fileArray[count++]=fileLine;
  }
     inFS.close();
     return fileArray;
}

/*
printArray
This function uses the ifstream class to convert a file to usable text
@param (string cmdLine representing a filepath to either be taken from command line or user
@return: none
*/
void FileParser::printArray()
{
  for (int i = 0; i < numLines; i++)
  {
    cout << fileArray[i] << endl;
  }
}

/*
prompt user()
prompts user to enter name of desired file, returns answer
@param: none
@return string inputFile representing the desired filepath
*/
string FileParser::promptUser()
{
  string inputFile;
  cout << "Enter name of file with extension: ";
  cin  >> inputFile;
  return inputFile;
}

/* getFileInfo
 * Pointer string to FileParser
 * @param: none
 * @return: fileArray
 */
string* FileParser::getFileInfo()
{
  return fileArray;
}

/* getNumLines
 * function that gets the number of lines for file parsing
 * @param: none
 * @return: numLines
 */
int FileParser::getNumLines()
{
  return numLines;
}
