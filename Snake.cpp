#include <stdio.h>
#include <stdlib.h>
#include <ncurses/ncurses.h>
#include <iostream>
#include "Snake.h"
#include "LivingArea.h"
using namespace std;

Snake::Snake()
{
  area=LivingArea();
   dir=DIR_LEFT;
 // cout<<"test"<<endl;
  //2010-08-25 王华杰 使用双链表
   SnakeNode node=SnakeNode(7,50);
  // cout<<node.y<<endl;
   list.push_back(node);
  // list.push_back(SnakeNode(7,50));
  // SnakeNode t;
  // list.retrieve(0,t);
  // cout<<"y: "<<t.y<<endl;
  // cout<<"x: "<<t.x<<endl;
  node=SnakeNode(7,51);
  list.push_back(node);
  node=SnakeNode(7,52);
  list.push_back(node);
  node=SnakeNode(7,53);
  list.push_back(node);
 // cout<<list.n<<endl;
 // area=a;
  area.setSnake(this);

  isAlive=true;  
}
void Snake::lifeProbing()
{
   if(isSpiralDead())
   {
    //cout<<"isSpiralDead"<<endl;
     isAlive=false;
   }
   if(isClapseArea())
   {
     //cout<<"isClapseArea"<<endl;
     isAlive=false;
   }
}
bool Snake::getIsAlive()
{
  return isAlive;
}
void Snake::move()
{
  area.blockChecking();
  if(area.isEattingPhase())
  {
    area.eraseBlock();
    selfGeneration();
  }
  bodyReshape();
  //area.eraseBlock();
}
void Snake::selfGeneration()
{
  SnakeNode t;
  list.retrieve(list.n-1,t);
  switch (dir) {
  case DIR_UP:
     t.y = t.y - 1;
     t.x = t.x;
     break;

  case DIR_DOWN:
     t.y = t.y + 1;
     t.x = t.x;
     break;

  case DIR_LEFT:
     t.y = t.y;
     t.x = t.x - 1;
     break;

  case DIR_RIGHT:
     t.y = t.y;
     t.x = t.x + 1;
     break;

  default:
     break;
 }
  list.push_back(t);
    
}
void Snake::bodyReshape()
{
  SnakeNode t;
  list.pop_back(t);
  footprinty=t.y;
  footprintx=t.x;
 // cout<<"y:"<<t.y<<" x:"<<t.x<<endl;
  //char tmp[256];
  //sprintf(tmp,"y: %d x: %d",footprinty,footprintx);
  //RUNLOG(tmp);
 // SnakeNode t;
  list.retrieve(0,t);
  switch (dir)
  {
   case DIR_UP:
     t.y = t.y - 1;
     t.x = t.x;
     break;

   case DIR_DOWN:
     t.y = t.y + 1;
     t.x = t.x;
     break;

   case DIR_LEFT:
     t.y = t.y;
     t.x = t.x - 1;
     break;

   case DIR_RIGHT:
     t.y = t.y;
     t.x = t.x + 1;
     break;

   default:
     break;
  }
  list.insert(0,t);
  
}
void Snake::eraseFootPrint(WINDOW *win)
{
  if (footprinty != 0 && footprintx != 0)
  {
     mvwaddch(win, footprinty, footprintx, ' ');
  }

}
bool Snake::isSpiralDead()
{
  Node<SnakeNode> *head=(list.left)->next;
  Node<SnakeNode> *pnode=head->next;
  for(int i=1;i<list.n;i++,pnode=pnode->next)
  {
     if( (head->data).y == (pnode->data).y && (head->data).x == (pnode->data).x )
       return true;
  }
  return false;
}
bool Snake::isClapseArea()
{
  Node<SnakeNode> *pnode=(list.left)->next;
  if ( (pnode->data).y <= 0 || (pnode->data).y >= area.y
   || (pnode->data).x <= 0 || (pnode->data).x >= area.x)
   return true;
  return false;

}
void Snake::receivingNavi(int key)
{
  switch (key) {
     case 'w':
     case 'W':
         (dir == DIR_DOWN) ? : (dir = DIR_UP);
         break;
    
     case 's':
     case 'S':
         (dir == DIR_UP) ? : (dir = DIR_DOWN);
         break;
    
     case 'a':
     case 'A':
         (dir == DIR_RIGHT) ? : (dir = DIR_LEFT);
         break;
    
     case 'd':
     case 'D':
         (dir == DIR_LEFT) ? : (dir = DIR_RIGHT);
         break;
    
//     case 'q':
//     case 'Q':
//         return -1;

     default:
         break;
     }

}
void Snake::draw(WINDOW *win)
{
  eraseFootPrint(win);
  area.draw(win);
  Node<SnakeNode> *pnode=(list.left)->next;
  /*  cout<<"y:"<<(pnode->data).y<<" x:"<<(pnode->data).x<<endl;
   SnakeNode t;
   list.retrieve(0,t);
   cout<<"y: "<<t.y<<endl;
   cout<<"x: "<<t.x<<endl;
  */
 for(int i=0;i<list.n;i++,pnode=pnode->next)
  {
   // cout<<"y:"<<(pnode->data).y<<" x:"<<(pnode->data).x<<endl;
    mvwaddch(win,(pnode->data).y,(pnode->data).x,SHAPE_SNAKE);
  }
  wrefresh(win);

}

