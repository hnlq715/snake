#ifndef _list
#define _list
#include "stdio.h"
#include <iostream>
#include "node.h"
using namespace std;

template<class T>
class List
{
  public:
         friend class LivingArea;
         friend class Snake;
         List();
         List(int size,T defaultValue);
         ~List();
         bool empty();
         int size();
         int locate(const T& one);
         bool retrieve(int k,T& one);
         List<T>& insert(int k,const T& one);
         List<T>& erase(int k);
         List<T>& push_back(const T& one);
         List<T>& pop_back(T& one);
         void print_list(ostream & writter);
         void init();
  private:
         int n;
         Node<T> *left,*right;
};

template<class T>
List<T>::List()
{
  init();
}

template<class T>
List<T>::List(int size,T defaultValue)
{
  Node<T> *head=new Node<T>();
  head->next=head;
  head->prev=head;
  left=head;
  right=head;
  n=0;
  cout<<"n="<<n<<endl;
  cout<<"List Constructor Begin"<<endl;
  for(int i=0;i<size;i++)
  {
  cout<<"n="<<n<<endl;
     push_back(defaultValue);
  }
  print_list(cout);
  cout<<"n="<<n<<endl;
  cout<<"List Constructor"<<endl;   
}

template<class T>
List<T>::~List()
{
  Node<T> *node=0;
  while(!empty())
  {
    node=left->next;
    delete left;
    n--;
    left=node;
  }
  delete left;
}

template<class T>
bool List<T>::empty()
{
 // if(rear->next==rear)
 //   return true;
 // else
 //   return false;
  if(n==0)
    return true;
  else 
    return false;
}

template<class T>
void List<T>::init()
{
  Node<T> *head=new Node<T>();
  head->next=head;
  head->prev=head;
  right=head;
  left=head;
  n=0;
  // cout<<"n="<<n<<endl;
}

template<class T>
int List<T>::size()
{
  return n;
}

template<class T>
int List<T>::locate(const T& one)
{
  Node<T> *p=left->next;
  for(int i=0;i<n;i++)
  {
     if(p->data==one)
     {
       return true;
     }
     p=p->next;
  }
  return false;
}

template<class T>
bool List<T>::retrieve(int k,T& one)
{
  if(k>n-1) 
    return false;
  Node<T> *p=left->next;
  for(int i=0;i<k;i++)
  {
    p=p->next;
  }
  one=p->data;
  return true;
  
}

template<class T>
List<T>& List<T>::insert(int k,const T& one)
{
  if(k>n-1)
  {
    ;
  }
  Node<T> *p=left;
  for(int i=0;i<k;i++)
  {
    p=p->next;
  }
  Node<T> *old=p->next;
  Node<T> *node=new Node<T>();
  node->data=one;
  node->next=old;
  node->prev=p;  
  p->next=node;
  old->prev=node;
  if(k==n-1)
  { 
    right=node;
  }

  n++;
  return *this;
}

template<class T>
List<T>& List<T>::erase(int k)
{
   if(k>n-1)
   {
     ;
   }
   Node<T> *p=left;
   for(int i=0;i<=k-1;i++)
   {
     p=p->next;
   }
   Node<T> *deleted=p->next;
   p->next=deleted->next;
   deleted->next->prev=p;
   if(k==n-1)
     right=p;
   delete deleted;
   n--;
}

template<class T>
List<T>&  List<T>::push_back(const T& one)
{
   Node<T> *node=new Node<T>();
   node->data=one;
   //if(rear->next==rear)
   //{
   //   rear->next=node;
   //   node->next=rear;
   //   rear=node;
   //}
   //else
   //{
   //  rear->next=node;
   //  node->next=rear->next;
   //  rear=node;
   //}
   right->next=node;
   node->next=left;
   node->prev=right;
   left->prev=node;
   right=node;
   n++;
   return (*this);
}

template<class T>
List<T>& List<T>::pop_back(T& one)
{
   if(n==0)
   {
     ;
   }
   else
   {
     Node<T> *prev=right->prev;
     prev->next=left;
     left->prev=prev;
     one=right->data;
     delete right;
     right=prev;
     n--;
   }
   return (*this);
}

template<class T>
void List<T>::print_list(ostream & writter)
{
   Node<T> *p=left->next;
   for(int i=0;i<n;i++)
   {
     writter<<p->data<<",";
     p=p->next;
   }
   writter<<endl;
}

#endif
