#ifndef _node
#define _node
#include "stdio.h"
#include <iostream>
using namespace std;
template<class T>
class Node 
{
  public:
        T data;
        Node<T> * next;
        Node<T> * prev;

};
#endif
