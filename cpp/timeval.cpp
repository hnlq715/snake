#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
//extern "C"
//{
#include <ncurses.h>
//}
using namespace std;
int main(int argc,char* argv[])
{
  initscr();
  raw();
  noecho();
  keypad(stdscr,TRUE);
  curs_set(0);
  refresh();
  
  WINDOW *gwin=newwin(15,60,1,3);
  box(gwin,0,0);
  mvwprintw(gwin,0,2,"LOG");
  int i=1;
  while(i<=100000000)
  {
  fd_set set;
  FD_ZERO(&set);
  FD_SET(0,&set);
  struct timeval timeout;
  timeout.tv_sec=0;
  timeout.tv_usec=600000;
  if(select(1,&set,NULL, NULL,&timeout)<0)
    return -1; 
  if(FD_ISSET(0,&set))
  {
    while((getch())==-1);
   mvwaddch(gwin,3,i,'t');
  }
  mvwaddch(gwin,3,i,'y');
  wrefresh(gwin);
   i++;
  }
  getch();
  delwin(gwin);
  endwin();
}
