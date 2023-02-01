#include<iostream>
#include<stdlib.h>
using namespace std;
template <class type>
class seqList{
    private:
    type* data;
    int MaxSize;
    int last;
    public:
    seqList(int num);
    ~seqList(){delete[] data;}
    int Length() const{return last+1;}
    bool Remove(int num);
    bool Insert(type& x,int index);
    int Find(type& x);
    type Get(int index);
    
};
template<class type>
seqList<type>::seqList(int num)
{
    if(num<=0)
    {
        cerr<<"Input number is wrong"<<endl;
        return;
    }
    MaxSize=num;
    last=0;
    data=new type[MaxSize];
    if(data==NULL)
    {
        MaxSize=0;
        last=-1;
        cerr<<"Failed to call memory"<<endl;
        return;
    }
}
template<class type>
int seqList<type>::Find(type& x)
{
    int i=0;
    data[last+1]=x;
    for(i=0;;i++)
    {
        if(data[i]==x)
            break;
    }
    if(i>last)
        return -1;
    else
        return i;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
template<class type>
bool seqList<type>:: Insert(type& x,int index)
{
    if(index>last||index>MaxSize||index<0||last==MaxSize-1)
        return false;
    else
    {
        for(int i=last;i>=index;i--)
            data[i+1]=data[i];
        data[index]=x;
        last++;
        return true;
    }
}
template<class type>
bool seqList<type>::Remove(int num)
{
    data[last+1]=num;
    int i=0;
    while(data[i]!=num)
        i++;
    if(i>last)
        return false;
    else
    {
        for(int j=i;j<last;j++)
            data[j]=data[j+1];
        last--;
        return 1;
    }
}
template<class type>
type seqList<type>::Get(int index)
{
    if(index>=last||index<0)
    {
        cerr<<"Iilegal number"<<endl;
        return -1;
    }
    return data[index];
}
void test1()
{
    seqList<int> seq1(15);
    for(int i=0;i<=9;i++)
        seq1.Insert(i,i);
    for(int i=0;i<=9;i++)
        cout<<seq1.Get(i)<<' ';
    cout<<endl;
    seqList<int> seq2(seq1);
    cout<<seq2.Length()<<endl;
    for(int i=0;i<=9;i++)
        cout<<seq2.Get(i)<<' ';
    cout<<endl;
    int x=11;
    seq2.Insert(x,11);
    cout<<seq2.Length()<<endl;
    for(int i=0;i<=9;i++)
        cout<<seq2.Get(i)<<' ';
    cout<<endl;
    seq2.Remove(3);
    for(int i=0;i<=8;i++)
        cout<<seq2.Get(i)<<' ';
}
int main()
{
    test1();
    return 0;
}