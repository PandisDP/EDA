#include <iostream>
#include "list.h"
using namespace std;

List::List(){
    pL=nullptr;
}

List::~List(){
    pLNode p,q;
    p= pL;
    q=nullptr;
    while(p!= nullptr){
        q=p->Next;
        delete p;
        p=q;
    }
}

void List::Insert_Node(int x){
    pLNode pTemp;
    pTemp= new LNode;
    (*pTemp).dato=x;
    (*pTemp).Next=pL;
    pL=pTemp;
}

pLNode List::Browse_Node(int x){
    pLNode pTemp;
    if (pL== nullptr)
        return nullptr;
    else
    {
        pTemp= pL;
        while (pTemp != nullptr && (*pTemp).dato != x)
            pTemp= (*pTemp).Next;
        return pTemp;    
    }        
}

pLNode List::Browse_Node_i_1(int x){
    pLNode a,p;
    a= nullptr;
    p= pL;
    while((*p).dato != x){
        a=p;
        p= p->Next;
    }
    return a;
}

void List::Delete_Node(int x){
    pLNode a,p;
    p= Browse_Node(x);
    if (p==nullptr)
        cout<<"The element does not exist in the list"<<endl;
    else{
        a= Browse_Node_i_1(x);
        if(a==nullptr)
            pL=(*p).Next;
        else
            (*a).Next=(*p).Next;
        delete p;        
    }    
}

void List::Print(){
    pLNode p;
    p= pL;
    while(p != nullptr){
        cout<< p->dato<<"<-";
        p= p->Next;
    }
    cout<<endl;
}

int List::len(){
    pLNode p;
    p=pL;
    int n=0;
    while(p!=nullptr){
        n=n+1;
    }
    return n;
}
