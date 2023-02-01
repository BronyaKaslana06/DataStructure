#include<iostream>
#include<assert.h>
using namespace std;
template<class Type>
class Stack;
template<class Type>
class StackNode{
    friend class Stack<Type>;
private:
    Type data;//data of the node
    StackNode<Type>* link;//pointer to next node
    StackNode(Type d=0,StackNode<Type>* l=NULL):data(d),link(l){}
};
template <class Type>
class Stack{
private:
    StackNode<Type>* top;//pointer to top of the stack
public:
    Stack():top(NULL){}
    ~Stack();
    void Push(Type&);
    Type Pop();
    Type GetTop();
    void MakeEmpty();
    bool IsEmpty()const{return top==NULL;}
};
template<class Type>
Stack<Type>::~Stack()
{
    StackNode<Type> *p=NULL;
    while(top!=NULL)
    {
        p=top;
        top=top->link;
        delete p;
    }
}
template<class Type>
void Stack<Type>::Push(Type& item)
{
    top=new(nothrow) StackNode<Type>(item,top);
    if(top==NULL)
    {
        cerr<<"Failed to call memory"<<endl;
        exit(1);
    }
}
template<class Type>
Type Stack<Type>::Pop()
{
    assert(!IsEmpty());
    StackNode<Type> *p=top;
    Type retvalue=p->data;
    top=top->link;
    delete p;
    return retvalue;
}
template<class Type>
Type Stack<Type>::GetTop()
{
    assert(!IsEmpty());
    return top->data;
}