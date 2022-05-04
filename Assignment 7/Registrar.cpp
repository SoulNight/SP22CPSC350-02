#include "Registrar.h"
#include <iostream>
#include <limits>

using namespace std;

/* ************************************************************************************************
 * Implementation of a member function - displayOptions
 * ------------------------------------------------------------------------------------------------
 * This function will display the user menu to screen
 * ------------------------------------------------------------------------------------------------
 * Function has 0 @param: none
 * returns: none
 * ************************************************************************************************/
void Registrar::displayOptions(){
  while(true){
    int choice;

    cout << "Make a selection from the choices below: " << '\n';
    cout <<'\t' <<"1. Print all students and their information (sorted by ascending id #)"<<'\n';
    cout <<'\t' <<"2. Print all faculty and their information (sorted by ascending id #)"<<'\n';
    cout <<'\t' <<"3. Find and display student information given the students id"<<'\n';
    cout <<'\t' <<"4. Find and display faculty information given the faculty id"<<'\n';
    cout <<'\t' <<"5. Given a student’s id, print the name and info of their faculty advisor"<<'\n';
    cout <<'\t' <<"6. Given a faculty id, print ALL the names and info of his/her advisees."<<'\n';
    cout <<'\t' <<"7. Add a new student"<<'\n';
    cout <<'\t' <<"8. Delete a student given the id"<<'\n';
    cout <<'\t' <<"9. Add a new faculty member"<<'\n';
    cout <<'\t' <<"10. Delete a faculty member given the id."<<'\n';
    cout <<'\t' <<"11. Change a student’s advisor given the student id and the new faculty id."<<'\n';
    cout <<'\t' <<"12. Remove an advisee from a faculty member given the ids"<<'\n';
    cout <<'\t' <<"13. Rollback"<<'\n';
    cout <<'\t' <<"14. Exit"<<'\n';
    cout <<'\t'<<"Input number: " ;
    cin>>choice;
    if(choice==1){
    // print all info in ascending id of students
      cout << "1" << '\n';
      printStudents();
    } else if (choice==2){
      cout << "2" << '\n';
      printFaculty();

    }else if (choice==3){
      cout << "3" << '\n';
      displayStudent();

    }else if (choice==4){
      cout << "4" << '\n';
      displayFaculty();
    }else if (choice==5){
      cout << "5" << '\n';
      printAdvisorInfo();
    }else if (choice==6){
      cout << "6" << '\n';
      printAdviseeInfo();
    }else if (choice==7){
      cout << "7" << '\n';
      addStudent();

    }else if (choice==8){
      cout << "8" << '\n';
      deleteStudent();
    }else if (choice==9){
      cout << "9" << '\n';
      addFaculty();

    }else if (choice==10){
      cout << "10" << '\n';
      deleteFaculty();
    }else if (choice==11){
      changeAdvisor();
    }else if (choice==12){
      cout << "12" << '\n';
      removeAdvisee();
    }else if (choice==13){
      cout << "13" << '\n';
      rollback();
    }else if (choice==14){
      cout << "14" << '\n';
      treeToCSV();
      // storeTreeOrder();
      break;
    }
  }
}


// Constructor
Registrar::Registrar(){
  // generateStudentBST
  checkForFiles();
  displayOptions();
  // writeObject("max");
  // checkSerialization("max");
}

/* ************************************************************************************************
 * Implementation of a member function - createFaculty
 * ------------------------------------------------------------------------------------------------
 * This function will ask the user to input data for faculty member
 * ------------------------------------------------------------------------------------------------
 * Function has 0 @param: none
 * returns: faculty name, faculty level, faculty id and faculty department
 * ************************************************************************************************/
Faculty Registrar::createFaculty(){
  int fid;
  string fname;
  string flevel;
  string fdept;
  string popList;

  cout << "~Faculty Info~" << '\n';
  cout <<'\t' <<"Enter Faculty ID: ";
  cin>>fid;
  cout <<'\t' <<"Enter Faculty Name: ";
  cin>>fname;
  cout <<'\t' <<"Enter Faculty Seniority Level: ";
  cin>>flevel;
  cout <<'\t' <<"Enter Faculty Department: ";
  cin>>fdept;

  Faculty f(fid,fname, flevel,fdept);
  cout << '\n';


  return f;
}


