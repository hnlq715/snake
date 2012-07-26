#include "stdio.h"
#include "dlinkedList.h"
#include <cassert>
#include <iostream>
using namespace std;
class SnakeNode
{
  public:
         SnakeNode(int ypointer=0,int xpointer=0);
         int y;
         int x;
};
/*
SnakeNode::SnakeNode()
{
  y=0;
  x=0;
}
*/
SnakeNode::SnakeNode(int ypointer,int xpointer)
{
  y=ypointer;
  x=xpointer;
}

int main(int argc,char* argv[])
{
   SnakeNode node=SnakeNode(4,50);
   List<SnakeNode> x;
   x.push_back(node);
   node=SnakeNode(4,51);
   x.push_back(node);
   node=SnakeNode(4,52);
   x.push_back(node);
   node=SnakeNode(4,53);
   x.push_back(node);
   cout<<"x.size()="<<x.size()<<endl;
   assert(x.size()==4);
   SnakeNode t;
   x.retrieve(1,t);
   assert(t.x==51);
   //x.print_list(cout);
   node=SnakeNode(3,500);
   x.insert(3,node);
   //x.print_list(cout);
   x.retrieve(3,t);
   assert(t.x==500);
   node=SnakeNode(0,120);
   x.insert(0,node);
   x.retrieve(0,t);
   assert(t.x==120);
   cout<<t.x<<endl;
   x.retrieve(1,t);
   assert(t.x==50);
   cout<<t.x<<endl;
   return 0;
}
