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

#include <iostream>
#ifndef Stack_H
#define Stack_H

template <typename T>
class Stack
{
public:
    int size{};
    int topOfStack;
    T *stackArray;
    T pop();
    bool isFull();
    bool isEmpty();
    Stack<T>();
    explicit Stack<T>(int max);
    ~Stack<T>();
    void push(T dataValue);
};
#endif 
