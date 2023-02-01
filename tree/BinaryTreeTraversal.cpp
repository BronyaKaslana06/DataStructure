#include<stack>
#include<iostream>
using namespace std;
typedef struct BitreeNode{
    int data;
    struct BitreeNode* leftChild,*rightChild;
}BitreeNode,*Bitree;
//traditional medthod to traverse binary tree(use stack)
void PreOrderTraverse(Bitree T)
{
    stack<BitreeNode*> S;
    BitreeNode *p;
    S.push(NULL);
    p=T;
    while(p)
    {
        cout<<p->data<<'\t';
        if(p->rightChild)
            S.push(p->rightChild);
        if(p->leftChild)
            p=p->leftChild;
        else
        {
            p=S.top();
            S.pop();
        }
    }
}
void InOrderTraverse(Bitree T)
{
    stack<BitreeNode*> S;
    BitreeNode *p;
    p=T;
    do{
        while(p!=NULL)
        {
            S.push(p);
            p=p->leftChild;
        }//finally p=nullptr, the last leftchild leaf node is in the stack
        if(!S.empty())
        {
            p=S.top();
            S.pop();
            cout<<p->data<<' ';
            p=p->rightChild;
        }
    }while(p!=NULL||!S.empty());
}