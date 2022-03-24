#include <iostream>
#include <cassert>
#include "p2set1.h"
using namespace std;

int main()
{
    char A = 'A', B = 'B', C = 'C', D = 'D';
	
    Set<char> S;
    initialize(S);
    
    assert(S.size == 2);
    assert(S.count == 0);
    
    insert(S,A);
    
    assert(S.data[0] == A);
    assert(S.count == 1);
    assert(S.size == 2);
    
    insert(S,B);
    
    assert(S.data[0] == A && S.data[1] == B);
    assert(S.count == 2);
    assert(S.size == 2);
    
    insert(S,C);
    
    assert(S.data[0] == A && S.data[1] == B && S.data[2] == C);
    assert(S.count == 3);
    assert(S.size == 4);    
    
    assert( contains(S,A));
    assert( contains(S,B));
    assert( contains(S,C));
    assert(!contains(S,D));
    
    remove(S,A);
    
    assert(S.data[0] == C && S.data[1] == B);
    assert(S.count == 2);
    
    assert(!contains(S,A));
    assert( contains(S,B));
    assert( contains(S,C));
    assert(!contains(S,D));    
}