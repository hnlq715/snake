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
        //2010-08-25 王华杰 参照dave_cn的c代码，先纵坐标，再横坐标
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
