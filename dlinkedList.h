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
  private:
         /*2010-08-17 王华杰 增加长度n*/
         int n;
         /*2010-08-12 王华杰 对于单循环链表，指针指向尾部方便插入，删除数据*i/
         /*2010-08-19 王华杰 对于双循环列表，left和right分别指向头部(空元素）和尾部（最后一个元素）*/
         Node<T> *left,*right;
};
template<class T>
List<T>::List()
{
  /*2010-08-12 王华杰 设置哨兵元素，该元素作为双循环链表的头部
 * 该元素的next指向自身，双循环链表的头尾指针均指向该元素 
 */
  Node<T> *head=new Node<T>();
  head->next=head;
  head->prev=head;
  right=head;
  left=head;
  n=0;
 // cout<<"n="<<n<<endl;
}
template<class T>
/*2010-08-06 王华杰 初始化size个数缺省值为defaultValue的元素*/
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
  /*2010-08-12 王华杰 利用push_back*/
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
  /*2010-08-12 王华杰 从哨兵元素开始delete*/
  /*2010-08-17 王华杰 新从尾指针指向元素开始释放，释放n+1个元素（包括头节点)*/
  Node<T> *node=0;
  while(!empty())
  {
    node=left->next;
    delete left;
    n--;
    left=node;
  }
  /*2010-08-17 王华杰 删除最后一个，注意不是次序最后一个*/
  delete left;
}
template<class T>
bool List<T>::empty()
{
  /*2010-08-17 王华杰 判断是否是空表*/
  /*2010-08-17 王华杰 新 改为判断n是否为0,因为析构时用到empty,析构时直接从rear指针开始删除，破坏了rear->next==rear的等式，且列表不再首尾连接*/
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
  /* 2010-08-17 王华杰 需要处理k>n-1的异常
    不用单独处理最后一位的插入
    如果插入第一位则将新创建元素的next指向head,再将head重新指向新创建的元素
  */
  if(k>n-1)
  {
    //抛出异常
  }
  Node<T> *p=left;
  for(int i=0;i<k;i++)
  {
    p=p->next;
  }
  /* 2010-08-18 王华杰 保存p->next*/
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
}
template<class T>
List<T>& List<T>::erase(int k)
{
    /* 2010-08-05 王华杰 需要处理k>n-1异常 */
    /* 2010-08-06 王华杰 如果删除第一个元素，则将head指向head->next 
 *  否则现找到欲删除元素的父元素(k-1),然后找到欲删除元素的next(k+1)
 *  如果欲删除的元素为最后一个，nextNode=0 此时不用特殊处理
 */
   if(k>n-1)
   {
     //抛出异常
   }
   Node<T> *p=left;
   /*2010-08-17 王华杰 找到k上一个元素准备关联*/
   /*2010-08-18 王华杰 当erase(0)时，不走循环 p->next即为第一个元素*/
   for(int i=0;i<=k-1;i++)
   {
     p=p->next;
   }
   /*2010-08-18 王华杰 保存p->next->next*/
   Node<T> *deleted=p->next;
   p->next=deleted->next;
   deleted->next->prev=p;
   /*2010-08-18 王华杰 如果k=n-1即删除最后一位元素，则应将尾指针指向倒数第二位元素（现在的最后一位）*/
   if(k==n-1)
     right=p;
   delete deleted;
   n--;
}
template<class T>
List<T>&  List<T>::push_back(const T& one)
{
   /* 2010-08-12 王华杰 将新增元素的next 指向哨兵元素，将尾指针指向新增元素
 * 注意 只有通过尾指针才能访问哨兵元素，增加新元素需要判断是否是空循环链表的情况 */
   /* 2010-08-19 王华杰 将头指针指向头部*/  
   Node<T> *node=new Node<T>();
   node->data=one;
   //if(rear->next==rear)
   //{
   //   /* 2010-08-12 王华杰 如果是空表，将哨兵元素（此时rear指向哨兵元素)的next指向node,将node的next指向哨兵元素,最后将rear移动到node上*/
   //   rear->next=node;
   //   node->next=rear;
   //   rear=node;
   //}
   //else
   //{
   //  /*2010-08-12 王华杰 如果不是空表，将最后一位元素(rear指向该元素)的next指向新增node,然后将新增元素的next指向哨兵元素(尾指针的next),最后将rear移动到node上*/   
   //  rear->next=node;
   //  node->next=rear->next;
   //  rear=node;
   //}
   /*2010-08-17 王华杰 可以不用区分空表*/
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
   /* 2010-08-12 王华杰 如果是空表，则抛出异常*/
   /* 2010-08-17 王华杰 或者判断n==0*/
   if(n==0)
   {
     //抛出异常
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
