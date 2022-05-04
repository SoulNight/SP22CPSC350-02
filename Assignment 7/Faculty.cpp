#include "Faculty.h"
#include <iostream>
#include <fstream>

#include <unistd.h>

using namespace std;

// Constructor - initializes the variables
Faculty::Faculty(){
  m_id=0;
  m_name="null";
  m_level="";
  m_dept="";
}

/*
 * Overload Constructor for Faculty
 * @param: id, name, level, dept
 */
Faculty::Faculty(int id, string name, string level, string dept){
  m_id=id;
  m_name=name;
  m_level=level;
  m_dept=dept;
  m_advIds=list<int>();
}


// Destructor
Faculty::~Faculty(){
}


/*
 * Accessor for Faculty getID
 * Returns: faculty m_Id
 */
int Faculty::getId(){
  return m_id;
}


/*
 * Mutator for setId
 * @param: id
 * returns: nothing
 */
void Faculty::setId(int id){
  m_id = id;
}


/*
 * Accessor for Faculty getLevel
 * Returns: faculty m_level
 */
string Faculty::getLevel(){
  return m_level;
}


/*
 * Mutator for setLevel
 * @param: lev
 * returns: nothing
 */
void Faculty::setLevel(string lev){
  m_level=lev;
}


/*
 * Accessor for Faculty getName
 * Returns: faculty m_name
 */
string Faculty::getName(){
  return m_name;
}


/*
 * Mutator for setName
 * @param: name
 * returns: nothing
 */
void Faculty::setName(string name){
  m_name = name;
}


/*
 * Accessor for Faculty getDept
 * Returns: faculty m_dept
 */
string Faculty::getDept(){
  return m_dept;
}


/*
 * Mutator for setDept
 * @param: dept
 * returns: nothing
 */
void Faculty::setDept(string dept){
  m_dept = dept;
}


/*
 * Accessor for Faculty getAdviseeID
 * Returns: faculty m_advIds
 */
list<int> Faculty::getAdviseeID(){
  return m_advIds;
}

/*
 * Mutator for setAdviseeIDs
 * @param: list ids
 * returns: nothing
 */
void Faculty::setAdviseeIDs(list<int> ids){
  m_advIds = ids;
}


/* ************************************************************************************************
 * Implementation of a member function - addAdvisee
 * ------------------------------------------------------------------------------------------------
 * This function adds the Faculty advisees id
 * ------------------------------------------------------------------------------------------------
 * Function has 1 @param: idToAdd
 * returns: none
 * ************************************************************************************************/
void Faculty::addAdvisee(int idToAdd){
  m_advIds.push_back(idToAdd);
}

/* ************************************************************************************************
 * Implementation of a member function - remAdvisee
 * ------------------------------------------------------------------------------------------------
 * This function removes the faculty advisees id number
 * ------------------------------------------------------------------------------------------------
 * Function has 1 @param: idToRemove
 * returns: none
 * ************************************************************************************************/
void Faculty::remAdvisee(int idToRemove){
  m_advIds.remove(idToRemove);
}

/* ************************************************************************************************
 * Implementation of a member function - overload less than operator
 * ------------------------------------------------------------------------------------------------
 * This function checks the faculty member id
 * ------------------------------------------------------------------------------------------------
 * Function has 1 @param: Faculty address
 * returns: true or false
 * ************************************************************************************************/
bool Faculty::operator<(Faculty& b){
  if(m_id < b.getId())
    return true;
  return false;
}

/* ************************************************************************************************
 * Implementation of a member function - overload greater than operator
 * ------------------------------------------------------------------------------------------------
 * This function checks the faculty member id
 * ------------------------------------------------------------------------------------------------
 * Function has 1 @param: Faculty address
 * returns: true or false
 * ************************************************************************************************/
bool Faculty::operator>(Faculty& b){
  if(m_id<b.getId())
    return false;
  return true;
}

/* ************************************************************************************************
 * Implementation of a member function - overload equals operator
 * ------------------------------------------------------------------------------------------------
 * This function checks the faculty member id
 * ------------------------------------------------------------------------------------------------
 * Function has 1 @param: Faculty address
 * returns: true or false
 * ************************************************************************************************/
bool Faculty::operator==(Faculty& b){
  if(m_id==b.getId())
    return true;
  return false;
}

/* ************************************************************************************************
 * Implementation of a member function - overload does not equal operator
 * ------------------------------------------------------------------------------------------------
 * This function checks the faculty member id
 * ------------------------------------------------------------------------------------------------
 * Function has 1 @param: Faculty address
 * returns: true or false
 * ************************************************************************************************/
bool Faculty::operator!=( Faculty& b){
  if(m_id==b.getId())
    return false;
  return true;
}

/* ************************************************************************************************
 * Implementation of a member function - printFacToFile
 * ------------------------------------------------------------------------------------------------
 * This function prints the faculty information to a file using fstream
 * ------------------------------------------------------------------------------------------------
 * Function has 0 @param: none
 * returns: none
 * ************************************************************************************************/
void Faculty::printFacToFile(){
    fstream fout;
    fout.open("facultyRecord.csv", ios::out | ios::app);
    fout << m_id << ", ";
    fout << m_name << ", ";
    fout << m_level<< ", ";
    fout << m_dept << ", ";
    fout<<'\n';
}

/* ************************************************************************************************
 * Implementation of a member function - printInfo
 * ------------------------------------------------------------------------------------------------
 * This function displays information from faculty table to screen
 * ------------------------------------------------------------------------------------------------
 * Function has 0 @param: none
 * returns: none
 * ************************************************************************************************/
void Faculty::printInfo(){
  cout << "Faculty with Id: " <<m_id<<", Name: "<<m_name<<", level: "<<m_level<<", Department: "<<m_dept;
  cout << ", Advisee Id's: ";
  for (auto const &i: m_advIds) {
  cout << i << ",";
  }
  cout  << '\n';
}
