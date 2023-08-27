#include <iostream> // cout
#include <fstream>  // ofstream, ifstream
#include <cmath>
#include <memory>
#include "demo.h"
#include "array.h"
#include "matrix.h"
#include "foreach.h"
#include "xtrait.h"
#include "binarytree.h"
#include "avl.h"
#include <random>
using namespace std;

template <typename T, int N>
void increment(T &x)
{  x+= N; }

template <typename T>
void print(T &x)
{  cout << x << "  "; }

// Object function
template <typename T>
class ClassX
{          int m_inc = 0;
    public:  ClassX(int n) : m_inc(n){}
    void operator()(T &n){  n += m_inc;     }
};

void Fx1(int n ) {    n++;    }
void Fx2(int &n) {    n++;    }
void Fx3(int *pi){    ++*pi;  pi = nullptr; }
void Fx4(int *&rp){   ++*rp;  rp = nullptr; }

void DemoBasicPointers(){
    int i = 10, j = 20, &r = i; 
    int *b /*Peligro*/, *p = nullptr, *q = nullptr, **pp = nullptr;
    p = &i;     q = &j;     pp = &p;
    float f = 3.14;
    cout << "***** Fx1 *****" << endl;
    Fx1(i);     cout << i << endl;  //  10
    Fx1(15);
    Fx1(*p);    cout << i << endl;  //  10
    Fx1(**pp);  cout << i << endl;  //  10
    Fx1(r);     cout << i << endl;  //  10
    
    cout << "***** Fx2 *****" << endl;
    i = 10;     // r = 10;
    Fx2(i);     cout << i << endl;  // 11
    // Fx2(20);
    // Fx2(i+5);
    // Fx2(i+j);
    // Fx2(f);
    Fx2(r);     cout << i << endl;  // 12

    cout << "***** Fx3 *****" << endl;
    **pp = 10;  // *p = 10;     i = 10;
    *q = 20;    //  j = 20;
    Fx3(p);     cout << i << endl;  // 11
    Fx3(*pp);   cout << i << endl;  // 12
    Fx3(&i);    cout << i << endl;  // 13
    Fx3(q);     cout << j << endl;  // 21
    Fx3(&j);    cout << j << endl;  // 22

    cout << "***** Fx4 *****" << endl;
    p = &i;     q = &j;     pp = &p;
    **pp = 50;  // *p = 10;     i = 10;
    *q   = 60;  //  j = 20;
    Fx4(p);     cout << i << " p: :" << p << endl;  // 51
    p = &i;     // *pp = &i;
    Fx4(*pp);   cout << i << " p: :" << p << endl;  // 52, p: 0x0
    // Fx4(&i);    Error ! es un valor
    Fx4(q);     cout << j << " q: :" << q << endl;  // 61 q: 0x0
    // Fx4(&j);    cout << j << endl;  // 22
}

void DemoSmartPointers(){
    CArray< TraitArrayIntInt > v2("Lucero"), *pX; //, *pV3 = new CArray("Luis");
    
    shared_ptr< CArray< TraitArrayFloatString > > pV3(new CArray< TraitArrayFloatString >("Luis")), pV4;
    pV4 = pV3;
    auto &rA = *pV3;
    for(auto i = 100 ; i < 112 ; i++)
    {   v2.insert(i, i*i);
        pV3->insert(sqrt(i), string("**")+to_string(sqrt(i)+5)+string("**"));
        //  (*pv3).insert(i);
        //  rA.insert(i);
    }
    cout << "Printing pV3 float -> string (greater)" << endl;
    cout << *pV3 ;
}

