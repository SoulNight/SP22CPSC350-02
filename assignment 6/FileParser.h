/*
 FileParser.h is the blueprint for the FileParser class. it contains the
 methods and variables that will be implemented in the class
*/
#include <string>
#include <iostream>
#include <string>

using namespace std;

class FileParser {
public:
  FileParser();
  ~FileParser();
  int numLines = 0;
  int getNumLines();
  int readFromFile();
  int getNumWindows();
  int getArrivalTime();
  string numWindows;
  string promptUser();
  string getString();
  string* getFileInfo();
  string* fileArray;
  string* extractInfo(string cmdLine);
  void printArray();

private:
  string syntax = "";
  string timeNeeded;
  string numStudents;
  string arrivalTime;
};
