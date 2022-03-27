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
#include "Stack.h"

using namespace std;

// Constructor
template <typename T>
Stack<T>::Stack() {
    stackArray = new T[64];
    topOfStack = -1;
}


// Overloaded Constructor
template <typename T>
Stack<T>::Stack(int max) {
    stackArray = new T[max]; // used to create max size in main
    topOfStack = -1;
}


//Destructor
template <typename T>
Stack<T>::~Stack() {
    delete[] stackArray;
}


/* *********************************************************************************
 * Template for Push
 * ---------------------------------------------------------------------------------
 * this pushes the value to the top of the stack, if the stack is full it will
 * double the stack size
 * **********************************************************************************/
template <typename T>
void Stack<T>::push(T dataValue) {
    if(isFull())
    {
        T* newStackArray = new T[size * 2];
        for(int i = 0; i <= topOfStack; i++)
        {
            newStackArray[i] = stackArray[i];
        }
        delete[] stackArray;
        stackArray = newStackArray;
    }
    stackArray[++topOfStack] = dataValue;
}


/* *********************************************************************************
 * Template for Pop
 * ---------------------------------------------------------------------------------
 * this will remove elements from the stack and returns value that was removed
 * from the stack
 * **********************************************************************************/
template <typename T>
T Stack<T>::pop() {
    if(isEmpty())
    {
        cout << "Underflow, the stack is empty. " << endl;
        return 0;
    }
    return stackArray[topOfStack--];
}


/* *********************************************************************************
 * Template for isFull
 * ---------------------------------------------------------------------------------
 * this will check to see if the stack is full.
 * ---------------------------------------------------------------------------------
 * returns: 1 = true or 0 for false
 * **********************************************************************************/
template <typename T>
bool Stack<T>::isFull()
{
  if(topOfStack == (size-1))
    return true;
  else
    return false;
}


/* *********************************************************************************
 * Template for isEmpty
 * ---------------------------------------------------------------------------------
 * this will check to see if the stack is full.
 * ---------------------------------------------------------------------------------
 * returns: 1 = true or 0 for false
 * **********************************************************************************/
template <typename T>
bool Stack<T>::isEmpty() {
    if(topOfStack == -1)
      return true;
    else
      return false;
}
