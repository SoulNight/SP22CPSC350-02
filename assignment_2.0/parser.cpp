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

#include "parse.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Constructor
Parser::Parser()
{
    sum_alphabet = 0;
    non_alphabet_count = 0;
    sum_non_alphabet = 0;
    pair_count = 0;
    alphabet_average = 0.0;
    alphabet_count = 0;
    index = 0;

    // Alphabet variables
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    f = 0;
    g = 0;
    h = 0;
    i = 0;
    j = 0;
    k = 0;
    l = 0;
    m = 0;
    n = 0;
    o = 0;
    p = 0;
    q = 0;
    r = 0;
    s = 0;
    t = 0;
    u = 0;
    v = 0;
    w = 0;
    x = 0;
    y = 0;
    z = 0;

    // Non-alphabet variables
    a1 = 0;
    b2 = 0;
    c3 = 0;
    d4 = 0;
    e5 = 0;
    f6 = 0;
    g7 = 0;
    h8 = 0;
    i9 = 0;
    j10 = 0;
    k11 = 0;
    l12 = 0;
    m13 = 0;
    n14 = 0;
    o15 = 0;
    p16 = 0;
    q17 = 0;
    r18 = 0;
    s19 = 0;
    t20 = 0;
    u21 = 0;
    v22 = 0;
    w23 = 0;
    x24 = 0;
    y25 = 0;
    z26 = 0;
}

// DESTRUCTOR - these don't return values
Parser::~Parser(){

};

//implementation of member function
void Parser::requestInput(){
    // INPUT
    cout << "\nPlease enter in a string that consists only of letters and numbers: ";
    getline(cin, user_response);
}

//implementation of member function
void Parser::alphabetPairs() {
    for(int indexj = 0; indexj < user_response.length(); indexj++){
        if(user_response[indexj] == user_response[indexj + 1])
        {
            pair_count++;
        }
    }
}

//implementation of member function
void Parser::parseAlphabet() {

    // INPUT - for alphabet letters
    for (index = 0; index < user_response.length(); index ++){
        if(user_response[index] == 'a' || user_response[index] == 'A')
        {
            a++;
            alphabet_count++;
        }
    }

    for (index = 0; index < user_response.length(); index++){
        if(user_response[index] == 'b' || user_response[index] == 'B')
        {
            b++;
            alphabet_count++;
        }
    }

    for (index = 0; index < user_response.length(); index++){
        if(user_response[index] == 'c' || user_response[index] == 'C')
        {
            c++;
            alphabet_count++;
        }
    }

    for (index = 0; index < user_response.length(); index++){
        if(user_response[index] == 'd' || user_response[index] == 'D')
        {
            d++;
            alphabet_count++;
        }
    }
    for (index = 0; index < user_response.length(); index++){
        if(user_response[index] == 'e' || user_response[index] == 'E')
        {
            e++;
            alphabet_count++;
        }
    }

    for (index = 0; index < user_response.length(); index++){
        if(user_response[index] == 'f' || user_response[index] == 'F')
        {
            f++;
            alphabet_count++;
        }
    }

    for (index = 0; index < user_response.length(); index++){
        if(user_response[index] == 'g' || user_response[index] == 'G')
        {
            g++;
            alphabet_count++;
        }
    }

    for (index = 0; index < user_response.length(); index++){
        if(user_response[index] == 'h' || user_response[index] == 'H')
        {
            h++;
            alphabet_count++;
        }
    }
    for (index = 0; index < user_response.length(); index++){
        if(user_response[index] == 'i' || user_response[index] == 'I')
        {
            i++;
            alphabet_count++;
        }
    }

    for (index = 0; index < user_response.length(); index++){
        if(user_response[index] == 'j' || user_response[index] == 'J')
        {
            j++;
            alphabet_count++;
        }
    }

    for (index = 0; index < user_response.length(); index++){
        if(user_response[index] == 'k' || user_response[index] == 'K')
        {
            k++;
            alphabet_count++;
        }
    }

    for (index = 0; index < user_response.length(); index++){
        if(user_response[index] == 'l' || user_response[index] == 'L')
        {
            l++;
            alphabet_count++;
        }
    }
    for (index = 0; index < user_response.length(); index++){
        if(user_response[index] == 'm' || user_response[index] == 'M')
        {
            m++;
            alphabet_count++;
        }
    }

    for (index = 0; index < user_response.length(); index++){
        if(user_response[index] == 'n' || user_response[index] == 'N')
        {
            n++;
            alphabet_count++;
        }
    }

    for (index = 0; index < user_response.length(); index++){
        if(user_response[index] == 'o' || user_response[index] == 'O')
        {
            o++;
            alphabet_count++;
        }
    }

    for (index = 0; index < user_response.length(); index++){
        if(user_response[index] == 'p' || user_response[index] == 'P')
        {
            p++;
            alphabet_count++;
        }
    }

    for (index = 0; index < user_response.length(); index++){
        if(user_response[index] == 'q' || user_response[index] == 'Q')
        {
            q++;
            alphabet_count++;
        }
    }

    for (index = 0; index < user_response.length(); index++){
        if(user_response[index] == 'r' || user_response[index] == 'R')
        {
            r++;
            alphabet_count++;
        }
    }

    for (index = 0; index < user_response.length(); index++){
        if(user_response[index] == 's' || user_response[index] == 'S')
        {
            s++;
            alphabet_count++;
        }
    }

    for (index = 0; index < user_response.length(); index++){
        if(user_response[index] == 't' || user_response[index] == 'T')
        {
            t++;
            alphabet_count++;
        }
    }
    for (index = 0; index < user_response.length(); index++){
        if(user_response[index] == 'u' || user_response[index] == 'U')
        {
            u++;
            alphabet_count++;
        }
    }

    for (index = 0; index < user_response.length(); index++){
        if(user_response[index] == 'v' || user_response[index] == 'V')
        {
            v++;
            alphabet_count++;
        }
    }

    for (index = 0; index < user_response.length(); index++){
        if(user_response[index] == 'w' || user_response[index] == 'W')
        {
            w++;
            alphabet_count++;
        }
    }

    for (index = 0; index < user_response.length(); index++){
        if(user_response[index] == 'x' || user_response[index] == 'X')
        {
            x++;
            alphabet_count++;
        }
    }

    for (index = 0; index < user_response.length(); index++){
        if(user_response[index] == 'y' || user_response[index] == 'Y')
        {
            y++;
            alphabet_count++;
        }
    }

    for (index = 0; index < user_response.length(); index++){
        if(user_response[index] == 'z' || user_response[index] == 'Z')
        {
            z++;
            alphabet_count++;
        }
    }

    alphabetPairs();

    // CALCULATIONS
    alphabet_average = alphabet_count / 26.0;
    sum_alphabet = a + b + c + d + e + f + g + h + i + j + k + l + m + n + o + p + q + r + s + t + u + v +
                   w + x + y + z;
}

