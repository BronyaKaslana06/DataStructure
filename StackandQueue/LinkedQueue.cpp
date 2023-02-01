#include<iostream>
#include<assert.h>
using namespace std;
template <class Type> 
class Queue;
template <class Type>
class QueueNode{
    friend class Queue<Type>;
private:
    Type data;
    QueueNode<Type> *link;//pointer to next node
    QueueNode(Type d=0,QueueNode *l=NULL):data(d),link(l){}
};
template <class Type>
class Queue{
private:
    QueueNode<Type> *front;//pointer of the queue
    QueueNode<Type> *rear;//pointer of the queue
public:
    Queue():rear(NULL),front(NULL){}
    ~Queue();
    void EnQueue(Type&);
    Type DeQueue();
    Type GetFront();
    void MakeEmpty();
    bool IsEmpty() const{return front==NULL;}
};
template<class Type>
void Queue<Type>::MakeEmpty()
{
    Queue<Type> *p=NULL;
    while(front!=NULL)
    {
        p=front;
        front=front->link;
        delete p;
    }
    front=rear=NULL;
}
template <class Type>
Queue<Type>::~Queue()
{
    MakeEmpty();
}
template <class Type>
void Queue<Type>:: EnQueue(Type& item)
{
    if(front==NULL)//if front is NULL, create new head node
    {
        front=rear=new QueueNode<Type>(item,NULL);
        assert(!front==NULL);
    }
    else
    {
        rear=rear->link=new QueueNode<Type>(item,NULL);
        assert(!rear==NULL);
    }
}
template <class Type>
Type Queue<Type>::DeQueue()
{
    assert(!IsEmpty());
    QueueNode<Type> *p=front;
    Type retvalue=p->data;
    front=front->link;
    delete p;
    return retvalue;
}
template<class Type>
Type Queue<Type>::GetFront()
{
    assert(!IsEmpty());
    return front->data;
}