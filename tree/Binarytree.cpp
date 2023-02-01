#include<iostream>
#include<math.h>
using namespace std;
template<class Type> 
class BinaryTree;
template<class Type>
class BinTreeNode{
    friend class BinaryTree<Type>;
private:
    BinTreeNode<Type>*leftChild,*rightChild;
    Type data;
public:
    BinTreeNode():leftChild(NULL),rightChild(NULL){}
    BinTreeNode(Type item,BinTreeNode<Type>*left=NULL,BinTreeNode<Type>*right=NULL):
    data(item),leftChild(left),rightChild(right){}
    Type GetData()const{return data;}
    BinTreeNode<Type>*GetLeft()const{return leftChild;}
    BinTreeNode<Type>*GetRight()const{return rightChild;}
    void SetData(Type& item){data=item;}
    void SetLeft(BinTreeNode<Type>*L){leftChild=L;}
    void SetRight(BinTreeNode<Type>*R){rightChild=R;}
};

template<class Type>
class BinaryTree{
public:
    BinaryTree():root(NULL){}
    BinaryTree(Type value):RefValue(value),root(NULL){}
    virtual ~BinaryTree(){destroy(root);}
    virtual int IsEmpty(){return root==NULL?1:0;}
    virtual BinTreeNode<Type>* Parent(BinTreeNode<Type> *current)
    {return root==NULL||root==current?NULL:Parent(root,current);}
    virtual BinTreeNode<Type>* LeftChild(BinTreeNode<Type>*current)
    {return root!=NULL?current->leftChild:NULL;}
    virtual int Insert(Type&item);
    const BinTreeNode<Type> *GetRoot()const{return root;}

    void InOrder();
    void InOrder(BinTreeNode<Type>*current);
    void PreOrder();
    void PreOrder(BinTreeNode<Type>*current);
    void PostOrder();
    void PostOrder(BinTreeNode<Type>*current);
    int Size(BinTreeNode<Type>*t);
    int Depth(BinTreeNode<Type>*t);
    friend istream& operator>>(istream& in,BinaryTree<Type> &Tree);
    friend ostream& operator<<(ostream &out,BinaryTree<Type> &Tree);
private:
    BinTreeNode<Type>*root;
    Type RefValue;
    BinTreeNode<Type>*Parent(BinTreeNode<Type>*start,BinTreeNode<Type>*current);
    int Insert(BinTreeNode<Type>*&current,const Type &item);
    void Traverse(BinTreeNode<Type>*current,ostream &out)const;
    int Find(BinTreeNode<Type>*current,const Type &item)const;
    void destroy(BinTreeNode<Type> *current);
};
template<class Type> 
void BinaryTree<Type>::destroy(BinTreeNode<Type>*current)
{
    if(current!=NULL)
    {
        destroy(current->leftChild);
        destroy(current->rightChild);
        delete current;
    }
}
template<class Type>
BinTreeNode<Type>* BinaryTree<Type>::Parent(BinTreeNode<Type>*start,BinTreeNode<Type>*current)
{
    if(start==NULL)
        return NULL;
    if(start->leftChild==current||start->rightChild==current)
        return start;
    BinTreeNode<Type>*p;
    if((p=Parent(start->leftChild,current)!=NULL))
        return p;
    else
        return Parent(start->rightChild,current);
}
template<class Type>
void BinaryTree<Type>::Traverse(BinTreeNode<Type>*current,ostream &out)const
{
    if(current!=NULL)//ordered traverse
    {
        out<<current->data<<' ';
        Traverse(current->leftChild,out);
        Traverse(current->rightChild,out);
    }
}
template<class Type>
istream& operator>>(istream &in,BinaryTree<Type> &Tree)
{
    Type item;
    cout<<"Build binary tree"<<endl;
    cout<<"Please input data(use "<<Tree.RefValue<<"to end):";
    in>>item;
    while(item!=Tree.RefValue)
    {
        Tree.Insert(item);
        cout<<"Please input data(use "<<Tree.RefValue<<"to end):";
    }
    in>>item;
    return in;
}
template<class Type>
ostream& operator<<(ostream& out,BinaryTree<Type> &Tree)
{
    out<<"Ordered traverse of binary tree"<<endl;
    Tree.Traverse(Tree.root,out);
    out<<endl;
    return out;
}
template<class Type>
void BinaryTree<Type>::InOrder()
{
    InOrder(root);
}
template<class Type>
//zhong xu bian li
void BinaryTree<Type>::InOrder(BinTreeNode<Type>*current)
{
    if(current!=NULL)
    {
        InOrder(current->leftChild);
        cout<<current->data;
        InOrder(current->rightChild);
    }
}
template<class Type>
void BinaryTree<Type>::PreOrder()
{
    PreOrder(root);
}
template<class Type>
//qian xu bian li 
void BinaryTree<Type>::PreOrder(BinTreeNode<Type>*current)
{
    if(current!=NULL)
    {
        cout<<current->data;
        PreOrder(current->leftChild);
        PreOrder(current->rightChild);
    }
}
template<class Type>
void BinaryTree<Type>::PostOrder()
{
    PostOrder(root);
}
template<class Type>
//hou xu bian li
void BinaryTree<Type>::PostOrder(BinTreeNode<Type>*current)
{
    if(current!=NULL)
    {
        PostOrder(current->leftChild);
        PostOrder(current->rightChild);
        current->data;
    }
}
template<class Type>
int BinaryTree<Type>::Size(BinTreeNode<Type>*t)
{
    if(t==NULL)
        return 0;
    else
        return 1+Size(t->leftChild)+Size(t->rightChild);
}
template<class Type>
int BinaryTree<Type>::Depth(BinTreeNode<Type>*t)
{
    if(t==NULL)
        return -1;
    else
        return 1+max(Depth(t->leftChild),Depth(t->rightChild));
}