
#include "Stack.h"
#include <iostream>
#include <stdexcept>

using namespace std;

/* *********************************************************************************
 *  Template Base Class - AStack
 *  is the blueprint for the Stack datatype implemented using an array.
 *  it contains the methods and variables that will be implemented in the class
 * ---------------------------------------------------------------------------------
 * @param: none
 * **********************************************************************************/
template <typename E>
class AStack: public Stack<E>{
public:
  AStack(int sz);
  ~AStack();
  void clear();
  void push(const E& item);
  E pop();
  E* topVal();
  int length();
  int getSize();

private:
    int top;
    int size; //max size
    int len; //current length
    E* stackArray; // pointer of type E (will become the array)

    void arrayDuplicator();

};


/*
AStack()
Default constructor for AStack takes size as parameter and initializes variables
@param (int size)
@return void
*/
template <typename E>
AStack<E>::AStack(int sz){
  len=0;
  top= -1;
  size= sz;
  stackArray= new E[sz];
}


/*
~AStack()
clears and deletes array

*/
template <typename E>
AStack<E>::~AStack(){
  clear();
  delete[] stackArray;
}


/*
processFile()
Deletes array, and Reinitializes 1 of the same size
@param: (none)
@return: void
*/
template <typename E>
void AStack<E>::clear(){
  delete[] stackArray;
  stackArray= new E[size];
  top= -1;
  len=0;
}


/*
push()
Takes in an item of generic type E and adds it to stack, calls arrayDuplicator if extra room is needed
@param (const E& item, string )
@return void
*/
template <typename E>
void AStack<E>::push(const E& item){
  if(len>=size){
    arrayDuplicator();
  }
  stackArray[++top]=item;
  len++;
}


/*
 * TopVal - array returns the value from top of the stack
 * @param: none
 * @return: stackArray
 */
template <typename E>
E* AStack<E>::topVal(){
  return stackArray[top];
}


/*
getSize()
Returns maxSize of array, used for debugging
@param (none)
@return (none)
*/
template <typename E>
int AStack<E>::getSize(){
  return size;
}


/*
arrayDuplicator()
This function resizes the array if more room is needed. if needed, this function
creates a new array 2 times the size of the previous.
@param (none)
@return (none)
*/
template <typename E>
void AStack<E>::arrayDuplicator(){
    E* temp = stackArray;
    delete[] stackArray;
    stackArray = new E[size*2];
    for(int i =0; i<len; i++){
      stackArray[i]=temp[i];
    }
    size=size*2;
  }

  /*
  pop()
  returns the top element of the stack
  @param (string inputName, string outputName)
  @return E item representing top of stack.
  */
template <typename E>
E AStack<E>::pop(){
      E item = stackArray[top];
      top--;
      len--;
      return item;
}
/*
length()
returns the current count of items in the stack, used mostly for debugging.
@param
@return int length.
*/
template <typename E>
int AStack<E>::length(){
  return len;
}
