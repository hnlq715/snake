#ifndef _snakeNode
#define _snakeNode
class SnakeNode
{
  public:
         SnakeNode();
         SnakeNode(int ypointer,int xpointer);
         //2010-08-25 王华杰 参照dave_cn的c代码，先纵坐标，再横坐标
         int y;
         int x;
};
#endif
