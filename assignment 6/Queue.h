#include "DLList.h"

template<typename E>
class Queue {
public:
  Queue();
  virtual ~Queue();
  virtual void clear();
  virtual void enqueue(const E& item);
  virtual E dequeue();
  virtual E frontValue();
  virtual int length();
  DLList<E> qList;
private:
};


/*
Template Constructor for Queue
*/
template<typename E>
Queue<E>::Queue(){
  clear(); // reinitialized the queue
}


/*
Template Destructor for DLList.
*/
template<typename E>
Queue<E>::~Queue(){
}


/*
Template for Clear
Function clears the Queue
@param item: none
*/
template<typename E>
void Queue<E>::clear(){
  qList.clear();
}


/*
Template for enqueue
Function places element at the end of the Queue
@param item: element being enqueued
*/
template<typename E>
void Queue<E>::enqueue(const E& item){
  qList.insertBack(item);
}


/*
Template for Clear
Function removes and return the element at the front of the queue
@param item: none
@return: removesFront; element at the front
*/
template<typename E>
E Queue<E>::dequeue(){
  if(qList.isEmpty()){
    return E();
  }
  return qList.removeFront();
}


/*
Template for frontValue
Function returns a copy of the front element
@param item: none
@returns: data at E or peeks at front of queue
*/
template<typename E>
E Queue<E>::frontValue(){
  if(qList.isEmpty()){
    return E();
  }
  return qList.peekFront();
}


/*
Template for length
Function gives length of queue
@param item: none
@return: length: the number of elements in the queue of queue
*/
template<typename E>
int Queue<E>::length(){
  return qList.length();
}
