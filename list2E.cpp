#include "list2E.h"
#include <iostream>
using namespace std;
List2E::List2E(){
    pL2E=nullptr; //Here initiliazed the pointer to null
    L_index=0;
}

List2E::~List2E(){
    pL2ENode p,tmp;
    p= pL2E;
    tmp=nullptr;
    while(p!= nullptr){
        tmp=p;
        p=p->Next;
        delete tmp;
    }
    cout<<"Free memory"<<endl;
}

void List2E::Insert(int x){
    pL2ENode p;
    p= new L2ENode;
    L_index=L_index+1;
    p->dato= x;
    p->index=L_index;
    p->Next= pL2E;
    p->Back=nullptr;
    if (pL2E != nullptr)
        pL2E->Back=p;
    pL2E=p;    
}

void List2E::Delete(int x){
    pL2ENode p,next,back;
    p= Browse(x);
    if(p==nullptr){
        cout<<"Does not exist "<<x<<endl;
    }
    else{
        back=p->Back;
        next=p->Next;
        if(back==nullptr){
            next->Back=nullptr;
            pL2E=next;
        }
        else{
            if(next!= nullptr){
                next->Back=back;
                back->Next=next;
            }
            else{
                back->Next=nullptr;
            }
        }
        delete p;
        L_index=L_index-1;
    }    
}

int List2E::Get_Value(int index){
    pL2ENode p;
    int x=0;
    p= pL2E;
    if (x<L_index){
        while(p!= nullptr && x != index){
            x=x+1;
            p=p->Next;
       }
    }
    return p->dato;
}

pL2ENode List2E::Browse(int x){
    pL2ENode p;
    p= pL2E;
    while(p->dato!=x && p!= nullptr){
           p=p->Next;
    }
    return p;
}

void List2E::Print(){
    pL2ENode p;
    p=pL2E;
    while(p!= nullptr){
        cout<<p->dato<<"-->";
        p=p->Next;
    }
    cout<<endl;
}

int List2E::Length(){
    return L_index;
}