/* ************************************************************************************************
 * Implementation of a member function - addFaculty
 * ------------------------------------------------------------------------------------------------
 * This function will add the faculty information to the database
 * ------------------------------------------------------------------------------------------------
 * Function has 0 @param: none
 * returns: none
 * ************************************************************************************************/
void Registrar::addFaculty(){
  Faculty temp=createFaculty();
  facultyTBLptr->insert(new TreeNode<Faculty>(temp.getId(), temp));
}

/* ************************************************************************************************
 * Implementation of a member function - printFaculty
 * ------------------------------------------------------------------------------------------------
 * This function will print the faculty information
 * ------------------------------------------------------------------------------------------------
 * Function has 0 @param: none
 * returns: none
 * ************************************************************************************************/
void Registrar::printFaculty(){
  string idStr=facultyTBLptr->getOrderedString(facultyTBLptr->getRoot());
  string singleID;
  // cout << studentTBLptr->printTreeString()<< '\n';
  for(int i =0; i<idStr.size();i++){
    if(idStr[i]!='-'){
       singleID+=idStr[i];
     } else{
       // cout << singleID << '\n';

       facultyTBLptr->find(stoi(singleID)).printInfo();
       singleID="";
     }
  }
  // studentTBLptr->printTree();
  enterToContinue();
}

/* ************************************************************************************************
 * Implementation of a member function - displayFaculty
 * ------------------------------------------------------------------------------------------------
 * This function will display the faculty information to the screen
 * ------------------------------------------------------------------------------------------------
 * Function has 0 @param: none
 * returns: none
 * ************************************************************************************************/
void Registrar::displayFaculty(){
  int id;
  cout << "Enter The Id of Faculty to display: ";
  cin >> id;
  if(facultyTBLptr->find(id).getName()=="null"){
    cout << "Faculty with ID #" <<id<<" does not exist in the database"<< '\n';
  }else{
    facultyTBLptr->find(id).printInfo();
  }
  enterToContinue();
}


/* ************************************************************************************************
 * Implementation of a member function - printAdviseeInfo
 * ------------------------------------------------------------------------------------------------
 * Given a faculty id, this function will print all the names and info of his/her advisees.
 * ------------------------------------------------------------------------------------------------
 * Function has 0 @param: none
 * returns: none
 * ************************************************************************************************/
void Registrar::printAdviseeInfo(){
  int id;
  cout << "Enter Faculty ID # :";
  cin >> id;
  if(facultyTBLptr->find(id).getName()=="null"){
    cout << "Faculty with ID #" <<id<<" does not exist in the database"<< '\n';
  }else{
    // find the faculty member with this id in faculty table
    Faculty f= facultyTBLptr->find(id);
    // f.printInfo();
    // get the list of advisees from that faculty member
    list<int> adviseeIddList=f.getAdviseeID();
    if(adviseeIddList.size()==0){
      cout << "This Faculty has no Advisees" << '\n';
    } else{
      // loop through list of advisee ids
      list<int>::iterator it;
      for (it = adviseeIddList.begin(); it != adviseeIddList.end(); it++)
          // check to see if the id exists
          if(studentTBLptr->find(*it).getName()=="null"){
            cout << "Advisee with ID #" <<*it<<" does not exist."<<'\n';
          } else{
            studentTBLptr->find(*it).printInfo();
          }
    }
  }
  enterToContinue();
}


/* ************************************************************************************************
 * Implementation of a member function - deleteFaculty
 * ------------------------------------------------------------------------------------------------
 * This function will delete a faculty member given the id.
 * ------------------------------------------------------------------------------------------------
 * Function has 0 @param: none
 * returns: none
 * ************************************************************************************************/
void Registrar::deleteFaculty(){
  int id;
  cout << "Faculty id to delete: #: " << '\n';
  cin >> id;

  if(facultyTBLptr->find(id).getName()=="null"){
    cout << "Faculty with ID #" <<id<<" does not exist in the database"<< '\n';
  }else{
    facultyTBLptr->remove(id);
  }
  enterToContinue();
}

