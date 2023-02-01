#include<iostream>
#include<stdlib.h>
using namespace std;
const int ArraySize=100;
template <class type>
class Array{
    private:
    type* elements;
    int Arraysize;
    void getArray();
    public:
    Array(int size);
    Array(const Array<type>& x);
    ~Array()
    {
        delete[] elements;
    }
    Array<type>& operator=(const Array<type>& A);
    type& operator[](int i);
    type* operator() ()const
    {
        return elements;
    }
    int Length() const
    {
        return Arraysize;
    }
    void ReSize(int sz);
};
template <class type>
void Array<type>::getArray()
{
    elements=new type[ArraySize];
    if(elements==NULL)
    {
        Arraysize=0;
        cerr<<"Failed to call memory!"<<endl;
        return;
    }
}
template <class type>
Array<type>::Array(int sz)
{
    if(sz<=0||sz>=100)
    {
        cerr<<"Iilegal array size"<<endl;
        Arraysize=0;
        return;
    }
    Arraysize=sz;
    getArray();
}
template<class type>
Array<type>::Array(const Array<type>& x)
{
    int n=x.Arraysize;
    Arraysize=n;
    elements=new type[ArraySize];
    if(elements==NULL)
    {
        Arraysize=0;
        cerr<<"Failed to call memory"<<endl;
        return;
    }
    type* srcptr=x.elements;
    type* dstptr=elements;
    while(n--)
        * dstptr++ = * srcptr++;
}
template<class type>
type& Array<type>:: operator[] (int i)
{
    if(i<0||i>=Arraysize)
    {
        cerr<<"下标越界"<<endl;
    }
    return elements[i];
} 
template<class type>
void Array<type>::ReSize(int sz)
{
    if(sz<=0||sz>=Arraysize)
    {
        cerr<<"下标越界"<<endl;
        return;
    }
    type* newArray=new type[sz];
    if(newArray==NULL)
    {
        cerr<<"Failed to call memory"<<endl;
        return;
    }
    int n=(sz<Arraysize)?sz:Arraysize;
    type* srcptr=elements;
    type* dstptr=newArray;
    while(n--)
        *dstptr++=*srcptr++;
    delete[] elements;
    elements=newArray;
    Arraysize=sz;
}
void test1()
{
    Array<int> a1(10);
    for(int i=0;i<=9;i++)
        a1[i]=i;
    for(int i=0;i<=9;i++)
        cout<<a1[i]<<' ';
    cout<<endl;
    Array<int> a2(a1);
    cout<<a2.Length()<<endl;
    for(int i=0;i<=9;i++)
        cout<<a2[i]<<' ';
    cout<<endl;
    a2.ReSize(5);
    cout<<a2.Length()<<endl;
    for(int i=0;i<=4;i++)
        cout<<a2[i]<<' ';
    cout<<endl;
}
int main()
{
    test1();
    return 0;
}
