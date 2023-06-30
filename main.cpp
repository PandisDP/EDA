#include <iostream>
#include "demo.h"
#include "CPPDemo.h"
#include "pila.h"
#include "queue.h"
// #include "array.h"

using namespace std;

// g++ -pthread -std=c++17 -o main main.cpp demo.cpp array.cpp CPPDemo.cpp
int main()
{
    //DemoArray();
    //DemoBinaryTree();
    //DemoHash();
    // DemoPreandPostIncrement();
    //DemoPila(10);
    DemoQueue(10);
    return 0;
}