#include <iostream> 
#include <random>
#include "demo.h"
#include "array.h"
#include "pila.h"
#include "queue.h"
#include "list.h"
#include "list2E.h"

using namespace std;
int Create_Aleatorio_number(int p){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1,p);
    return dist(gen);
}
void DemoList2E(int x_n){
    List2E p,q;
    cout<<"Add elements to List 2E"<<endl;
    for (int i=0;i<=x_n;i++){
        int n= Create_Aleatorio_number(x_n);
        p.Insert(n);
    }
    cout<<"Print List 2E with elements"<<endl;
    p.Print();
    cout<<"\nDelete the even elements"<<endl;
    int t;
    for(int i=0;i< p.Length();i++){
        t= p.Get_Value(i);
        if (t%2==0){
            p.Delete(t);
            q.Insert(t);
        }
    }
    cout<<"Print List 2E Q with odd elements"<<endl;
    p.Print();
    cout<<"Print List 2E Q with even elements"<<endl;
    q.Print();
    cout<<"Length "<<p.Length()<<endl;
    
}
void DemoQueue(int x_n){
    Queue p; 
    cout<<"Add elements to Queue"<<endl;
    for (int i=0;i<=x_n;i++){
        int n= Create_Aleatorio_number(x_n);
        p.InQueue(n);
    }
    cout<<"Print Queue with elements"<<endl;
    p.Print();
    cout<<"\nDelete the Five first elements"<<endl;
    for(auto i=0;i<5;i++){
        int k;
        k=p.DQueue();
        cout<<"The element deleted is :"<<k<<endl;
    }
    p.Print();
    cout<<"\nThe length of Queue is : "<<p.NCount()<< endl;
}

void DemoPila(int x_n){
    pila p; 
    cout<<"Add elements to Stack"<<endl;
    for (int i=0;i<=x_n;i++){
        int n= Create_Aleatorio_number(x_n);
        p.apilar(n);
    }
    cout<<"Print Stack with elements"<<endl;
    p.print();
    cout<<"\nDelete the Five first elements"<<endl;
    for(auto i=0;i<5;i++){
        int k;
        k=p.desapilar();
        cout<<"The element deleted is :"<<k<<endl;
    }
    p.print();
    cout<<"\nBrowse element"<<endl;
    int n_find=4;
    if (p.Browse_element(n_find))
        cout<<"This element exist into Stack"<<endl;
    else    
        cout<<"This element does not exist into Stack"<<endl; 
    cout<< "\nThis Stack has "<<p.NCount()<< " elements"<<endl;       
}

void DemoArray(){   
    cout << "Hello from DemoArray()" <<endl;
    cout << "Vector #1()" <<endl;
    CArray v1("Antonio"); 
    for(auto i = 0 ; i < 15 ; i++)
        v1.insert(i);   //  insert(&v1);

    cout << "Vector #2()" <<endl;
    CArray v2("Cristian"), *pV3 = new CArray("Guiomar ABC");
    //shared_ptr<CArray> pV3(new CArray("Guiomar ABC")), pV4;
    //pV4 = pV3;
    CArray &rA = *pV3;
    for(auto i = 0 ; i < 12 ; i++)
    {   v2.insert(i);
        pV3->insert(i);
        //  (*pv3).insert(i);
        //  rA.insert(i);
    }
    
    v1.print();
    v2.print();
    pV3->print();
    // (*pV3).print();     *pV3 is already an object
    // rA.print();          rA is also an object
    // pV3[0].print();      pV3 is also an array with just 1 element [0]
    // (*(pV3+0)).print();
    // (*(0+pV3)).print();
    // 0[pV3].print();
    delete pV3;
}

void DemoBinaryTree()
{
    cout << "Hello from DemoBinaryTree()" <<endl;
}

void DemoHash()
{
    cout << "Hello from DemoHash()" <<endl;
}

void DemoList(int p){
    List lt; 
    cout<<"Add elements to List"<<endl;
    for (int i=0;i<=p;i++){
        int n= Create_Aleatorio_number(p);
        lt.Insert_Node(n);
    }
    cout<<"Print elements of List"<<endl;
    lt.Print();
    cout<<"Delete the odd elements of List"<<endl;
    pLNode tmp;
    tmp= lt.pL;
    while(tmp!=nullptr){
        if (tmp->dato%2==0)
            lt.Delete_Node(tmp->dato);
        tmp=tmp->Next;    
    }
    cout<<"Print elements of  Final List"<<endl;
    lt.Print();
}
