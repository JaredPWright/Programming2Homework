#include <iostream>
#include <cassert>
#include "p2stack1.h"
using namespace std;

int main()
{
    char A = 'A', B = 'B', C = 'C', popped;

    Stack<char> S;
    initialize(S);
    
    assert(S.top == 0);
    assert(isEmpty(S));
    assert(S.size == 2);
    
    push(S,A);
    assert(S.data[0] == A);
    assert(S.top == 1);
    assert(!isEmpty(S));
    
    push(S,B);
    assert(S.data[0] == A);
    assert(S.data[1] == B);
    assert(S.top == 2);
    
    push(S,C);
    assert(S.data[0] == A);
    assert(S.data[1] == B);
    assert(S.data[2] == C);
    assert(S.size == 4);
    assert(S.top == 3);
    
    popped = pop(S);
    cout << popped << ", " << C << endl;
    assert(popped == C);
    assert(S.data[0] == A);
    assert(S.data[1] == B);
    cout << S.top << endl;
    assert(S.top == 2);
    assert(S.size == 4);
    
    // Add more function calls and assertions 
}