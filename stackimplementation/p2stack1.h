#include <cstddef>
using namespace std;

template <class T>
struct Stack{
    T* data;
    int size;
    int top;
};

template <class T>
void initialize(Stack<T>& newstack){
    T *Array = new T[2];
    newstack.data = Array;
    newstack.size = 2;
    newstack.top = 0;
}

template <class T>
void destroy(Stack<T>& userstack){
    delete [] userstack.data;
    userstack.data = NULL;
    userstack.size = 0;
    userstack.top = 0;
}

template <class T>
bool isEmpty(Stack<T>& userstack){
    if(userstack.top == 0)
        return true;
    else
        return false;
}

template <class T>
void push(Stack<T>& userstack, T newitem){
    if(userstack.top > (userstack.size - 1)){
        T *temppointer;
        int tempsize = userstack.size;

        userstack.size *= 2;
        T *newarray = new T[userstack.size];
        
        for(int i = 0; i < tempsize; i++)
            newarray[i] = userstack.data[i];

        temppointer = userstack.data;
        userstack.data = newarray;
        delete [] temppointer;
        temppointer = NULL;
    }

    userstack.data[userstack.top] = newitem;
    userstack.top++;
}

template <class T>
T pop(Stack<T>& userstack){
    userstack.top--;
    T returnt = userstack.data[userstack.top];
    return returnt;
}