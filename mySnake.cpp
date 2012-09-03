#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cassert>
#include <iostream>
#include <ncurses/ncurses.h>
#include "Screen.h"
#include "LivingArea.h"

using namespace std;
using namespace scr;

WINDOW *logwin;
WINDOW *gwin;

#define INITRUNLOG()     (logwin = newlogw())
#define RUNLOG(str)      (runlog(logwin, str))
#define DESTROYRUNLOG()  (delwin(logwin))


WINDOW* newlogw();
void runlog(WINDOW *win, const char *str);
void cleanline(WINDOW *win, int y, int x);
void initSreen(void);
void exitSreen(void);

const char log[] = "  Press 'q' or 'Q' to quit."
                   "  Press 'w/s/a/d' or 'W/S/A/D' to move the snake."
                   "  Info:";

int main(int argc,char* argv[])
{
  initSreen();
  INITRUNLOG();
  RUNLOG(log);
  
  Screen screen;
  screen.init();
  screen.process();

  exitSreen();
}

WINDOW* newlogw()
{
 WINDOW *win = newwin(LOGWIN_YLEN, LOGWIN_XLEN, GAMEWIN_YLEN + 2, 3);
 box(win, 0, 0);
 mvwprintw(win, 0, 2, " LOG ");
 wrefresh(win);

 return win;
}

void runlog(WINDOW *win, const char *str)
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

void initSreen()
{
  initscr();
  raw();
  noecho();
  keypad(stdscr,TRUE);
  curs_set(0);
  refresh();
}

void exitSreen()
{
  delwin(gwin);
  endwin();
  exit(0);
}
