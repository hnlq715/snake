#ifndef _livingArea
#define _livingArea

#include <ncurses/ncurses.h>
#include "Block.h"

#define GAMEWIN_YLEN 15
#define GAMEWIN_XLEN 60
#define SHAPE_FOOD '@'
class Snake;
class LivingArea
{
  public:
        LivingArea();
        void blockChecking();
        void eraseBlock();
        void setSnake(Snake *psnake);
        void draw(WINDOW *win);
        bool isEattingPhase();
        int y;
        int x;
  private:
        Block *block;
        bool isBlockExisted;
        Snake *snake;

        void generateBlock();
        bool isDigestPhase();

};
#endif
