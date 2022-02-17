#include <iostream>
#include "fraction.h"
using namespace std;

int main()
{
    Fraction x, y;

    cout << "Enter X: ";
    cin >> x;
	
    cout << "Enter Y: ";
    cin >> y;
	
    cout << endl;
    
    cout << "ADD: " << x+y << endl;
    cout << "SUB: " << x-y << endl;
    cout << "MUL: " << x*y << endl;
    cout << "DIV: " << x/y << endl;	
}