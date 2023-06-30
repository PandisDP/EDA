#include <iostream>
#include "queue.h"
using namespace std;
Queue::Queue()
{
    pTop=nullptr;
    pDown= nullptr;
}

Queue::~Queue(){
    qNode pTemp;
    pTemp=pTop;
    if (pTop!= pDown){
        while (pTemp != nullptr){
            pTop=pTop->Next;
            delete pTemp;
            pTemp=pTop;
       }
    }
    else
        delete pTop;
        delete pTemp;
}

void Queue::InQueue(int x){
    qNode pTemp;
    pTemp= new NodeQ;
    (*pTemp).dato=x;
    (*pTemp).Next= nullptr;
    if (pTop==nullptr)
        pTop= pTemp;
    else
        (*pDown).Next=pTemp;
    pDown= pTemp;        
}

int Queue::DQueue(){
    qNode pTemp;
    pTemp= pTop;
    if (pTop != nullptr){
        if(pTop == pDown){
            pTop= nullptr;
            pDown=nullptr;
        }
        else
            pTop=pTop->Next;
        return (*pTemp).dato;
    }
    else
       return -1; 
}

int Queue::NCount(){
    qNode pTemp= pTop;
    int n=0;
    while(pTemp != nullptr){
        n=n+1;
        pTemp=pTemp->Next;
    }
    return n;
}

void Queue::Print(){
    qNode pTemp;
    pTemp= pTop;
    if(pTemp != nullptr){
        while(pTemp!=nullptr){
            cout<<pTemp->dato<<"->";
            pTemp=pTemp->Next;
        }
        cout<<endl;
    }
    else
        cout<<"The Queue is empty"<<endl;
}
