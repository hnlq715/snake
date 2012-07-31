#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <ncurses/ncurses.h>
#include <iostream>
#include "LivingArea.h"
#include "Screen.h"
#include "Snake.h"

using namespace std;
using namespace scr;

namespace scr{
Screen::Screen()
{
 // LivingArea area;
 // snake=Snake();
  //while(refresh()>=0); 
}
Screen::Screen(WINDOW *pwin)
{
  win = pwin;
  while(refresh()>=0);
}
int Screen::refresh()
{
  int key = -1;
  fd_set set;
  FD_ZERO(&set);
  FD_SET(STDIN, &set);
  struct timeval timeout;
  timeout.tv_sec = 0;
  timeout.tv_usec = 600000;
  snake.lifeProbing();
  if(!snake.getIsAlive())
    return -1;
  if(select(STDIN+1, &set, NULL, NULL, &timeout) < 0)
    return -1;
  if(FD_ISSET(0, &set))
  {
    while((key = getch()) == -1);
      snake.receivingNavi(key);
  }
  snake.move();
  this->draw();  
  return 0;
}
void Screen::draw()
{
   //wrefresh(win); 
   snake.draw(win);
} 

}
