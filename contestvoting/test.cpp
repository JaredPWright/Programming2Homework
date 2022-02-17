#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main (){

    int testdouble = 0;

    ifstream names;

    names.open("names.txt");

    names >> testdouble;

    cout  << testdouble << endl;

    return 0;
}