/* ************************************************************************************************
 * Implementation of a member function - removeAdvisee
 * ------------------------------------------------------------------------------------------------
 * This function will Remove an advisee from a faculty member given the ids
 * ------------------------------------------------------------------------------------------------
 * Function has 0 @param: none
 * returns: none
 * ************************************************************************************************/
void Registrar::removeAdvisee(){
  int id;

  int fid;
  cout << "Enter Faculty ID # :";
  cin >> fid;

  cout << "ID of student to remove #: ";
  cin >> id;

  if(studentTBLptr->find(id).getName()=="null"){
    cout << "Student with ID #" <<id<<" does not exist in the database"<< '\n';
    enterToContinue();

    return;
  }
  if(facultyTBLptr->find(fid).getName()=="null"){
    cout << "Faculty with ID #" <<id<<" does not exist in the database"<< '\n';
    enterToContinue();

    return;
  }
  if(studentTBLptr->find(id).getAdvisor()!=fid){
    cout << "Student with ID #" <<id<<" does not have  Advisor"<<fid<< '\n';
    enterToContinue();

    return;
  }
  facultyTBLptr->getNode(fid)->value.remAdvisee(id);
  studentTBLptr->getNode(id)->value.setAdvisor(0);
  enterToContinue();
}


/* ************************************************************************************************
 * Implementation of a member function - printStudent
 * ------------------------------------------------------------------------------------------------
 * This function will print all students and their information (sorted by ascending id #)
 * ------------------------------------------------------------------------------------------------
 * Function has 0 @param: none
 * returns: none
 * ************************************************************************************************/
void Registrar::printStudents(){
  // studentTBLptr->inOrder(studentTBLptr->getRoot());
  string idStr=studentTBLptr->getOrderedString(studentTBLptr->getRoot());
  string singleID;
  // cout << studentTBLptr->printTreeString()<< '\n';
  for(int i =0; i<idStr.size();i++){
    if(idStr[i]!='-'){
       singleID+=idStr[i];
     } else{
       // cout << singleID << '\n';
       studentTBLptr->find(stoi(singleID)).printInfo();
       singleID="";
     }
  }
  // studentTBLptr->printTree();
  enterToContinue();
}


/* ************************************************************************************************
 * Implementation of a member function - displayStudent
 * ------------------------------------------------------------------------------------------------
 * This function will find and display student information given the students id
 * ------------------------------------------------------------------------------------------------
 * Function has 0 @param: none
 * returns: none
 * ************************************************************************************************/
void Registrar::displayStudent(){
  int id;
  cout << "Enter The Id of Student to display: ";
  cin >> id;
  if(studentTBLptr->find(id).getName()=="null"){
    cout << "Student with ID #" <<id<<" does not exist in the database"<< '\n';
  }else{
    studentTBLptr->find(id).printInfo();
  }
  enterToContinue();
}

/* ************************************************************************************************
 * Implementation of a member function - createStudent
 * ------------------------------------------------------------------------------------------------
 * This function add a new student
 * ------------------------------------------------------------------------------------------------
 * Function has 0 @param: none
 * returns: S, student id, student, name, student level, student major, student GPA, and student id
 * ************************************************************************************************/
Student Registrar::createStudent(){
  int tid;
  string tname;
  double tgpa;
  string tmajor;
  int taid;
  string tlevel;
  while(true){
    cout << "~Student Info~" << '\n';
    cout <<'\t' <<"Enter Student ID: ";
    cin>>tid;
    cout <<'\t' <<"Enter Student Name: ";
    cin>>tname;
    cout <<'\t' <<"Enter Student Grade Level: ";
    cin>>tlevel;
    cout <<'\t' <<"Enter Student Major: ";
    cin>>tmajor;
    cout <<'\t' <<"Enter Student GPA: ";
    cin>>tgpa;
    cout <<'\t' <<"Enter Student Advisor's ID: ";
    cin>>taid;

    if(facultyTBLptr->find(taid).getName()=="null"){
      cout << "Advisor with ID #: " <<taid<<" does not exist"<< '\n';
      continue;
    }
    facultyTBLptr->getNode(taid)->value.addAdvisee(tid);
    // facultyTBLptr->find(taid).addAdvisee(tid);
    Student s(tid,tname, tlevel,tmajor,tgpa,taid);
    return s;
  }
}


