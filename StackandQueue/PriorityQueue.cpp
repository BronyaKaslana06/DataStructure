#include<assert.h>
#include<iostream>
#include<stdlib.h>
const int maxPQSize=50;
template<class Type>
class PQueue{
private:
    Type *pqelements;//save array
    int count;//the number of queue's elements
public:
    PQueue();
    ~PQueue(){delete[] pqelements;}
    void PQInsert(Type&);
    Type PQRemove();
    void makeEmpty(){count=0;}
    bool IsEmpty() const{return count==0;}
    bool IsFull() const{return count==maxPQSize;}
    int Length() const{return count;}
};
template<class Type>
PQueue<Type>::PQueue():count(0)
{
    pqelements=new Type[maxPQSize];
    assert(pqelements!=NULL);
}
template<class Type>
void PQueue<Type>::PQInsert(Type& item)
{
    assert(!IsFull());
    pqelements[count]=item;
    count++;
}
template<class Type>
Type PQueue<Type>::PQRemove()
{
    assert(!IsEmpty());
    Type minElement=pqelements[0];
    int minindex=0;
    for(int i=1;i<count;i++)
    {
        if(pqelements[i]<minElement)
        {
            minElement=pqelements[i];
            minindex=i;
        }
    }
    pqelements[minindex]=pqelements[count-1];//put last element here
    count--;
    return minElement;
}