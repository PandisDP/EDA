#ifndef _LIST_
#define _LIST_

#include<iostream>
using namespace std;

struct LNode{
    int dato;
    LNode *Next;
};
typedef LNode *pLNode;

class List{
    public:
        List();
        ~List();
        void Insert_Node(int x);
        pLNode Browse_Node(int x);
        pLNode Browse_Node_i_1(int x);
        void Delete_Node(int x);
        void Print();
        int len();
        pLNode pL;        
};
#endif