/* ************************************************************************************************
 * Implementation of a member function - addStudent
 * ------------------------------------------------------------------------------------------------
 * This function will add the student information to the database
 * ------------------------------------------------------------------------------------------------
 * Function has 0 @param: none
 * returns: none
 * ************************************************************************************************/
void Registrar::addStudent(){
  Student temp = createStudent();
  studentTBLptr->insert(new TreeNode<Student>(temp.getId(), temp));
  changeMade("student");
}

/* ************************************************************************************************
 * Implementation of a member function - printAdvisorInfo
 * ------------------------------------------------------------------------------------------------
 * Given a student’s id, this function will print the name and info of their faculty advisor
 * ------------------------------------------------------------------------------------------------
 * Function has 0 @param: none
 * returns: none
 * ************************************************************************************************/
void Registrar::printAdvisorInfo(){
  int id;
  cout << "Enter Student ID # :";
  cin >> id;
  if(studentTBLptr->find(id).getName()=="null"){
    cout << "Student with ID #" <<id<<" does not exist in the database"<< '\n';
  }else if(facultyTBLptr->find(studentTBLptr->find(id).getAdvisor()).getName()=="null"){
    cout << "Faculty with ID #" <<studentTBLptr->find(id).getAdvisor()<<" does not exist in the database"<< '\n';
  }else{
    facultyTBLptr->find(studentTBLptr->find(id).getAdvisor()).printInfo();
  }
  enterToContinue();
  }


/* ************************************************************************************************
 * Implementation of a member function - deleteStudent
 * ------------------------------------------------------------------------------------------------
 * Given a student’s id, this function will delete the pertinent information from the database
 * ------------------------------------------------------------------------------------------------
 * Function has 0 @param: none
 * returns: none
 * ************************************************************************************************/
void Registrar::deleteStudent(){
  int id;
  cout << "Student id to delete: #: " << '\n';
  cin >> id;

  if(studentTBLptr->find(id).getName()=="null"){
    cout << "Student with ID #" <<id<<" does not exist in the database"<< '\n';
  }else{
    facultyTBLptr->getNode(studentTBLptr->find(id).getAdvisor())->value.remAdvisee(id);
    studentTBLptr->remove(id);
  }
  enterToContinue();
}


/* ************************************************************************************************
 * Implementation of a member function - changeAdvisor
 * ------------------------------------------------------------------------------------------------
 * This function will change a student’s advisor given the student id and the new faculty id.
 * ------------------------------------------------------------------------------------------------
 * Function has 0 @param: none
 * returns: error if student doesn't exist in database
 * ************************************************************************************************/
void Registrar::changeAdvisor(){
  int id;
  cout << "Enter Student ID # :";
  cin >> id;

  int fid;
  cout << "ID of New Advisor: #: ";
  cin >> fid;
  if(studentTBLptr->find(id).getName()=="null"){
    cout << "Student with ID #" <<id<<" does not exist in the database"<< '\n';
    enterToContinue();
    return;
  }
  if(facultyTBLptr->find(fid).getName()=="null"){
    cout << "Faculty with ID #" <<id<<" does not exist in the database"<< '\n';
    enterToContinue();
    return;
  }
  // go to students current advisor and remove them from their advisee list
  facultyTBLptr->getNode(studentTBLptr->find(id).getAdvisor())->value.remAdvisee(id);

  //add students id to advisor list of new advisor
  facultyTBLptr->getNode(fid)->value.addAdvisee(id);

  // set advisor of student to new one ,,
  studentTBLptr->getNode(id)->value.setAdvisor(fid);
  enterToContinue();
}


/* ************************************************************************************************
 * Implementation of a member function - checkForFiles
 * ------------------------------------------------------------------------------------------------
 * This function will check for serilaization of a database table for student and faculty
 * ------------------------------------------------------------------------------------------------
 * Function has 0 @param: none
 * returns: error if student doesn't exist in database
 * ************************************************************************************************/
