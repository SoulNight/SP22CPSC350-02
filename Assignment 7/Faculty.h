#include <iostream>
#include <string>
#include <list>

using namespace std;

/* *********************************************************************************
 * Base Class - Faculty
 * ---------------------------------------------------------------------------------
 * @param: none
 * **********************************************************************************/
class Faculty{
   public:
     Faculty();
     Faculty(int id, string name, string level, string dept);
     ~Faculty();
     int getId();
     void setId(int id);
     string getLevel();
     void setLevel(string lev);
     string getName();
     void setName(string name);
     string getDept();
     void setDept(string dept);
     void printInfo();
     void printFacToFile();
     list<int> getAdviseeID();
     void setAdviseeIDs(list<int> ids);
     void addAdvisee(int idToAdd);
     void remAdvisee(int idToRemove);
     bool operator<( Faculty& b);
     bool operator>( Faculty& b);
     bool operator==( Faculty& b);
     bool operator!=( Faculty& b);
private:
    int m_id;
    string m_name;
    string m_level;
    string m_dept;
    list<int> m_advIds;
 };