void DemoDynamicMatrixes(){

    cout << "----------------mat1--------------------" << endl;
    CMatrix<MatrixTraitFloat> mat1(3, 4);
    mat1.fill(1);
    //cout << "k : " << mat1.m_rows<<endl;
    cout << mat1;

    cout << "----------------mat1--------------------" << endl;
    CMatrix<MatrixTraitFloat> mat2(4, 5);
    mat2.fill(2.5);
    cout << mat2;

    cout << "----------------mat1*mat2--------------------" << endl;
    // TODO #1: overload operator*(CMatrix<Traits> &other)
    CMatrix<MatrixTraitFloat> mat3 = mat1 * mat2;
    cout << mat3;

    cout <<endl;
    cout << "----------------Iterator matrix--------------------" << endl;
    // TODO #2: Create Iterator for CMatrix
    cout <<endl<< "----mat1----" << endl;
    foreach(mat1, ::print<TX>);
    cout << endl;

    cout <<endl<< "----mat1 sumando un contador----" << endl;
    TX x = 1;
    // // Lambda function
    // foreach(mat1, [x](TX &n){ n += x; x++; });
    // foreach(mat1, ::print<TX>); cout << endl;
    // ClassX<TX> ope(5);
    // foreach(mat1, ope);
    // foreach(mat1, ::print<TX>); cout << endl;
    // foreach(mat1, ClassX<TX>(8) );
    // foreach(mat1, ::print<TX>); cout << endl;

     // // TODO #3: prepare Matrix to be used as a matrix from outside
    // // overload operator[](size_t row)
    cout << "----------------Operator [] and ()-------------------" << endl;
    mat1[2][3] = 8.2;
    mat1(2, 2) = 7.5; // Operator () is returning a value_type &
    cout << mat1;
    cout << endl;
}

void DemoPreandPostIncrement(){
    int x = 10, y, z;
    y = x++;
    cout << "y=" << y << " x=" << x << endl;
    x = 10;
    z = ++x;
    cout << "z=" << z << " x=" << x << endl;
}

void DemoArray(){   
    cout << "Hello from DemoArray()" <<endl;
    cout << "Vector #1()" <<endl;
    
    CArray< TraitArrayIntInt > v1("Antonio"); 
    for(auto i = 0 ; i < 15 ; i++)
        v1.insert(i, i+5);   //  insert(&v1);

    cout << "Vector #2()" <<endl;
    CArray< TraitFloatLong > v2("Cristian Vera"), 
           *pV3 = new CArray< TraitFloatLong >("Guiomar ABC");
    auto &rA = *pV3;
    for(auto i = 100 ; i < 112 ; i++)
    {   v2.insert(sqrt(i), i);
        pV3->insert(i, sqrt(i));
        //  (*pv3).insert(i);
        //  rA.insert(i);
    }
    cout << "Printing V1 (TraitArrayIntInt)" << endl;
    cout << v1; // v1.print(cout);

    cout << "Printing V2 (TraitFloatLong)" << endl;
    ostream &tmp = cout << v2 << "More text" << endl;
    tmp << "Hola !!!" << endl;
    cout << &tmp << "..." << &cout <<endl;
    // cout << x << f << y << endl;

    cout << "Printing pv3 (TraitFloatLong)" << endl;
    pV3->print(cout);
    // (*pV3).print();     *pV3 is already an object
    // rA.print();          rA is also an object
    // pV3[0].print();      pV3 is also an array with just 1 element [0]
    // (*(pV3+0)).print();
    // (*(0+pV3)).print();
    // 0[pV3].print();
    // delete pV3;

    // Using an array with []
    for(auto i = 0 ; i < v2.size() ; i++)
        cout << "v2[" << i << "] = " << v2[i] << endl;
    ofstream of("test.txt", ios::out);
    of << v2 << endl; 
    cout << "DemoArray finished !" << endl;

    // using TraitStringString = ArrayTrait<string, string  , std::less<NodeArray<string, string> &>>;
    // CArray< TraitStringString > vx("Ernesto Cuadros");
    // vx.insert("Ernesto", "Cuadros");
    // vx.insert("Luis"   , "Tejada");
    // vx.insert("Jorge"  , "Lozano");
    // vx.insert("Edson"  , "Caceres");
    // vx.insert("Franz"  , "Maguiña");
    // vx.print(cout);
}

