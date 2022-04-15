#include "ListNode.h"
#include <iostream>

template <typename E>
class DLList{
public:
    DLList();
    ~DLList();
    void insertFront(E item);
    void insertBack(E item);
    void clear();
    E removeFront();
    E removeBack();
    E peekFront();
    E peekBack();
    int length();
    bool isEmpty();
private:
    ListNode<E>* head; // pointer to front of list
    ListNode<E>* tail; // pointer cto back of list
    int size; // number of elements in list
};

/*
Constructor for DLList.
*/
template <typename E>
DLList<E>::DLList(){
  size = 0;
  head = nullptr;
  tail = nullptr;
}

/*
Destructor for DLList.
*/
template <typename E>
DLList<E>::~DLList(){
  ListNode<E>* temp = head;
  if(size != 0)
  {
    while(head != nullptr)
    {
      temp = head;
      head = head->next;
      delete temp;
    }
  }
}

/*
Template for Clear
Function clears the temp node
@param item: none
*/
template <typename E>
void DLList<E>::clear(){
  ListNode<E>* temp = head;
  while(head != nullptr){
    temp = head;
    head = head->next;
    delete temp;
  }
}


/*
Template for insertFront
Function inserts a list node to the front of the list.
@param item: item value to be inserted.
*/
template <typename E>
void DLList<E>::insertFront(E item){
  auto* temp = new ListNode<E>(item);
  if(size == 0)
    tail = temp;
  else
  {
    head->prev = temp;
    temp->next = head;
    }
  head = temp;
  size++;
}


/*
Template for insertBack
Function inserts a list node to the back of the list.
@param item: item value to be inserted.
*/
template <typename E>
void DLList<E>::insertBack(E item){
  auto* temp = new ListNode<E>(item);
  if(size == 0)
    head = temp;
  else
  {
    tail->next = temp;
    temp->prev = tail;
    }
  tail = temp;
  size++;
}


/*
Template for removeFront
Function removes a list node from the front of the list.
@return: item value at front.
*/
template <typename E>
E DLList<E>::removeFront(){
  ListNode<E>* temp = head;
  if(head->next == nullptr){
    tail = nullptr;
  }else
  {
    head->next->prev = nullptr;
    head = head->next;
  }
  E item = temp->element;
  temp->next = nullptr;
  delete temp;
  size--;
  return item;
}


/*
Template for removeBack
Function removes a list node from the back of the list.
@return: item value at back.
*/
template <typename E>
E DLList<E>::removeBack(){
  ListNode<E>* temp = tail;
  if(tail->prev == nullptr){
    head = nullptr;
  }
  else
  {
    tail->prev->next = nullptr;
    tail = tail->prev;
  }
  E item = temp->element;
  temp->prev = nullptr;
  delete temp;
  size--;
  return item;
}


/*
Template for peekFront
Function returns the data value at front of list
@return: item value at front.
*/
template <typename E>
E DLList<E>::peekFront(){
  return head->element;
}


/*
Template for peekBack
Function returns the data value at the back of list
@return: item value at back.
*/
template <typename E>
E DLList<E>::peekBack(){
  return tail->element;
}


/*
Template for length
Function returns the size of the list.
@return: size of list.
*/
template <typename E>
int DLList<E>::length(){
  return size;
}


/*
Template for length
Function returns if list is empty or not by checking size.
@return: T/F.
*/
template <typename E>
bool DLList<E>::isEmpty(){
  return (size==0);
}