//implementation of member function
void Parser::parseNonAlphabet(){
    // INPUT - for non-alphabet letters
    for (char response: user_response){
        if(response == '!')
        {
            a1++;
            non_alphabet_count++;
        }
    }

    for (char response : user_response){
        if(response == '@')
        {
            b2++;
            non_alphabet_count++;
        }
    }
    for (char response : user_response){
        if(response == '#')
        {
            c3++;
            non_alphabet_count++;
        }
    }
    for (char response : user_response){
        if(response == '$')
        {
            d4++;
            non_alphabet_count++;
        }
    }
    for (char response : user_response){
        if(response == '%')
        {
            e5++;
            non_alphabet_count++;
        }
    }

    for (char response : user_response){
        if(response == '^')
        {
            f6++;
            non_alphabet_count++;
        }
    }
    for (char response : user_response){
        if(response == '&')
        {
            g7++;
            non_alphabet_count++;
        }
    }

    for (char response : user_response){
        if(response == '*')
        {
            h8++;
            non_alphabet_count++;
        }
    }

    for (char response : user_response){
        if(response == '(')
        {
            i9++;
            non_alphabet_count++;
        }
    }

    for (char response : user_response){
        if(response == ')')
        {
            j10++;
            non_alphabet_count++;
        }
    }

    for (char response : user_response){
        if(response == '-')
        {
            k11++;
            non_alphabet_count++;
        }
    }

    for (char response : user_response){
        if(response == '=')
        {
            l12++;
            non_alphabet_count++;
        }
    }

    for (char response : user_response){
        if(response == '_')
        {
            m13++;
            non_alphabet_count++;
        }
    }

    for (char response : user_response){
        if(response == '+')
        {
            n14++;
            non_alphabet_count++;
        }
    }

    for (char response : user_response){
        if(response == '`')
        {
            o15++;
            non_alphabet_count++;
        }
    }

    for (char response : user_response){
        if(response == '~')
        {
            p16++;
            non_alphabet_count++;
        }
    }

    for (char response : user_response){
        if(response == ',')
        {
            q17++;
            non_alphabet_count++;
        }
    }
    for (char response : user_response){
        if(response == '.')
        {
            r18++;
            non_alphabet_count++;
        }
    }

    for (char response : user_response){
        if(response == '/')
        {
            s19++;
            non_alphabet_count++;
        }
    }

    for (char response : user_response){
        if(response == '<')
        {
            t20++;
            non_alphabet_count++;
        }
    }

    for (char response : user_response){
        if(response == '>')
        {
            u21++;
            non_alphabet_count++;
        }
    }
    for (char response : user_response){
        if(response == '?')
        {
            v22++;
            non_alphabet_count++;
        }
    }

    for (char response : user_response){
        if(response == ';')
        {
            w23++;
            non_alphabet_count++;
        }
    }

    for (char response : user_response){
        if(response == ':')
        {
            x24++;
            non_alphabet_count++;
        }
    }

    for (char response : user_response){
        if(response == ' ')
        {
            y25++;
            non_alphabet_count++;
        }
    }

    for (char response : user_response){
        if(response == '|')
        {
            z26++;
            non_alphabet_count++;
        }
    }
    sum_non_alphabet = a1 + b2 + c3 + d4 + e5 + f6 + g7 + h8 + i9 + j10 + k11 + l12 + m13 + n14 +
                       o15 + p16 + q17 + r18 + s19 + t20 + u21 + v22 + w23 + x24 + y25 + z26;
}