void DemoIterators(){
    CArray< TraitArrayIntInt > v1("Jorge");
    
    v1.insert(30, 40);
    v1.insert(18, 45);
    v1.insert(20, 35);
    v1.insert(7 , 64);
    v1.insert(12, 25);
    v1.insert(8 , 17);

    cout << v1 << endl;
    // array_forward_iterator<CArray< TraitArrayIntInt >> iter = v1.begin();
    //CArray< TraitArrayIntInt >::iterator iter = v1.begin();
    auto iter = v1.begin();
    foreach(iter, v1.end(), ::increment<TX, 7>);
    cout << v1 << endl;
    foreach(v1, ::increment<TX, 4>);
    cout << v1 << endl;

    foreach(v1, ::print<TX>);
    cout << endl;
    // Lambda function
    int x = 3;
    foreach(v1, [x](TX &n){ n *= 2*x; });
    foreach(v1, ::print<TX>); cout << endl;
    ClassX<TX> ope(5);
    foreach(v1, ope);
    foreach(v1, ::print<TX>); cout << endl;
    foreach(v1, ClassX<TX>(8) );
    foreach(v1, ::print<TX>); cout << endl;
}

void DemoReverseIterators(){
    cout << "DemoReverseIterators: " << endl;
    CArray< TraitArrayIntInt > v1("Edson Cáceres");
    v1.insert(30, 40);
    v1.insert(18, 45);
    v1.insert(20, 35);
    v1.insert(7 , 64);
    v1.insert(12, 25);
    v1.insert(8 , 17);

    cout << "Printing asc : " << endl;
    cout << v1 << endl;
    cout << "Printing desc : " << endl;
    foreach(v1.rbegin(), v1.rend(), ::print<TX>);
}

void DemoHeap()
{
    cout << "Hello from DemoHeap()" <<endl;
}

