#include<iostream>
using namespace std;
template<class Type> 
class SetList;
template<class Type> 
class SetNode{
    friend class SetList<Type>;
private:
    Type data;
    SetNode<Type> *link;
public:
    SetNode(const Type &item):data(item),link(NULL){}
};
template<class Type>
class SetList{
private:
    SetNode<Type> *first,*last;
public:
    SetList();
    void MakeEmpty();
    int AddMember(const Type &x);
    int DelMember(const Type &x);
    SetList<Type>& operator=(SetList<Type> &right);
    SetList<Type>& operator+(SetList<Type> &right);
    SetList<Type>& operator*(SetList<Type> &right);
    SetList<Type>& operator-(SetList<Type> &right);
    int Contains(const Type &x);
    int operator==(SetList<Type> &right);
    Type& Min();
    Type& Max();
};
template<class Type>
SetList<Type>::SetList()
{
    first=last=new SetNode<Type>(0);
}
template<class Type>
int SetList<Type>::Contains(const Type &x)
{
    SetNode<Type> *temp=first->link;
    while(temp!=NULL&&temp->data<x)
        temp=temp->link;
    if(temp!=NULL&&temp->data==x)
        return 1;
    else 
        return 0;
}
template<class Type>
SetList<Type> &SetList<Type>::operator=(SetList<Type> &right)
{
    SetNode<Type> *pb=right.first->link;
    SetNode<Type> *pa=first=new SetNode<Type>;
    while(pb!=NULL)
    {
        pa->link=new SetNode<Type>(pb->data);
        pa=pa->link;
        pb=pb->link;
    }
    pa->link=NULL;
    last=pa;
    return *this;
}
template <class Type>
SetList<Type>& SetList<Type>::operator+(SetList<Type> &right)
{
    SetNode<Type> *pb=right.first->link;
    SetNode<Type> *pa=first->link;
    SetNode<Type> *pc=first;
    while(pa!=NULL&&pb!=NULL)
    {
        if(pa->data==pb->data)
        {
            pc->link=pa;
            pa=pa->link;
            pb=pb->link;
        }
        else if(pa->data<pb->data)
        {
            pc->link=pa;
            pa=pa->link;
        }
        else
        {
            pc->link=new SetNode<Type>(pb->data);
            pb=pb->link;
        }
        pc=pc->link;
    }
    if(pa!=NULL)
        pc->link=pa;
    else
    {
        while(pb!=NULL)
        {
            pc->link=new SetNode<Type>(pb->data);
            pc=pc->link;
            pb=pb->link;
        }
        pc->link=NULL;
        last=pc;
    }
    return *this;
}
template<class Type>
SetList<Type>& SetList<Type>::operator*(SetList<Type> &right)
{
    SetNode<Type> *pb=right.first->link;
    SetNode<Type> *pa=first->link;
    SetNode<Type> *pc=first;
    while(pa!=NULL&&pb!=NULL)
    {
        if(pa->data==pb->data)
        {
            pc=pc->link;
            pa=pa->link;
            pb=pb->link;
        }
        else if(pa->data<pb->data)
        {
            pc->link=pa->link;
            delete pa;
            pa=pc->link;
        }
        else
            pb=pb->link;
    }
    while(pa!=NULL)
    {
        pc->link=pa->link;
        delete pa;
        pa=pc->link;
    }
    last=pc;
    return *this;
}
template<class Type>
SetList<Type>& SetList<Type>::operator-(SetList<Type> &right)
{
    SetNode<Type> *pb=right.first->link;
    SetNode<Type> *pa=first->link;
    SetNode<Type> *pc=first;
    while(pa!=NULL&&pb!=NULL)
    {
        if(pa->data==pb->data)
        {
            pc->link=pa->link;
            delete pa;
            pa=pc->link;
            pb=pb->link;
        }
        else if(pa->data<pb->data)
        {
            pc=pc->link;
            pa=pa->link;
        }
        else 
            pb=pb->link;
    }
    if(pa==NULL)
        last=pc;
    return *this;
}
template<class Type>
int SetList<Type>::operator==(SetList<Type> &right)
{
    SetNode<Type> *pb=right.first->link;
    SetNode<Type> *pa=first->link;
    while(pa!=NULL&&pb!=NULL)
    {
        if(pa->data==pb->data)
        {
            pa=pa->link;
            pb=pb->link;
        }
        else
            return 0;
    }
    if(pa!=NULL||pb!=NULL)
        return 0;
    return 1;
}