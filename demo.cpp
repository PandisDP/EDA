#include <iostream> // cout
#include "demo.h"
#include "array.h"
#include "pila.h"

using namespace std;
void DemoPila(){
    pila p;
    cout<<" Testing of Apilamiento"<<endl;
    for (int i=0;i<=10;i++){
        p.apilar(i);
    }
    cout<<"Print Stack with elements"<<endl;
    p.print();
    cout<<"\nDelete the Five first elements"<<endl;
    for(auto i=0;i<5;i++){
        int k;
        k=p.desapilar();
        cout<<"The element delete is :"<<k<<endl;
    }
    p.print();
    cout<<"End"<<endl;
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

