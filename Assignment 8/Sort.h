/* *****************************************************************************
 *  Base Class - Sort
 * -----------------------------------------------------------------------------
 *  Sort is the blueprint for the member function that will sort your file
 *  information.
 * ****************************************************************************/
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

class Sort{
public:
    Sort();
    ~Sort();
    void bubbleSort(double myArray[], int size);
    void selectionSort(double myArray[], int size);
    void mergeSort(double myArray[], int m, int last);
    void merge(double myArray[], int m, int middle, int last);
    void printArray(double *myArray);
};
