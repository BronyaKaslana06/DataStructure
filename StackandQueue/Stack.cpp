#include<iostream>
#include<assert.h>
using namespace std;
template<class Type>
class Stack{
private:
    int top;//pointer of the top of the stack
    Type* elements;//stack array
    int maxSize;//max volumn of the stack
public:
    Stack(int=10);//constructor
    ~Stack(){delete[] elements;}//destructor
    void Push(Type&);//Push into stack 
    Type Pop();//Pop out of stack
    Type GetTop();//get top element of stack but do not pop
    void MakeEmpty(){top=-1;}//make stack empty
    bool IsEmpty()const{return top==-1;}//is the stack empty
    bool IsFull()const{return top==maxSize-1;}//is the stack full 
};
template<class Type>
Stack<Type>::Stack(int s):top(-1),maxSize(s)
{
    elements=new Type[maxSize];
    assert(elements!=0);
}
template<class Type>
void Stack<Type>::Push(Type& item)
{
    assert(!IsFull());
    elements[++top]=item;
}
template<class Type>
Type Stack<Type>::Pop()
{
    assert(!IsEmpty());
    return elements[top--];
}
template<class Type>
Type Stack<Type>::GetTop()
{
    assert(!IsEmpty());
    return elements[top];
}

