#include "Queue.h"
#include "FileParser.h"
#include "Student.h"
#include <iostream>
#include <list>

#include <iostream>

class Simulation {
   private:
     int ticks=0;
     int lineCount=0;
     int timeNeeded{};
     int numStudents{};
     int arrivalTime{};
     int waitTime{};
     int* winIdleArr;
     string* fileInfo;
     Student* windows;
     void printWaitList(list<int>g);
     void calcStudentMetrics();
     Queue<Student> studentQ;
     list<int> waitTimes;
   public:
     int numWindows;
     int linesInFile;
     void getWave(int time);
     void Run();
     void lineLogic(Student arr[], int tcks);
     void findSpot(Student s);
     void checkIdle(Student win[], int t);
     void calcMedWaitTime(int sz, int index);
     void sortIdle();
     void printIdleMetrics();
     bool isEmpty(Student arr[]);
     bool spotAvailable();
     Simulation(string arg);
 };
