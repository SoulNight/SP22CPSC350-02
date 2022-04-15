/* ********************************************************************************
 * Tony Bautista
 * Spring 22 CPSC 350
 * April 14, 2022
 * Assignment 6
 * ---------------------------------------------------------------------------------
 * This program is a called Registrar.The program will ask the user to input the
 * file name to parse information for the office the Registrar and
 * display it to the terminal.
 * --------------------------------------------------------------------------------
 * The information being parsed is the following:
 * 1. The mean student wait time
 * 2. The median student wait time
 * 3. The longest student wait time
 * 4. The number of students waiting over 10 minutes
 * 5. The mean window idle time
 * 7. Number of windows idle for over 5 minutes
 * *********************************************************************************/

#include "Simulation.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

  Simulation s(argv[1]);

  return 0;
}
