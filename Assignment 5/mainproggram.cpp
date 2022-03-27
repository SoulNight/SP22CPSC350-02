/* ********************************************************************************
 * Tony Bautista
 * Spring 22 CPSC 350-02
 * March 27, 2022
 * Assignment 5
 * ---------------------------------------------------------------------------------
 * This program uses a stack based on arrays to analyze source code written
 * in any language and reports the location of any mismatched delimiter; (), [] , {}.
 * The program analyzes one error at a time.
 * *********************************************************************************/
#include "AStack.cpp"
#include <fstream>

using namespace std;

int main (__attribute__((unused)) int argc, char** argv)
{
    string line;
    string usersFile = argv[1];
    char usersResponse;
    do
    {
        ifstream is(usersFile);
        if(is.fail())
        {
            cout << "Could not open " << usersFile << ". " << endl;
            exit(1); // exit failure, termination of program.
        }

        Stack<char> delimiter(100);
        int lineNumber = 0;
        while(!is.eof()) //
        {
            lineNumber++;
            getline(is, line);
            for(char analyzedDelimiter : line)
            {
                //Push inserts element into stack
                if(analyzedDelimiter == '(' || analyzedDelimiter == '{' || analyzedDelimiter == '[')
                {
                    delimiter.push(analyzedDelimiter); // call to delimiter push
                }

                //Pop removes element from stack
                if(analyzedDelimiter == ')' || analyzedDelimiter == '}' || analyzedDelimiter == ']')
                {
                    if(delimiter.isEmpty())
                    {
                     cout << "Error on line " << lineNumber << ": no opening delimiter found for closing delimiter " << analyzedDelimiter << endl;
                     exit(1); // exit failure, termination of program.
                    }

                    char poppedDelimeter = delimiter.pop();// call to delimiter pop
                    if(poppedDelimeter == '(')
                    {
                        if(analyzedDelimiter != ')')
                        {
                            cout << "Error on line " << lineNumber << ": expected ) and found " << analyzedDelimiter << endl;
                            exit(1);// exit failure, termination of program.
                        }
                    }
                    else if(poppedDelimeter == '{')
                    {
                        if(analyzedDelimiter != '}')
                        {
                            cout << "Error on line " << lineNumber << ": expected } and found " << analyzedDelimiter << endl;
                            exit(1);// exit failure, termination of program.
                        }
                    }
                    else if (poppedDelimeter == '[')
                    {
                        if(analyzedDelimiter != ']')
                        {
                            cout << "Error on line " << lineNumber << ": expected ] and found " << analyzedDelimiter << endl;
                            exit(1); // exit failure, termination of program.
                        }
                    }
                }
            }
        }
        if(delimiter.isEmpty()) // checks to see if stack is empty
        {
            cout << "No delimiter errors found in your file." << endl;
            cout << "Would you like to analyze another file? (y/n) ";
            cin >> usersResponse;
            cin.ignore(10000, '\n');
            if(usersResponse == 'y')
            {
                cout << "What is the name of the file you would like to analyze? ";
                getline(cin, usersFile);
            }
        }
        is.close();
    } while (usersResponse =='y');
    return 0;
}