void Parser::outputToConsole(){
    //OUTPUT - single letter
    cout << "\nYour string consists of: " << endl;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;
    cout << "d: " << d << endl;
    cout << "e: " << e << endl;
    cout << "f: " << f << endl;
    cout << "g: " << g << endl;
    cout << "h: " << h << endl;
    cout << "i: " << i << endl;
    cout << "j: " << j << endl;
    cout << "k: " << k << endl;
    cout << "l: " << l << endl;
    cout << "m: " << m << endl;
    cout << "n: " << n << endl;
    cout << "o: " << o << endl;
    cout << "p: " << p << endl;
    cout << "q: " << q << endl;
    cout << "r: " << r << endl;
    cout << "s: " << s << endl;
    cout << "t: " << t << endl;
    cout << "u: " << u << endl;
    cout << "v: " << v << endl;
    cout << "w: " << w << endl;
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    cout << "z: " << z << endl;

    // OUTPUT - sums
    cout << "\nAlphabets: " << sum_alphabet << endl;
    cout << "Non-alphabets: " << sum_non_alphabet << endl;
    cout << setprecision(6) << "Average: " << alphabet_average << endl;
    cout << "Pairs: " << pair_count << endl;
}

bool Parser::save(const string& fileName){
    ofstream ofsNumbers; // declaring variable of ofsNumber

    ofsNumbers.open(fileName); //

    if (!ofsNumbers.is_open()){
        cout << "Failed to open the file." << endl;
        return false;
    }

    //output list of data
    ofsNumbers << "\na: " << a << endl;
    ofsNumbers << "b: " << b << endl;
    ofsNumbers << "c: " << c << endl;
    ofsNumbers << "d: " << d << endl;
    ofsNumbers << "e: " << e << endl;
    ofsNumbers << "f: " << f << endl;
    ofsNumbers << "g: " << g << endl;
    ofsNumbers << "h: " << h << endl;
    ofsNumbers << "i: " << i << endl;
    ofsNumbers << "j: " << j << endl;
    ofsNumbers << "k: " << k << endl;
    ofsNumbers << "l: " << l << endl;
    ofsNumbers << "m: " << m << endl;
    ofsNumbers << "n: " << n << endl;
    ofsNumbers << "o: " << o << endl;
    ofsNumbers << "p: " << p << endl;
    ofsNumbers << "q: " << q << endl;
    ofsNumbers << "r: " << r << endl;
    ofsNumbers << "s: " << s << endl;
    ofsNumbers << "t: " << t << endl;
    ofsNumbers << "u: " << u << endl;
    ofsNumbers << "v: " << v << endl;
    ofsNumbers << "w: " << w << endl;
    ofsNumbers << "x: " << x << endl;
    ofsNumbers << "y: " << y << endl;
    ofsNumbers << "z: " << z << endl;
    ofsNumbers << "\nAlphabets: "<< alphabet_count << endl;
    ofsNumbers << "Non-alphabets: " << non_alphabet_count << endl;
    ofsNumbers << "Average: " << alphabet_average << endl; // writes info to file
    ofsNumbers << "Pairs: " << pair_count << endl;
    ofsNumbers.close();

    return true;// if succeeds returns true
}
