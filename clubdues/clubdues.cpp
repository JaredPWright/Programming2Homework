#include <iostream>
#include <fstream>
#include "p2set.h"
using namespace std;

int main()
{
    int olddues = 0, newdues = 0;
    int currentmembers = 0, memberslisted;
    string intakestring;
    string junkstring;
    string filename1 = "8A_past.txt"; 
    string filename2 = "8A_new.txt";

    Set<string> memberset;
    initialize(memberset);

    ifstream oldfin;
    ifstream newfin;
    
    oldfin.open(filename1.c_str());
    for(int i = 0; i < 2; i++)
        oldfin >> junkstring;
    oldfin >> memberslisted;

    getline(oldfin, junkstring);
    for(int i = 0; i < memberslisted; i++){
        getline(oldfin, intakestring);
        insert(memberset, intakestring);
        currentmembers++;
    }

    newfin.open(filename2.c_str());
    for(int i = 0; i < 2; i++)
        newfin >> junkstring;
    newfin >> memberslisted;

    getline(newfin, intakestring);
    for(int i = 0; i < memberslisted; i++){
        getline(newfin, intakestring);
        if(!contains(memberset, intakestring)){
            newdues += 80;
            currentmembers++;
        }else
            olddues += 62;
    }
    
    oldfin.close();
    newfin.close();
    
    cout << "Old Member Dues: $" << olddues << endl;
    cout << "New Member Dues: $" << newdues << endl;
    cout << "Total expected:  $" << newdues + olddues << endl;
    cout << endl;
    cout << "Two-year membership: " << currentmembers << endl;

    destroy(memberset);

    return 0;
}