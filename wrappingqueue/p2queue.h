const int SIZE = 5;
template<typename T>
struct Queue{
    int head;
    int tail;
    T data[SIZE];
};

template <typename T>
void initialize(Queue<T>& q){
    q.head = 0;
    q.tail = 0;
}

template <typename T>
void destroy(Queue<T>& q){
    q.head = 0;
    q.tail = 0;
}

template<typename T>
int getSize(Queue<T> q){
    return q.head - q.tail;
}

template<typename T>
bool isEmpty(Queue<T> q){
    if(q.head == q.tail)
        return true;
    else
        return false;
}

template<typename T>
void push(Queue<T>& q, T userval){
    q.array[q.tail] = userval;
    q.tail++;
    if(q.tail > SIZE)
        q.tail = 0;
}

template<typename T>
T pop(Queue<T>& q){
    T tempval = q.array[q.head];
    q.head++;
    if(q.head > SIZE)
        q.head = 0;
    return tempval;
}