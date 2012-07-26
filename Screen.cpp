#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <ncurses/ncurses.h>
#include <iostream>
#include "LivingArea.h"
#include "Snake.h"
#include "Screen.h"
using namespace std;
Screen::Screen()
{
 // LivingArea area;
 // snake=Snake();
  //while(refresh()>=0); 
}
Screen::Screen(WINDOW *pwin)
{
  win=pwin;
  while(refresh()>=0);
}
int Screen::refresh()
{
   int key=-1;
  fd_set set;
  FD_ZERO(&set);
  FD_SET(0,&set);
  struct timeval timeout;
  timeout.tv_sec=0;
  //TODO 2010-08-25 王华杰 未考虑snake 的speedlevel
  timeout.tv_usec=600000;
  snake.lifeProbing();
  if(!snake.getIsAlive())
    return -1;
  if(select(1,&set,NULL,NULL,&timeout)<0)
     return -1;
  if(FD_ISSET(0,&set))
  {
    while((key=getch())==-1);
    snake.receivingNavi(key);
  }
  snake.move();
  draw();  
  return 0;
}
void Screen::draw()
{
   //wrefresh(win); 
   snake.draw(win);
} 
