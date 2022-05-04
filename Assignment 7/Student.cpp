// Student.cpp is the core implementation of a student record.
#include <fstream>
#include <iostream>

#include "Student.h"
#include <unistd.h>

/*
 * Default Constructor
 */
Student::Student() {
  m_gradeLevel = "";
  m_major = "";
  m_gpa = 0;
  m_advisor = 0;
  m_id=0;
  m_name="null";
}
Student::~Student(){
  ;
}

/*
 * Overloaded Constructor:
*/
Student::Student(int studentId, string studentName, string gradeLevel, string major, double gpa,
                 int advisor){
    m_gradeLevel = gradeLevel;
    m_major = major;
    m_gpa = gpa;
    m_advisor = advisor;
    m_id=studentId;
    m_name=studentName;
}


/* ************************************************************************************************
 * Implementation of a member function - printStudentToFile
 * ------------------------------------------------------------------------------------------------
 * This function will print student record to CSV file
 * ------------------------------------------------------------------------------------------------
 * Function has 0 @param: none
 * returns: none
 * ************************************************************************************************/
void Student::printStudentToFile(){
    fstream fout;
    fout.open("studentRecord.csv", ios::out | ios::app);
    fout << m_id << ", ";
    fout << m_name << ", ";
    fout << m_gradeLevel << ", ";
    fout << m_major << ", ";
    fout << m_gpa << ", ";
    fout << m_advisor << ", ";
    fout<<'\n';
}


/*
 * Accessor for getId
 * @param: none
 * @Returns: m_id
 */
int Student::getId(){
  return m_id;
}

/*
 * Mutator for setId
 * @param: id
 * @Returns: m_id
 */
void Student::setId(int id){
  m_id=id;
}


/*
 * Accessor for getName
 * @param: name
 * @returns: m_name
 */
string Student::getName(){
  return m_name;
}


/*
 * Mutator for setName
 * @param: name
 */
void Student::setName(string name){
  m_name=name;
}


/*
 * Accessor for getGradeLevel
 * Returns: students m_gradeLevel
 */
string Student::getGradeLevel() const{
    return m_gradeLevel;
}


/*
 * Accessor for getMajor
 * Returns: students m_major
 */
string Student::getMajor() const{
    return m_major;
}


/*
 * Accessor for students GPA
 * Returns: students GPA
 */
double Student::getGPA() const{
    return m_gpa;
}


/*
 * Accessor for students advisor
 * Returns: students advisor
 */
int Student::getAdvisor() const{
    return m_advisor;
}


/*
 * Mutator for setGradeLevel
 * returns: nothing
 */
void Student::setGradeLevel(string gradeLevel) {
    m_gradeLevel = gradeLevel;
}


/*
 * Mutator for students major
 * returns: nothing
 */
void Student::setMajor(string major) {
    m_major = major;
}


/*
 * Mutator for GPA
 * returns: nothing
 */
void Student::setGPA(double gpa) {
    m_gpa = gpa;
}


/*
 * Mutator for advisor
 * returns: nothing
 */
void Student::setAdvisor(int advisor) {
    m_advisor = advisor;
}


/* ************************************************************************************************
 * Implementation of a member function - printInfo
 * ------------------------------------------------------------------------------------------------
 * This function will print student info for displayStudent
 * ------------------------------------------------------------------------------------------------
 * Function has 0 @param: none
 * returns: none
 * ************************************************************************************************/
void Student::printInfo(){
  std::cout << "Student with Id: " <<m_id<<", Name: "<<m_name<<", AdvisorID: "<<m_advisor<<", GPA: "<<m_gpa<<", Major: "<<m_major<<", Grade level: "<<m_gradeLevel<< '\n';
}


/* ************************************************************************************************
 * Implementation of operator overload function - operator <
 * ------------------------------------------------------------------------------------------------
 * This function will compare students in the BST
 * ------------------------------------------------------------------------------------------------
 * Function has 1 @param: b
 * returns: true or false
 * ************************************************************************************************/
bool Student::operator<(Student& b){
  if(m_id<b.getId())
    return true;
  return false;
}


/* ************************************************************************************************
 * Implementation of operator overload function - operator >
 * ------------------------------------------------------------------------------------------------
 * This function will compare students in the BST
 * ------------------------------------------------------------------------------------------------
 * Function has 1 @param: b
 * returns: true or false
 * ************************************************************************************************/
bool Student::operator>( Student& b){
  if(m_id<b.getId())
    return false;
  return true;
}


/* ************************************************************************************************
 * Implementation of operator overload function - operator ==
 * ------------------------------------------------------------------------------------------------
 * This function will compare students in the BST
 * ------------------------------------------------------------------------------------------------
 * Function has 1 @param: b
 * returns: true or false
 * ************************************************************************************************/
bool Student::operator==( Student& b){
  if(m_id==b.getId())
    return true;
  return false;
}


/* ************************************************************************************************
 * Implementation of operator overload function - operator !=
 * ------------------------------------------------------------------------------------------------
 * This function will compare students in the BST
 * ------------------------------------------------------------------------------------------------
 * Function has 1 @param: b
 * returns: true or false
 * ************************************************************************************************/
bool Student::operator!=( Student& b){
  if(m_id==b.getId())
    return false;
  return true;
}
