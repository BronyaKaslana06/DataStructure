#include<iostream>
#include<assert.h>
using namespace std;
template<class Type>
class Queue{
private:
    int rear;
    int front;
    Type* elements;
    int maxSize;
public:
    Queue(int=10);
    ~Queue(){delete[] elements;}
    void EnQueue(Type& item);//come in queue
    Type DeQueue();//come out of the queue
    Type GetFront();//get the top element's value
    void MakeEmpty(){front=rear=0;}//make queue empty
    bool IsEmpty() const{return front==rear;}//queue is empty or not
    bool IsFull() const{return (rear+1)%maxSize==front;}//queue is full or not
    int Length() const{return (rear-front+maxSize)%maxSize;}
};
template<class Type>
Queue<Type>::Queue(int size)
{
    maxSize=size;
    elements=new Type[maxSize];
    assert(elements!=NULL);
    rear=front=-1;
}
template<class Type>
void Queue<Type>::EnQueue(Type& item)
{
    assert(!IsFull());
    //elements[++rear]=item;//standard queue
    rear=(rear+1)%maxSize;//circular queue
}
template<class Type>
Type Queue<Type>::DeQueue()
{
    assert(!IsEmpty());
    //return elements[++front];//standard queue
    front=(front+1)%maxSize;//circular queue
    return elements[front];
}
template<class Type>
Type Queue<Type>::GetFront()
{
    assert(!IsEmpty());
    return elements[front];
}