void Registrar:: checkForFiles(){
  ifstream inFS; // input file stream
  int fileNum; //file Data
  // // open fileNum
  // cout << "Opening File " << fileName<< endl;
  inFS.open("studentRecord.csv");

  if(!inFS.is_open()){
    // cout << "Could not open file " << fileName<< endl;
    inFS.close();
    return;
  } else{
    generateStudentBST();
    generateFacBST();
    inFS.close();
  }
    inFS.close();
  }


/* ************************************************************************************************
* Implementation of a member function - generateStudentBST
* ------------------------------------------------------------------------------------------------
* This function will creat BST for student
* ------------------------------------------------------------------------------------------------
* Function has 0 @param: none
* returns: error if student doesn't exist in database
* ************************************************************************************************/
void Registrar::generateStudentBST(){
  string studentString;
  ifstream infile;
  vector<string> fields;
  int numLines;
  infile.open ("studentRecord.csv");
  while(!infile.eof()) // To get you all the lines.
  {
    getline(infile,studentString); // Saves the line in STRING.
    // cout<<studentString; // Prints our STRIN
    string fieldStr="";
    int fieldCount=0;
    for(int i =0; i<studentString.length();i++){
    if(studentString[i]!=' '){
      if(studentString[i]==','){
        ++fieldCount;
        fields.push_back(fieldStr);
         fieldStr="";
      }
      else{
        fieldStr+=studentString[i];
      }
    }
  }
  numLines++;
}
int numStudents=(numLines-1);
  for(int j=0;j<numStudents;j++){
    Student temp(stoi(fields[(6*j)+0]),fields[(6*j)+1],fields[(6*j)+2],fields[(6*j)+3],stod(fields[(6*j)+4]),stoi(fields[(6*j)+5]));
    studentTBLptr->insert(new TreeNode<Student>(temp.getId(), temp));
    studentIdsToLoad.push_back(std::stoi(fields[(6*j)+0]));

}
infile.close();
}

/* ************************************************************************************************
* Implementation of a member function - generateFactBST
* ------------------------------------------------------------------------------------------------
* This function will creat BST for faculty member
* ------------------------------------------------------------------------------------------------
* Function has 0 @param: none
* returns: error if student doesn't exist in database
* ************************************************************************************************/
void Registrar::generateFacBST(){
  string facString;
  ifstream infile;
  vector<string> fields;
  int numLinesf;
  infile.open ("facultyRecord.csv");
  while(!infile.eof()) // To get you all the lines.
  {
    getline(infile,facString); // Saves the line in STRING.
    // cout<<facString; // Prints our STRIN
    string fieldStr="";
    int fieldCount=0;
    for(int i =0; i<facString.length();i++){
    if(facString[i]!=' '){
      if(facString[i]==','){
        ++fieldCount;
        fields.push_back(fieldStr);
         fieldStr="";
      }
      else{
        fieldStr+=facString[i];
      }
    }
  }
  numLinesf++;
}

// cout << fields.size() << '\n';
cout << numLinesf << '\n';
int numFac=(numLinesf-1)/3;
cout << "numFac:"<<numFac << '\n';
// for(int i =0;i<numFac;i++){
  for(int j=0;j<numFac;j++){
    Faculty temp(stoi(fields[(4*j)+0]),fields[(4*j)+1],fields[(4*j)+2],fields[(4*j)+3]);
    facultyTBLptr->insert(new TreeNode<Faculty>(temp.getId(), temp));
}
for (int j=0;j<numFac;j++){
  if(studentIdsToLoad.size()!=0){
    for(int i=0; i<studentIdsToLoad.size(); i++){
      if(studentTBLptr->getNode(studentIdsToLoad[i])->value.getAdvisor()==std::stoi(fields[(4*j)+0])){
        facultyTBLptr->getNode(std::stoi(fields[(4*j)+0]))->value.addAdvisee(studentIdsToLoad[i]);
      }
    }
  }

}
infile.close();
}
// void Registrar::writeObject(){
//   storeTrees();
//
//
// }

