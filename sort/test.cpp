#include<iostream>
#include<string.h>
#define N 6
using namespace std;
void sort(char** pp)
{
    char* temp;
    int i,j,k;
    for(i=N/2;i>0;i/=2)
        for(j=i;j<N;j++)
            for(k=N-i-1;k>=0;k-=i)
            {
                if(**(pp+k)<=**(pp+k+i))
                    continue;
                temp=*(pp+k);
                *(pp+k)=*(pp+k+i);
                *(pp+k+i)=temp;
            }
}
int main()
{
    char pp[N][20]={"binary","address","parallel","interrupt","digital","check"};
    int i;
    sort((char**)pp);
    for(i=0;i<N;i++)
        cout<<pp[i][0]<<endl;
    return 0;
}