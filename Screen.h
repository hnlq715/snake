#ifndef _screen
#define _screen
#include <iostream>
#include <ncurses/ncurses.h>
#include "LivingArea.h"
#include "Snake.h"

namespace scr{

const int STDIN = 0;
class Screen
{
  public:
         Screen();
         Screen(WINDOW *pwin);
         void init();
		 void process();
         void refresh();
         void draw();

  private:
         Snake snake;
         WINDOW *win;
};

}
#endif
