#ifndef _LIST2E_
#define _LIST2E_
#include <iostream>
using namespace std;

//We define Struct to admin the data
struct L2ENode{
    int dato;
    int index;
    L2ENode *Next;
    L2ENode *Back;
};
typedef L2ENode *pL2ENode;
// Class definition
class List2E{
    public:
        List2E();
        ~List2E();
        void Insert(int x);
        void Delete(int x);
        int Get_Value(int index);
        void Print();
        int Length();
    private:
        int L_index; 
        pL2ENode pL2E; 
        pL2ENode Browse(int x);
}
;
#endif