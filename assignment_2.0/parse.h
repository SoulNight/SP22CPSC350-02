/* ********************************************************************************
 * Tony Bautista
 * Spring 22 CPSC 350-02
 * February 17, 2022
 * Assignment 2
 * ---------------------------------------------------------------------------------
 * This program asks the user to input any letter or set of letters, and any non
 * letter. The program will output the letter count, how many alphabet letters, how
 * many non-alphabets, the average letters, and how many pairs of letters.
 * *********************************************************************************/

#include <string>
using namespace std;

#ifndef ASSIGNMENT_2_0_PARSE_H
#define ASSIGNMENT_2_0_PARSE_H

// //////////////////////////////////////////////////////////////////////////////////////////////
// Base Class Parser
// //////////////////////////////////////////////////////////////////////////////////////////////

class Parser{

public:
    Parser();   // Constructor
    ~Parser();  // Destructor

    // Member Function Prototypes
    void requestInput();
    void parseAlphabet();
    void parseNonAlphabet();
    void outputToConsole();
    void alphabetPairs();
    bool save(const string& fileName);

private:
    // Declaration - variables
    string user_response;
    int sum_alphabet;
    int non_alphabet_count;
    int sum_non_alphabet;
    int pair_count;
    int index;
    double alphabet_average;
    int alphabet_count;

    // alphabet variables
    int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;

    // non-alphabet variables
    int a1, b2, c3, d4, e5, f6, g7, h8, i9, j10, k11, l12, m13, n14, o15, p16, q17, r18, s19,
            t20, u21, v22, w23, x24, y25, z26;
};// TERMINATES THE DECLARATION OF THE CLASS

#endif //ASSIGNMENT_2_0_PARSE_H
