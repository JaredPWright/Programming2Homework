#include <iostream>
#include "p2queue.h"
#include "p2priorityqueue.h"
#include "p2stack.h"
using namespace std;

int main ()
{
    Queue<int> testqueue;
    PriorityQueue<int, int> ptestqueue;
    Stack<int> teststack;

    initialize(testqueue);
    initialize(ptestqueue);
    initialize(teststack);

    bool queuebool = true;
    bool pqueuebool = true;
    bool stackbool = true;

    string cmnd;
    int number;

    cout << "Command: ";
    cin >> cmnd;
    cout << endl;
    while(cmnd != "END")
    {
        if(cmnd == "PUSH")
        {
            cin >> number;
            push(testqueue, number);
            push(ptestqueue, number, number);
            push(teststack, number);
        }else if(cmnd == "POP"){
            cin >> number;
            if(pop(testqueue) != number)
                queuebool = false;

            if(pop(ptestqueue) != number)
                pqueuebool = false;

            if(pop(teststack) != number)
                stackbool = false;
        }else
            cout << "Error. Please input the proper commands.\n";

        cout << "Command: ";
        cin >> cmnd;
        cout << endl;
    }

    if(queuebool){
        if(pqueuebool)
            cout << "The black box remains mysterious.\n";
        else if(stackbool)
            cout << "The black box remains mysterious.\n";
        else
            cout << "The black box holds a queue.\n";
    }else if (pqueuebool){
        if(stackbool)
            cout << "The black box remains mysterious.\n";
        else
            cout << "The black box holds a priority queue.\n";
    }else if(stackbool){
        cout << "The black box holds a stack.\n";
    }else
        cout << "The black box holds something else.\n";

    destroy(ptestqueue);
    destroy(testqueue);
    destroy(teststack);

    return 0;
}