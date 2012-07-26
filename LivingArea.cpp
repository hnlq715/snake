#include <stdio.h>
#include <stdlib.h>
#include <ncurses/ncurses.h>
#include "Snake.h"
#include "LivingArea.h"
using namespace std;

LivingArea::LivingArea()
{
 y=GAMEWIN_YLEN;
 x=GAMEWIN_XLEN;
 block=new Block();
 isBlockExisted=false;
}
void LivingArea::generateBlock()
{
   isBlockExisted=true;
   //cout<<isBlockExisted<<endl;   
   block->y = random() % (y - 1) + 1;
   block->x = random() % (y - 1) + 1;

}
void LivingArea::blockChecking()
{
    //cout<<isBlockExisted<<endl;
    // digestProcessing();
    if(!isBlockExisted) 
       generateBlock();
}
void LivingArea::eraseBlock()
{
    isBlockExisted=false;
}
bool LivingArea::isDigestPhase()
{  
    
    Node<SnakeNode> *pnode=(snake->list).left->next;
    for(int i=0;i<(snake->list).n;i++,pnode=pnode->next)
      if(block->y==(pnode->data).y&&block->x==(pnode->data).x)
        return true;
    return false;
   
}
bool LivingArea::isEattingPhase()
{
    Node<SnakeNode> *pnode=(snake->list).left->next;
    if(block->y==(pnode->data).y&&block->x==(pnode->data).x)
        return true;
    return false;

}
void LivingArea::setSnake(Snake *psnake)
{ 
   snake=psnake;
}
void LivingArea::draw(WINDOW *win)
{
  mvwaddch(win, block->y,block->x, SHAPE_FOOD);
  mvwprintw(win,y-1,2," Speed: %d ",1);
  wrefresh(win);
}
