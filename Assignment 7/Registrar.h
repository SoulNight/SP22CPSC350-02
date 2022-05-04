#include "BST.h"
#include "Student.h"
#include "Faculty.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include<vector>

/* *********************************************************************************
 * Base Class - Registrar
 * ---------------------------------------------------------------------------------
 *  Registrar.h is the blueprint for the Registrar class. it contains the
 *  methods and variables that will be implemented in the class
 * **********************************************************************************/
class Registrar{
public:
  // Helper Stuff
  void displayOptions();
  Registrar();
  void rollback();
  void enterToContinue();
  void changeMade(string t);

  // Student Stuff
  void addStudent();
  Student createStudent();
  void printStudents();
  void printFaculty();
  void displayStudent();
  void printAdvisorInfo();
  void deleteStudent();
  void changeAdvisor();

  //Faculty Stuff
  Faculty createFaculty();
  void addFaculty();
  void printAdviseeInfo();
  void displayFaculty();
  void deleteFaculty();
  void removeAdvisee();

  // File Stuff
  void checkForFiles();
  void checkSerialization(string f);
  void writeObjectStudent(BST<Student> tree);
  void writeObjectFac(BST<Faculty> tree);
  void storeTreeOrder();
  void treeToCSV();
  void facTreeToCSV();

  void generateStudentBST();
  void generateFacBST();

private:
    // Student BST
    BST<Student> tblStudent;
    BST<Student>* studentTBLptr= &tblStudent;

    //Faculty BST
    BST<Faculty> tblFaculty;
    BST<Faculty>* facultyTBLptr= &tblFaculty;

    //Student Stack
    stack<BST<Student>> studentStack;
    vector<int> studentIdsToLoad;

};
