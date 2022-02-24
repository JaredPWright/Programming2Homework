#include <iostream>
#include "p2queue2.h"
using namespace std;

int main ()
{
// push 3, pop 2, push 1, pop 1, push 3, pop 2, push 1, pop 3 [now empty]
    double A = 1.1, B = 2.3, C = 3.03, D = 4.14, E = 5.16, F = -6.5, G = 7.0, H = 8.2, V;
    Queue<double> Q;
    initialize(Q);
    // push 3
    push(Q,A);
    push(Q,B);
    push(Q,C);
    // pop 2
    V = pop(Q);
    V = pop(Q);
    // push 1
    push(Q,D);
    // pop 1
    V = pop(Q);
    // push 3
    push(Q,E);
    push(Q,F);
    push(Q,G);

    cout << Q.tail << endl;
    cout << getSize(Q) << endl;
    cout << isEmpty(Q) << endl;
    return 0;
}