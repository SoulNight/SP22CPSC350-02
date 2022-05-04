#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

/* *********************************************************************************
 *  Base Class - Student
 * ---------------------------------------------------------------------------------
 *  Student is the blueprint for the student table
 * **********************************************************************************/
class Student{
public:
    int getId();
    void setId(int id);
    string getName();
    void setName(string name);
    int getAdvisor() const;
    double getGPA() const;
    string getMajor() const;
    string getGradeLevel() const;
    void setGPA(double gpa);
    void setMajor(string major);
    void setAdvisor(int advisor);
    void setGradeLevel(string gradeLevel);
    Student();
    ~Student();
    Student(int studentId, string name, string gradeLevel, string major, double gpa, int advisor);
    void printInfo();
    bool operator<( Student& b);
    bool operator>( Student& b);
    bool operator==( Student& b);
    bool operator!=( Student& b);
    void printStudentToFile();
private:
    int m_id;
    string m_name;
    int m_advisor;
    double m_gpa;
    string m_major;
    string m_gradeLevel;
};
#endif
