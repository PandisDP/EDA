#ifndef __RECORRRER_H__  
#define __RECORRRER_H__ 
//#include "object_function.h"
using namespace std;

template <typename T>
void f2(T &x)
{  cout << x << "  "; }

template <typename T>
void f1(T &x)
{  x+= 5; }

template <typename Iterator, typename F>
void foreach_btree(Iterator ItBegin, Iterator ItEnd, F ope)
{
  auto iter = ItBegin;
  for(; iter != ItEnd;++iter){
    ope(*iter);
  }
  ope(*ItEnd);
  ItEnd.fill_status();
}
template <typename Iterator, typename F>
void foreach(Iterator ItBegin, Iterator ItEnd, F ope)
{
  auto iter = ItBegin;
  for(; iter != ItEnd;++iter){
    ope(*iter);
  }
  ope(*ItEnd);
}

// template <typename Iterator, typename Callable, typename... Args>
// void foreach(Iterator ItBegin, Iterator ItEnd, Callable op, Args&&... args)
// {
//     for (auto iter = ItBegin; iter != ItEnd; ++iter)
//     {
//         if constexpr (is_void_v<invoke_result_t<Callable, typename Iterator::value_type, Args...>>)
//         {
//             cout << "Function is returning: void!" << endl;
//             invoke(op, *iter, forward<Args>(args)...);
//             //...  // do something before we return
//         }
//         else // return type is not void:
//         {
//             auto ret = invoke(op, *iter, forward<Args>(args)...);
//             cout << "Function is returning: " << type_name<decltype(ret)>() << endl;
//             //...  // do something (with ret) before we return
//         }
//     }
// }

// #1
template <typename Container, typename F>
void foreach_btree(Container &container, F ope)
{  
    foreach_btree(container.begin(), container.end() , ope);
}
template <typename Container, typename F>
void foreach(Container &container, F ope)
{  
    foreach(container.begin(), container.end() , ope);
}

// template <typename Iterator, typename Callable, typename... Args>
// void foreach(Iterator ItBegin, Iterator ItEnd, Callable op, Args&&... args)
// {   foreach(container.begin(), container.end(), ope);
// }

// TODO implementar el foreach inverso
// # 2
// template <typename Container, typename F>
// void foreach_inverso(Container &container, F ope)
// { foreach(container.rbegin(), container.rend(), ope);
// }

// template <typename Container>
// void foreach(Container &container)
// {
//     using T = typename Container::value_type;
    // using T = typename Container::value_type;
    // foreach(container, print<T>);  cout << endl; // recorre imprimiendo
    // foreach(container, inc<T>);  // recorre incrementando
    // foreach(container, print<T>);  cout << endl; // recorre imprimiendo

//     // funciones lambda
//     foreach(container, [](T &n){ n-= 5;}); cout << endl; // -5 a todos
//     foreach(container, print<T>);  cout << endl; // recorre imprimiendo
    
//     OperacionEspecial<T> ope; 
//     foreach(container, ope);  
//     foreach(container, print<T>);  cout << endl;
// }

#endif
