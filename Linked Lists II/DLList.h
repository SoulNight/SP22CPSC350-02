// doubly linked list template class

#include "ListNode.h"

template <typename E>
class DLList{
private:
  ListNode<E>* head; // pointer to front of list
  ListNode<E>* tail; // pointer to back of list
  int size; // number of elements in list

public:
  DLList();
  ~DLList();
  void insertFront(E item);
  void insertBack(E item);
  E removeFront();
  E removeBack();
  E peekFront();
  E peekBack();
  int length();
  bool isEmpty();
};

/*
Constructor for DLList.
*/
template <typename E>
DLList<E>::DLList(){
  // ADD CODE HERE
}

/*
Destructor for DLList.
*/
template <typename E>
DLList<E>::~DLList(){
  // ADD CODE HERE
}

/*
insertFront
Function inserts a list node to the front of the list.
@param item: item value to be inserted.
*/
template <typename E>
void DLList<E>::insertFront(E item){
  // ADD CODE HERE
}

/*
insertBack
Function inserts a list node to the back of the list.
@param item: item value to be inserted.
*/
template <typename E>
void DLList<E>::insertBack(E item){
  // ADD CODE HERE
}

/*
removeFront
Function removes a list node from the front of the list.
@return: item value at front.
*/
template <typename E>
E DLList<E>::removeFront(){
  // ADD CODE HERE
}


/*
removeBack
Function removes a list node from the back of the list.
@return: item value at back.
*/
template <typename E>
E DLList<E>::removeBack(){
  // ADD CODE HERE
}

/*
peekFront
Function returns the data value at front of list
@return: item value at front.
*/
template <typename E>
E DLList<E>::peekFront(){
  // ADD CODE HERE
}

/*
peekBack
Function returns the data value at the back of list
@return: item value at back.
*/
template <typename E>
E DLList<E>::peekBack(){
  // ADD CODE HERE
}

/*
length
Function returns the size of the list.
@return: size of list.
*/
template <typename E>
int DLList<E>::length(){
  // ADD CODE HERE
}


/*
length
Function returns if list is empty or not by checking size.
@return: T/F.
*/
template <typename E>
bool DLList<E>::isEmpty(){
  // ADD CODE HERE
}
