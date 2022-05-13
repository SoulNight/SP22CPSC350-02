#include "Sort.h"
#include <iostream>
#include <string>

using namespace std;

/*
 * Default Constructor
 */
Sort::Sort() {

}

/*
 * Destructor
 */
Sort::~Sort() {

}


/* *****************************************************************************
 * Implementation of a member function - BubbleSort
 * -----------------------------------------------------------------------------
 * This function will sort the file information using Bubble sort algorithm
 * -----------------------------------------------------------------------------
 * @param: myArray[], size
 * returns: none
 * ****************************************************************************/
void Sort::bubbleSort(double myArray[], int size) {
    double temp;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size - 1; j++)
        {
            if(myArray[j] > myArray[j +1])
            {
                temp = myArray[j + 1];
                myArray[j + 1 ] = myArray[j];
                myArray[j] = temp;
            }
        }
    }
}


/* *****************************************************************************
 * Implementation of a member function - SelectionSort
 * -----------------------------------------------------------------------------
 * This function will sort the file information using Selection Sort Algorithm
 * -----------------------------------------------------------------------------
 * @param: myArray[], size
 * returns: none
 * ****************************************************************************/
void Sort::selectionSort(double myArray[], int size) {
    int minIndex;
    double temp;
    for(int i = 0; i < size; i++)
    {
        minIndex = i;
        for(int j = i + 1; j < size; j++)
        {
            if(myArray[j] < myArray[minIndex])
            {
                minIndex = j;
            }
        }
        if(minIndex != i)
        {
            temp = myArray[i];
            myArray[i] = myArray[minIndex];
            myArray[minIndex] = temp;
        }
    }
}

/* *****************************************************************************
 * Implementation of a member function - MergeSort
 * -----------------------------------------------------------------------------
 * This function will sort the file information using Merge sort
 * -----------------------------------------------------------------------------
 * @param: myArray[], m, size
 * returns: none
 * ****************************************************************************/
void Sort::mergeSort(double myArray[], int m, int last){

    int middle = 0;

    if(m < last){
        middle = (m + last) / 2;

        mergeSort(myArray, m, middle);
        mergeSort(myArray, middle + 1, last);
        merge(myArray, m, middle, last);
    }
}

/* *****************************************************************************
 * Implementation of a member function - Merge
 * -----------------------------------------------------------------------------
 * This function will merge the information from the sub-arrays
 * -----------------------------------------------------------------------------
 * @param: myArray[], m, middle, last
 * returns: none
 * ****************************************************************************/
void Sort::merge(double myArray[], int m, int middle, int last) {
    int newSize = last - m + 1;
    int currPos = 0;
    int left = 0;
    int right = 0;

    double* merged = new double[newSize];
    left = m;
    right = middle + 1;

    while(left <= middle && right <= last)
    {
        if(myArray[left] <= myArray[right])
        {
            merged[currPos] = myArray[left];
            left++;
        }
        else
        {
            merged[currPos] = myArray[right];
            right++;
        }
        currPos++;
    }
    while(left <= middle)
    {
        merged[currPos] = myArray[left];
        left++;
        currPos++;
    }
    while(right <= last)
    {
        merged[currPos] = myArray[right];
        right++;
        currPos++;
    }
    for(currPos = 0; currPos < newSize; currPos++)
    {
        myArray[m + currPos] = merged[currPos];
    }
}


/* *****************************************************************************
 * Implementation of a member function - Print
 * -----------------------------------------------------------------------------
 * This function was used to see if the info from the files was getting sorted
 *  - note: to use function change the for loop to adjust for file line size
 *  -
 * -----------------------------------------------------------------------------
 * @param: myArray[]
 * returns: none
 * ****************************************************************************/
void Sort::printArray(double myArray[]){
    for (int i = 0; i < 1000; i++){
        cout << myArray[i] << endl;
    }
}
