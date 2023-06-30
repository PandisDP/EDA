#ifndef _QUEUE_H
#define _QUEUE_H
#include<iostream>
using namespace std;

struct NodeQ{
    int dato;
    NodeQ *Next;
};
typedef NodeQ *qNode;

class Queue{
    public:
        Queue();
        ~Queue();
        void InQueue(int x);
        int DQueue();
        int NCount();
        void Print();
    private:
        qNode pTop;
        qNode pDown;    

};

#endif
