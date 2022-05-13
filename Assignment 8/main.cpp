/* ********************************************************************************
 * Tony Bautista
 * Spring 22 CPSC 350
 * May 12, 2022
 * Assignment 8
 * -----------------------------------------------------------------------------
 * Sorting Algorithms
 * -----------------------------------------------------------------------------
 * This program takes in a text file via command line argument. The program will
 * parse the information using dynamic arrays using Merge, Bubble and Selection
 * Sort algorithm.
 * Each algorithm will individually sort the information and will then output
 * start time, stop time and elapsed time of the sort in milliseconds.
 * -----------------------------------------------------------------------------
 * This program contains: main.cpp, Sort.cpp, and Sort.h
 *  - you will have to provide command line argument for a text file to sort
 *    information.
 * ****************************************************************************/

#include <iostream>
#include <chrono>
#include "Sort.h"

using namespace std;

int main(int argc, char** argv) {

    // Object Creation
    Sort sortObjectClass;


    if(argc == 1) {
        cout << "Please provide a filename as a command argument" << endl;
        exit(0);
    }
    ifstream inputFile(argv[1]);
    int arraySize;
    inputFile >> arraySize;

    auto* mergeArray = new double[arraySize];
    auto* bubbleArray = new double[arraySize];
    auto* selectionArray = new double[arraySize];

    for(int i = 0; i < arraySize; i++)
    {
        string temp;
        getline(inputFile, temp);
        double info;
        inputFile >> info;
        mergeArray[i] = info;
        bubbleArray[i] = info;
        selectionArray[i] = info;
    }

    // Merge sort output
    auto clockStartMerge = clock();
    cout << "\nMerge Sort Start Time: " << (1000.0 * clockStartMerge)/CLOCKS_PER_SEC << " ms" << endl;
    sortObjectClass.mergeSort(mergeArray, 0, arraySize - 1);
    auto clockEndMerge = clock();
    cout << "Merge Sort End Time: " << (1000.0 * clockEndMerge)/CLOCKS_PER_SEC << " ms" << endl;
    cout << "Merge Sort Elapsed Runtime: " << (clockEndMerge - clockStartMerge) / 1000.0 << " ms" << endl << endl;

    // Bubble sort output
    auto clockStartBubble = clock();
    cout << "Bubble Sort Start Time: " << (1000.0 * clockStartBubble)/CLOCKS_PER_SEC << " ms" << endl;
    sortObjectClass.bubbleSort(bubbleArray, arraySize);
    auto clockEndBubble = clock();
    cout << "Bubble Sort End Time: " << (1000.0 * clockEndBubble)/CLOCKS_PER_SEC << " ms" << endl;
    cout << "Bubble Sort Elapsed Runtime: " << (clockEndBubble - clockStartBubble) / 1000.0 << " ms" << endl << endl;

    // Selection Sort output
    auto clockStartSelection = clock();
    cout << "Selection Sort Start Time: " << (1000.0 * clockStartSelection)/CLOCKS_PER_SEC << " ms" << endl;
    sortObjectClass.selectionSort(selectionArray, arraySize);
    auto clockEndSelection = clock();
    cout << "Selection Sort End Time: " << (1000.0 * clockEndSelection)/CLOCKS_PER_SEC << " ms" << endl;
    cout << "Selection Sort Elapsed Runtime: " << (clockEndSelection - clockStartSelection) / 1000.0 << " ms" << endl << endl;

    return 0;
}
