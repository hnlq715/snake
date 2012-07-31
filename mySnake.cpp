#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#include <cassert>
#include <iostream>
#include <ncurses/ncurses.h>
#include "Screen.h"
using namespace std;

#define GAMEWIN_YLEN 15
#define GAMEWIN_XLEN 60
#define LOGWIN_YLEN 7
#define LOGWIN_XLEN (GAMEWIN_XLEN)
#define LOGBUF_NUM (LOGWIN_YLEN-2)
#define LOGBUF_LEN (GAMEWIN_XLEN-2)

WINDOW *logwin;
#define INITRUNLOG()     logwin = newlogw()
#define RUNLOG(str)      runlog(logwin, str)
#define DESTROYRUNLOG()  delwin(logwin)


WINDOW* newlogw();
void runlog(WINDOW *win, char *str);
void cleanline(WINDOW *win, int y, int x);


int main(int argc,char* argv[])
{
  initscr();
  raw();
  noecho();
  keypad(stdscr,TRUE);
  curs_set(0);
  refresh();
  INITRUNLOG();
  //RUNLOG("  Press 'q' or 'Q' to quit.");
 //RUNLOG("  Press 'w/s/a/d' or 'W/S/A/D' to move the snake.");
 //RUNLOG("Info:");
  WINDOW *gwin=newwin(15,60,1,3);
  box(gwin,0,0);
  mvwprintw(gwin,0,2,"GAME");

  Screen screen(gwin); 
 // screen.draw(gwin);
  wrefresh(gwin);  
  getch();
  delwin(gwin);
  endwin();
  return 0;
}
WINDOW* newlogw()
{
 WINDOW *win = newwin(LOGWIN_YLEN, LOGWIN_XLEN, GAMEWIN_YLEN + 2, 3);
 box(win, 0, 0);
 mvwprintw(win, 0, 2, " LOG ");
 wrefresh(win);

 return win;
}

void runlog(WINDOW *win, char *str)
{
 static char logbuf[LOGBUF_NUM][LOGBUF_LEN];
 static int  index = 0;

 strcpy(logbuf[index], str);

 int i = 0;
 for (; i < LOGBUF_NUM; ++i) {
     cleanline(win, i+1, 1);
     mvwprintw(win, i+1, 1, logbuf[(index+i) % LOGBUF_NUM]);
     wrefresh(win);
 }

 index = (index + LOGBUF_NUM - 1) % LOGBUF_NUM;
}

void cleanline(WINDOW *win, int y, int x)
{
 char EMPTYLINE[LOGBUF_LEN] = {0};
 memset(EMPTYLINE, ' ', LOGBUF_LEN-1);

 mvwprintw(win, y, x, EMPTYLINE);
}

