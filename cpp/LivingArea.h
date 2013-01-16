#ifndef _livingArea
#define _livingArea

#include <ncurses/ncurses.h>
#include "Block.h"

const int GAMEWIN_YLEN = 15;
const int GAMEWIN_XLEN = 60;
const int LOGWIN_YLEN = 7;
const int LOGWIN_XLEN = GAMEWIN_XLEN;
const int LOGBUF_NUM = LOGWIN_YLEN-2;
const int LOGBUF_LEN = GAMEWIN_XLEN-2;

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
