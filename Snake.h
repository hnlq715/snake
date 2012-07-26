#ifndef _snake
#define _snake
#include "LivingArea.h"
#include "SnakeNode.h"
#include "dlinkedList.h"
#include "node.h"
using namespace std;

#define SHAPE_SNAKE '*'
#define MAXLEVEL    12
enum TDirection{
  DIR_UP,
  DIR_DOWN,
  DIR_LEFT,
  DIR_RIGHT
};

class LivingArea;
class Snake
{
  public:
        friend class LivingArea;
        Snake();
        void receivingNavi(int key);
        void lifeProbing();
        void move();
        bool getIsAlive();
        void draw(WINDOW *win);
        void eraseFootPrint(WINDOW *win);
  private:
        enum TDirection dir;
        List<SnakeNode> list;
        LivingArea area;
        int speedLevel; //TODO
        bool isAlive;
        int footprinty,footprintx;
        
        bool isSpiralDead();
        bool isClapseArea();
        void selfGeneration();
        void bodyReshape();
};

#endif