/* ************************************************************************************************
* Implementation of a member function - storeTreeOrder
* ------------------------------------------------------------------------------------------------
* This function store the BST information to text file
* ------------------------------------------------------------------------------------------------
* Function has 0 @param: none
* returns: error if student doesn't exist in database
* ************************************************************************************************/
void Registrar::storeTreeOrder(){
  FILE *fp = fopen("studentTree.txt", "w");
  FILE *ffp = fopen("facultyTree.txt", "w");

  if (fp == NULL)
  {
      puts("Could not open file");
      return;
  }
  if (ffp == NULL)
  {
      puts("Could not open file");
      return;
  }
  studentTBLptr->getRoot()->serialize(studentTBLptr->getRoot(), fp);
  tblFaculty.getRoot()->serialize(tblFaculty.getRoot(), ffp);
  fclose(fp);
  fclose(ffp);
}


/* ************************************************************************************************
* Implementation of a member function - treeToCSV
* ------------------------------------------------------------------------------------------------
* This function will store the student BST to a CSV file
* ------------------------------------------------------------------------------------------------
* Function has 0 @param: none
* returns: error if student doesn't exist in database
* ************************************************************************************************/
void Registrar::treeToCSV(){
  ofstream ofs;
  ofs.open("studentRecord.csv", ofstream::out | ofstream::trunc);
  ofs.close();
  storeTreeOrder();
  facTreeToCSV();

  string nodeString;
  ifstream infile;
  infile.open ("studentTree.txt");
  while(!infile.eof()) // To get you all the lines.
  {
    getline(infile,nodeString); // Saves the line in STRING.
  }
  infile.close();

  string idStr="";

  for(int i =0; i<nodeString.length();i++){
    if(nodeString[i]!='\n'){
      if(nodeString[i]==' '){
        fstream fout;
        fout.open("studentRecord.csv");
        fout.close();
        int id=stoi(idStr);
        studentTBLptr->getNode(id)->value.printStudentToFile();
        idStr="";
      }
      idStr+=nodeString[i];
      }
    }
  }


/* ************************************************************************************************
* Implementation of a member function - facTreeToCSV
* ------------------------------------------------------------------------------------------------
* This function will store the faculty BST to a CSV file
* ------------------------------------------------------------------------------------------------
* Function has 0 @param: none
* returns: error if student doesn't exist in database
* ************************************************************************************************/
void Registrar::facTreeToCSV(){
  string nodeString;
  ifstream infile;
  ofstream ofs;

  ofs.open("facultyRecord.csv", ofstream::out | ofstream::trunc);
  ofs.close();
  infile.open ("facultyTree.txt");
  while(!infile.eof()) // To get you all the lines.
  {
    getline(infile,nodeString); // Saves the line in STRING.
  }
  infile.close();
  string idStr="";
  for(int i =0; i<nodeString.length();i++){
    if(nodeString[i]!='\n'){
      if(nodeString[i]==' '){
        fstream fout;
        fout.open("facultyRecord.csv");
        fout.close();
        int id=stoi(idStr);
        facultyTBLptr->getNode(id)->value.printFacToFile();
        idStr="";
      }
      idStr+=nodeString[i];
      }
    }
  }


/* ************************************************************************************************
* Implementation of a member function - enterToContinue
* ------------------------------------------------------------------------------------------------
* This function will pause at display
* ------------------------------------------------------------------------------------------------
* Function has 0 @param: none
* returns: error if student doesn't exist in database
* ************************************************************************************************/
void Registrar::enterToContinue(){
  cout << "PRESS ENTER TO CONTINUE" << '\n';
  cin.ignore();
  cin.ignore( numeric_limits <streamsize> ::max(), '\n' );
}


/* ************************************************************************************************
* Implementation of a member function - changeMade
* ------------------------------------------------------------------------------------------------
* This function will track changes made to database for student
* ------------------------------------------------------------------------------------------------
* Function has 0 @param: none
* returns: error if student doesn't exist in database
* ************************************************************************************************/
void Registrar::changeMade(string type){
   if(type=="student" ){
     studentStack.push(*studentTBLptr);
     studentTBLptr->printTree();
     studentTBLptr->printTree();
   }
}

/* ************************************************************************************************
* Implementation of a member function - rollback
* ------------------------------------------------------------------------------------------------
* This function will rollback recent changes to function
* ------------------------------------------------------------------------------------------------
* Function has 0 @param: none
* returns: error if student doesn't exist in database
* ************************************************************************************************/
void Registrar::rollback(){
  std::cout << "Hmmmmm.... something is wrong..." << '\n';
  enterToContinue();
}
