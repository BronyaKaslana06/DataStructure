#include<assert.h>
#include<iostream>
using namespace std;
const int DefaultSize=100;
class Set{
private:
    int *bitVector;
    int MaxSize;
public:
    Set(int MaxSetSize=DefaultSize);
    ~Set(){delete[] bitVector;}
    void MakeEmpty();
    int AddMember(const int x);
    int DelMember(const int x);
    Set& operator+(Set &right);
    Set& operator*(Set &right);
    Set& operator-(Set &right);
    Set& operator=(Set &right);
    int Contains(const int x);
    int SubSet(Set &right);
    bool operator==(Set &right);
};
void Set::MakeEmpty()
{
    for(int i=0;i<MaxSize;i++)
        bitVector[i]=0;
}
Set::Set(int MaxSetSize):MaxSize(MaxSetSize)
{
    assert(MaxSize>0);
    bitVector=new int[MaxSize];
    assert(bitVector!=NULL);
    for(int i=0;i<MaxSize;i++)
        bitVector[i]=0;
}
int Set::AddMember(const int x)
{
    assert(x>=0&&x<MaxSize);
    if(!bitVector[x])
    {
        bitVector[x]=1;
        return 1;
    }
    return 0;
}
int Set::DelMember(const int x)
{
    assert(x>=0&&x<MaxSize);
    if(bitVector[x])
    {
        bitVector[x]=0;
        return 1;
    }
    return 0;
}
Set& Set::operator=(Set &right)
{
    assert(MaxSize==right.MaxSize);
    for(int i=0;i<MaxSize;i++)
        bitVector[i]=right.bitVector[i];
    return *this;
}
Set& Set::operator+(Set &right)
{
    assert(MaxSize==right.MaxSize);
    for(int i=0;i<MaxSize;i++)
        bitVector[i]=bitVector[i]||right.bitVector[i];
    return *this;
}
Set& Set::operator*(Set &right)
{
    assert(MaxSize==right.MaxSize);
    for(int i=0;i<MaxSize;i++)
        bitVector[i]=bitVector[i]&&right.bitVector[i];
    return *this;
}
Set& Set::operator-(Set &right)
{
    assert(MaxSize==right.MaxSize);
    for(int i=0;i<MaxSize;i++)
        bitVector[i]=bitVector[i]&&!right.bitVector[i];
    return *this;
}
int Set::Contains(const int x)
{
    assert(x>=0&&x<MaxSize);
    return bitVector[x];
}
bool Set::operator==(Set &right)
{
    assert(MaxSize==right.MaxSize);
    for(int i=0;i<MaxSize;i++)
        if(bitVector[i]!=right.bitVector[i])
            return 0;
    return 1;
}
int Set::SubSet(Set &right)//the method is wrong
{
    assert(MaxSize==right.MaxSize);
    for(int i=0;i<MaxSize;i++)
        if(bitVector[i]&&!right.bitVector[i])
            return 0;
    return 1;
}