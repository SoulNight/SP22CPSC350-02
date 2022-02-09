/* ********************************************************************************
 * Tony Bautista
 * Spring 22 CPSC 350-02
 * February 10, 2022
 * ---------------------------------------------------------------------------------
 * This program asks the user to input three ages and determines the youngest and
 * oldest age of the entered values.
 * *********************************************************************************/

#include <iostream>
using namespace std;

int main() {
    // DECLARATION - of variables
    int array_size = 3;
    int array_ages[3];
    int oldest_age;
    int youngest_age;

    // INPUT - of ages
    cout << "\nEnter in the ages of " << array_size << " people" << endl;

    // For loop tha stores the ages in an array
    for (int i = 0; i < array_size; ++i) {
       cout << "Age: ";
       cin >> array_ages[i];
    }

    // Determines the youngest age
    youngest_age = array_ages[0]; // assigns youngest age to element 0
    for (int i = 0; i < array_size; ++i)
    {
       if (array_ages[i] < youngest_age)
       {
          youngest_age = array_ages[i];
       }
    }

    // Determines the oldest age
    oldest_age = array_ages[0]; // assigns oldest age to element 0
    for (int i = 0; i < array_size; ++i)
    {
       if (array_ages[i] > oldest_age)
       {
          oldest_age = array_ages[i];
       }
    }

    // OUTPUT - of ages
    cout << "\nThe youngest is age " << youngest_age << " years old." << endl;
    cout << "The oldest is age"     << oldest_age   << " years old." << endl;

   return 0;
}