void DemoBinaryTree()
{   
    cout << "Hello from DemoBinaryTree()" <<endl;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1,60);
    BinaryTree<Traits_BNTDesc> bt;
    vector<int> vect0={75,65,22,8,45,20,5,7,46,48,40,41};
    vector<int> vect1={35,32,30,27,25,22,11,5,3,2,1};
    vector<int> vect2={35,45,50,57,75,82,91,95,103,112,120};
    vector<int> vect3= {49,47,22,20,41,11,23,55,40,35,42,38,10,27,34,60,9,2,6,31,26};
    vector<int> vect4= {49,47,22,20,41,10,22,55,40,35,42,38,9,27,34,60,9,2,6,31,26};
    vector<int> vect5={41,49,22,10,26,44,54,25,33,59,8,5,9,1,30,2,55,46,18,43,40};
    vector<int> vect6= {11,6,15,12,20,3,2,5,9,7,10};
    vector<int> vect7= {25,13,37,9,18,27,53,45,37};
    for(auto i=0;i<=8;i++){
        int tmp= dist(gen);
        int tmp2= dist(gen);
        cout<<vect7[i]<<"-->";
        bt.insert(vect7[i],tmp2);
        // cout<<tmp<<"-->";
        // bt.insert(tmp,tmp2);
    }
    cout<<endl;
    bt.print(cout);

    cout<<"\nRunning in Order"<<endl;
    bt.inorder(cout);

    cout<<"\nRunning in PostOrder"<<endl;
    bt.postorder(cout);

    cout<<"\nRunning in PreOrder"<<endl;
    bt.preorder(cout);
    cout<<endl;
    cout<<"\nForeach in Order"<<endl;
    foreach_btree_inorder(bt,::print<int>);
    cout<<"\nForeach in Post Order"<<endl;
    foreach_btree_posorder(bt,::print<int>);
    cout<<"\nForeach in Pre Order"<<endl;
    foreach_btree_preorder(bt,::print<int>);

}
void Nodes(){
    cout<<"Test Node BinaryTree"<<endl;
    using Node = typename Traits_BNTDesc::Node;
    Node    *m_pRoot = nullptr;
    Node bt(m_pRoot,3,5,nullptr,nullptr);
    cout<<bt.getData()<<endl;
    
    cout<<"Test Node AVL"<<endl;
    using NodeA= typename Traits_AVLDesc::Node;
    NodeA  *m_pRootA= nullptr;
    NodeA  btA(m_pRootA,4,6,nullptr,nullptr);
    cout<<btA.getData()<<endl;
    cout<<btA.m_depth<<endl;

}
void guardarVectorEnArchivo(const std::vector<int>& vec, const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        for (const int& numero : vec) {
            archivo << numero << "\n";
        }
        archivo.close();
        //std::cout << "Vector guardado en " << nombreArchivo << std::endl;
    } else {
        //std::cerr << "No se pudo abrir el archivo." << std::endl;
    }
}
void DemoAVL()
{   
    cout << "Hello from AVL" <<endl;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1,60);
    CAVL<Traits_AVLDesc>bt;
    //BinaryTree<Traits_BNTDesc> bt;
    vector<int> vect0={75,65,22,8,45,20,5,7,46,48,40,41};
    vector<int> vect1={35,32,30,27,25,22,11,5,3,2,1};
    vector<int> vect6= {20,15,12,11,10,9,7,6,5,3,2,1};
    vector<int> vect2={35,45,50,57,75,82,91,95,103,112,120};
    vector<int> vect3= {49,47,22,20,41,11,23,55,40,35,42,38,10,27,34,60,9,2,6,31,26};
    vector<int> vect3k= {49,47,22,20,41,11,30,55,23,35,42,38,10,27,34,60,9,2,6,31,26};
    vector<int> vect4= {49,47,22,20,41,10,22,55,40,35,42,38,9,27,34,60,9,2,6,31,26};
    vector<int> vect5={41,49,22,10,26,44,54,25,33,59,8,5,9,1,30,2,55,46,18,43,40};
    vector<int> vect7={10,20,22,8,16,24};
    vector<int> vect8={10,20,22,8,15,5,1,16,24,20};
    vector<int> vect3p={7,40,19,15,18,24,5,41,48,10,9,35,8,25,24};
    vector<int> vect3q={9,27,37,13,25,18,53,45,37,8,54,55,4,9,28,50,20,55};
    vector<int> vect3s ={35,9,59,53,39,57,54,27,42,28,9,35,11};
    vector<int> vect_s= {};
    vector<int> vect_r2={5,11,12,40,4,32,41,20,40,33,27,25,47,24,9,46,3,8,36,20};
    vector<int> vect_r={41,54,46,25,53,53,44,39,50,20,39,55,57,46,42,39,12,37,45,10};
    for (auto i=0;i<=19;i++){
        int tmp= dist(gen);
        int tmp2= dist(gen);
        vect_s.push_back(tmp);
    }
    guardarVectorEnArchivo(vect_s, "mi_vector.txt");
    for(auto i=0;i<=19;i++){
        // int tmp= dist(gen);
        // int tmp2= dist(gen);
        cout<<vect_s[i]<<"-->";
        bt.insert(vect_s[i],0);
        //cout<<tmp<<"-->";
        // vect_r.push_back(tmp);
        // bt.insert(tmp,tmp2);
    }
    
    cout<<endl;
    bt.print(cout);

    cout<<"\nRunning in Order"<<endl;
    bt.inorder(cout);

    cout<<"\nRunning in PostOrder"<<endl;
    bt.postorder(cout);

    cout<<"\nRunning in PreOrder"<<endl;
    bt.preorder(cout);
    cout<<endl;
    cout<<"\nForeach in Order"<<endl;
    foreach_btree_inorder(bt,::print<int>);
    cout<<"\nForeach in Post Order"<<endl;
    foreach_btree_posorder(bt,::print<int>);
    cout<<"\nForeach in Pre Order"<<endl;
    foreach_btree_preorder(bt,::print<int>);

}



void DemoHash()
{
    cout << "Hello from DemoHash()" <<endl;
}
