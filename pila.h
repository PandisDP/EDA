#ifndef _PILA_H
#define _PILA_H

#include<iostream>
using namespace std;

struct Node{
    /* data */
    int dato;
    Node *sig;
};
typedef Node *pNode;
class pila{
private:
    pNode pTop;
public:
    pila();
    ~pila();
    bool pila_empty();
    void apilar(int x);
    int desapilar();
    void print();
};

#endif  //PILA_H