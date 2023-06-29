#include<iostream>
#include "pila.h"
using namespace std;

pila::pila(){
    pTop = nullptr;
}

pila::~pila(){
    pNode p;
    p= pTop;
    while(p!=nullptr){
        p=p->sig;
        delete pTop;
        pTop=p;
    }
}

bool pila::pila_empty(){
    // This code identify if the Pila is empty
    if (pTop == nullptr)
        return true;
    else
        return false;
}

void pila::apilar(int x){
    pNode ptemp;
    ptemp= new Node;
    (*ptemp).dato=x;
    (*ptemp).sig= pTop;
    pTop=ptemp;
}

int pila::desapilar(){
    if (pTop != nullptr){
        pNode ptemp;
        int x;
        ptemp =pTop;
        x= ptemp->dato; 
        pTop= pTop->sig;
        return x;
    }
    else{
        return -1;
    }
}

void pila::print(){
    pNode p;
    p= pTop;
    while (p!=nullptr){
        cout<< p->dato<< "->";
        p=p->sig;
    }
    cout<<endl;
}
