#include "Simulation.h"
#include <array>

using namespace std;


/*
 * This function gets command line argument to extract info from text file in order to check & calculate student metrics,
 * idle time, line logic, idle metrics, simulation, sort idle time, print metric, wave information, line count.
 */

Simulation::Simulation(string arg)
{
  FileParser p;
  fileInfo = p.extractInfo(arg);
  numWindows = stoi(fileInfo[0]);
  windows = new Student[numWindows];
  winIdleArr = new int[numWindows];
  lineCount = 1;
  linesInFile = p.getNumLines();
  Run();
  calcStudentMetrics();
  printIdleMetrics();
  cout  << endl;
}


/*
 * This function gets each waves of students coming into the registrar's office
 * so we can convert the information from sting to int
 */
void Simulation::getWave(int time)
{
  if (lineCount == linesInFile)
  {
    return;
  }
  else
  {
    if(time == stoi(fileInfo[lineCount])) // converting time into string
    {
      arrivalTime = stoi(fileInfo[lineCount]);
      numStudents = stoi(fileInfo[++lineCount]);
      for(int i =0; i < numStudents; i++)
      {
        timeNeeded = stoi(fileInfo[++lineCount]);
        Student s(true,timeNeeded,arrivalTime);
        studentQ.enqueue(s);
        }
    ++lineCount;
   }
 }
}

/*
 * This function gets the waves of students coming into the registrars office
 */
void Simulation::Run()
{
  while(true)
  {
    getWave(ticks);
    lineLogic(windows, ticks);
    if(studentQ.qList.isEmpty() && isEmpty(windows) && lineCount == linesInFile)
    {
      break;
    }
    checkIdle(windows, ticks);
    ticks++;
  }
}


/*
 * This function gets us the information for the window and tick, so we can parse the arrival time, wait time,
 * and time needed for the student
 */
void Simulation::lineLogic(Student win[],int tcks)
{
  for (int i = 0; i < numWindows; i++)
  {
    // if the student in window needs no more time, and they aren't null
    // replace them with null or empty student object
    if(win[i].getTimeNeeded() == 0 && !win[i].getNull())
    {
      Student s;
      win[i] = s;
    }

    /*
    //if this window is empty
    put student first in queue in window,
    check if there is a non-null student in the window, if there is,
    set their wait time = ticks - arrival time
    else, set the null wait time = 0;
    */
    if(win[i].getNull())
    {
      win[i] = studentQ.dequeue();
      if(!win[i].getNull())
      {
        win[i].setWaitTime(tcks - win[i].getArrivalTime());
        waitTimes.push_front(win[i].getWaitTime());
      }
      else
          win[i].setWaitTime(0);
    }
    win[i].setTimeNeeded(win[i].getTimeNeeded() - 1);
  }
}


/*
 * This function tells us whether the line is empty or not
 */
bool Simulation::isEmpty(Student win[])
{
  for (int i = 0; i < numWindows; i++)
  {
    if(!win[i].getNull())
      return false;
  }
  return true;
}

/*
 * This function prints the wait times using a list
 */
void Simulation::printWaitList(list<int> g)
{
    list<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it){
        cout << '\t' << *it;
    }
    cout << endl;
}


/*
 * This function calculate the students metrics and outputs the information to the screen
 */
void Simulation::calcStudentMetrics(){
  waitTimes.sort();
  int numWaitTimes = waitTimes.size();
  int medWaitTimeIndex = numWaitTimes / 2;
  int medWaitTime;
  int longestWaitTime = waitTimes.back();
  int longWaits=0;
  int waitSum=0;
  float meanWait;

  list<int>::iterator it = waitTimes.begin();
  int count = 0;
  for(int i = 0; i < numWaitTimes; i++)
  {
    if(i == medWaitTimeIndex)
    {
      medWaitTime =* it;
    }
    if(*it > 10){
      longWaits++;
    }
    waitSum +=* it;
    advance(it, 1);
  }
  meanWait = float(waitSum) /float(numWaitTimes);
  cout <<"\nMean Wait Time: "   << meanWait << endl;
  cout << "Median Wait Time: " << medWaitTime << endl;
  cout << "Longest Student Wait Time: " << longestWaitTime << endl;
  cout << "No. of students waiting > 10 ticks: " << longWaits << endl;
}


/*
 * This function checks the students idle time at the window
 */
void Simulation::checkIdle(Student win[], int t){
  if(t == 1)
  {
    for (int i = 0; i < numWindows; i++)
    {
      winIdleArr[i] = 0;
    }
  }else
  {
    for (int i = 0; i < numWindows; i++)
    {
      if(win[i].getNull() && t != 0)
      {
        winIdleArr[i] += 1;
      }
    }
  }
}


/*
 * This function sorts the window idle time
 */
void Simulation::sortIdle()
{
  for(int i = 0; i < numWindows; i++)
  {
        for(int j = 0; j < 2-i; j++)
        {
            if(winIdleArr[j] >winIdleArr[j+1]){
                int temp = winIdleArr[j];
                winIdleArr[j] = winIdleArr[j+1];
                winIdleArr[j+1] = temp;
            }
        }
    }
}


/*
 * This function prints the metrics for the idle wait times
 */
void Simulation::printIdleMetrics()
{
  sortIdle();
  int over5;
  over5 = 0;
  float idleSum = 0;
  for (int i = 0; i < numWindows; i++){
    idleSum += winIdleArr[i];
    if(winIdleArr[i] > 5){
      ++over5;
    }
  }
  cout << "Mean idle Time: "    << float (idleSum / numWindows) << endl;
  cout << "Longest Idle Time: " << winIdleArr[numWindows - 1] << endl;
  cout << "No. of windows idle > 5 ticks: " << over5 << endl;
}