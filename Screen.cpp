#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <ncurses/ncurses.h>
#include <iostream>
#include "LivingArea.h"
#include "Screen.h"
#include "Snake.h"

using namespace std;
using namespace scr;

extern WINDOW* gwin;

namespace scr{
Screen::Screen()
{
 // LivingArea area;
 // snake=Snake();
  //while(refresh()>=0); 
}

void Screen::init()
{
	gwin = newwin(15, 60, 1, 3);
	box(gwin, 0, 0);
	mvwprintw(gwin, 0, 2, "GAME");
    win = gwin;
}

void Screen::process()
{
	int key = -1;
	fd_set set;
	int val = fcntl( STDIN, F_GETFL, 0 );
	fcntl( STDIN, F_SETFL, val|O_NONBLOCK );

	struct timeval timeout;
	timeout.tv_sec = 0;
	timeout.tv_usec = 600000;


    for(;;)
    {
    	FD_ZERO(&set);
		FD_SET( STDIN, &set );

		if(select(STDIN+1, &set, NULL, NULL, &timeout) < 0)
		  return;

		snake.lifeProbing();
		if(!snake.getIsAlive())
		  return;

		if(FD_ISSET(STDIN, &set))
		{
		  while( ( key = getch() ) == -1 );
            snake.receivingNavi( key );
		}
        refresh();
    }
    return;
}

void Screen::refresh()
{
  snake.move();
  draw();
  return;
}
void Screen::draw()
{
   snake.draw( win );
} 

}
