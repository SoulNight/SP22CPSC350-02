/* ********************************************************************************
 * Tony Bautista
 * Spring 22 CPSC 350-02
 * February 10, 2022
 * ---------------------------------------------------------------------------------
 * This program will ask the user for a price then calculate the total price of
 * all the items.
 * *********************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    // Declaration - of variables
    float item_price = 0.0;
    float total_cost = 0.0;

    // INPUT - from user
    do{
        cout << "Enter in the price of an item: (Enter a negative number to exit): $";
        cin >> item_price;

        if(item_price >= 0)
        {
            total_cost += item_price;
        }
    }while(item_price >=0);

    // OUTPUT - to user screen
    cout << endl;
    cout << "Total cost of the items entered is: $";
    cout << fixed << setprecision(2) << total_cost << endl;

    return 0;
}
