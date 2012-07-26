#include "stdio.h"
#include "dlinkedList.h"
#include <cassert>
#include <iostream>
using namespace std;
int main(int argc,char* argv[])
{
   List<int> x(6,8);
   cout<<"x.size()="<<x.size()<<endl;
   assert(x.size()==6);
   int t;
   x.retrieve(1,t);
   assert(t==8);
   x.print_list(cout);
   x.insert(2,9);
   x.print_list(cout);
   x.retrieve(3,t);
   assert(t==9);
   x.erase(6);
   assert(x.size()==6);
   x.print_list(cout);
   x.erase(0);
   assert(x.size()==5);
   x.retrieve(2,t);
   assert(t==9);
   x.print_list(cout);
   x.erase(1);
   assert(x.size()==4);
   x.print_list(cout);
   return 0;
}
