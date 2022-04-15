
#include <iostream>

class Student {
   public:
     int getWaitTime();
     int getArrivalTime();
     int getTimeNeeded();
     void setTimeNeeded(int time);
     void incrementWaitTime();
     void printInfo();
     void setWaitTime(int t);
     void setArrivalTime(int time);
     void setLineStatus(bool status);
     bool getNull();
     bool getLineStatus();
     Student();
     Student(bool status, int tneeded, int arvlTime);
     ~Student();
private:
    int timeNeeded;
    int arrivalTime;
    int waitTime;
    bool isNull;
    bool inLine;
 };