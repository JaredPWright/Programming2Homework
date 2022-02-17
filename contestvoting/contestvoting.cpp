#include <iostream>
#include <fstream>
#include <iomanip>
#include "p2queue.h"
#include "p2priorityqueue.h"
#include "p2map.h"
using namespace std;

int main (){
    int numcontestants = 0;
    int numvotes = 0;

    ifstream confin, votefin;

    Queue<string> contestants;
    Map<string, int> votes;
    Map<string, int> timesvoted;
    PriorityQueue<string, int> sortingpqueue;

    initialize(contestants);
    initialize(votes);
    initialize(timesvoted);
    initialize(sortingpqueue);

    //perform input operations on the contestants. 
    confin.open("names");
    votefin.open("votes");

    confin >> numcontestants;

    string tempstring;
    getline(confin, tempstring);
    for(int i = 0; i < numcontestants; i++){
        getline(confin, tempstring);
        push(contestants, tempstring);
        assign(votes, tempstring, 0);
    }

    int vvotebump;
    int cvotebump;
    int votestallied = 0;

    votefin >> numvotes;

    for(int i = 0; i < numvotes; i++){
        string voterphone;
        votefin >> tempstring;
        votefin >> voterphone;
        if(has_key(timesvoted, voterphone)){
            if(lookup(timesvoted, voterphone) < 4){
                vvotebump = lookup(timesvoted, voterphone) + 1;
                cvotebump = lookup(votes, tempstring) + 1;
                assign(timesvoted, voterphone, vvotebump);
                assign(votes, tempstring, cvotebump);
                votestallied++;
            }else
                continue;
        }else{
            assign(timesvoted, voterphone, 1);
            cvotebump = lookup(votes, tempstring) + 1;
            assign(votes, tempstring, cvotebump);
            votestallied++;
        }
    }

    for(int i = 0; i < numcontestants; i++){
        string junkstring = pop(contestants);
        int tempvotes = lookup(votes, junkstring);
        push(sortingpqueue, junkstring, tempvotes);
    }

    cout << "Final rankings\n";

    for(int i = 0; i < numcontestants; i++){
        string junkstring = pop(sortingpqueue);

        double thingum = lookup(votes, junkstring);
        double percentageofvote = 0.0;
        
        percentageofvote = (thingum / votestallied) * 100.0;

        cout <<fixed<< setprecision(1) << percentageofvote << "% " << junkstring << endl;
    }

    confin.close();
    votefin.close();

    destroy(contestants);
    destroy(votes);
    destroy(timesvoted);
    destroy(sortingpqueue);

    return 0;
}