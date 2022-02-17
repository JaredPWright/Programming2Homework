#include <iostream>
#include <fstream>
#include "p2queue.h"
#include "p2priorityqueue.h"
using namespace std;

int main()
{
    PriorityQueue<string, int> cs332;
    PriorityQueue<string, int> cs352;
    PriorityQueue<string, int> cs365;

    initialize(cs332);
    initialize(cs352);
    initialize(cs365);

    string filename;
    //prompt user for filename
    cout << "Filename: ";
    //get filename
    cin >> filename;
    cout << endl;

    //open input file
    ifstream fin;
    fin.open(filename);

    ofstream cs332out;
    ofstream cs352out;
    ofstream cs365out;

    cs332out.open("CS332");
    cs352out.open("CS352");
    cs365out.open("CS365");


    string headername;
    //read in the class id
    while(fin >> headername)
    {
        string studentid;
        int value;
        fin >> studentid;
        fin >> value;
        if(headername == "CS332")
            push(cs332, studentid, value);
        else if (headername == "CS352")
            push(cs352, studentid, value);
        else
            push(cs365, studentid, value);
    }

    
    if(cs332out.is_open())
    {
        while(!isEmpty(cs332))
            cs332out << pop(cs332) << endl;
    }
    
    if(cs352out.is_open())
    {
        while(!isEmpty(cs352))
            cs352out << pop(cs352) << endl;
    }
    
    if(cs365out.is_open())
    {
        while(!isEmpty(cs365))
            cs365out << pop(cs365) << endl;
    }
    
    //open output files
    //for each of, pop until pq empty
    fin.close();

    cs332out.close();
    cs352out.close();
    cs365out.close();

    destroy(cs332);
    destroy(cs352);
    destroy(cs365);

    return 0;
}