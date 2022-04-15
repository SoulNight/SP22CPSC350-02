#include "Student.h"
#include <iostream>
using namespace std;

/*
 * Default Constructor
 */
Student::Student(){
  inLine = false;
  timeNeeded = 0;
  arrivalTime = 0;
  isNull = true;
}

/*
 * Overloaded constructor: creates a student with the desired data values
 * @parameters: status, tneeded, arvLtime
 * @return: none
*/

Student::Student(bool status,int tneeded, int arvlTime){
  waitTime = 0;
  isNull = false;
  inLine = status;
  timeNeeded = tneeded;
  arrivalTime = arvlTime;
}

/*
 * Destructor for Student.h
 */
Student::~Student(){
}


/*
printInfo
Void Function displays information to screen
@param item: none
@return: none
*/
void Student::printInfo(){
  cout << "I am a student with" << endl;
  cout << "arrival time: "<< arrivalTime << endl;
  cout << "timeNeeded: "  << timeNeeded  << endl << endl;
}

/*
getLineStatus
Bool Function get the line status
@param item: none
@return: inlIne
*/
bool Student::getLineStatus(){
  return inLine;
}

/*
setLineStatus
Void Function sets the students inline status
@param item: status
@return: none
*/
void Student::setLineStatus(bool status){
  inLine = status;
}

/*
getArrivalTime
int Function gets the student arrival time
@param item: none
@return: arrivalTime
*/
int Student::getArrivalTime(){
  return arrivalTime;
}

/*
setArrivalTime
Void Function sets the arrival time of student
@param item: item,m
@return: removesFront; element at the front
*/
void Student::setArrivalTime(int time){
  arrivalTime = time;
}

/*
getNull
Bool Function is null to check if student is idle
@param item: none
@return: isNull
*/
bool Student::getNull(){
  return isNull;
}

/*
getTimeNeeded
Int Function will tell us if no time is need or more time is needed to student
@param item: none
@return: timeNeeded
*/
int Student::getTimeNeeded(){
  return timeNeeded;
}

/*
setTimeNeeded
Void Function passing the time needed at the window
@param item: time
@return: none
*/
void Student::setTimeNeeded(int time){
  timeNeeded = time;
}

/*
setWaitTime
Void Function sets student wait time in the queue
@param item: t
@return: none
*/
void Student::setWaitTime(int t){
  waitTime = t;
}

/*
Template for Clear
Int Function pushes wait time to front of the queue
@param item: none
@return: waitTime
*/
int Student::getWaitTime(){
  return waitTime;
}
