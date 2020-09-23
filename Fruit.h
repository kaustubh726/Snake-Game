#ifndef FRUIT_H
#define FRUIT_H
#include<stdlib.h>
#include<time.h>
#define HEIGHT 30
#define WIDTH 30
class Fruit{
    int X;
    int Y;

public:
    Fruit(){
        X = 20;
        Y = 20;
    }

    void changePosition(){
        srand(time(0));
        Y = 1 + (rand() % (WIDTH-1));
        srand(time(0));
        X = 1 + (rand() % (HEIGHT-1));
    }

    friend class Game;
};
#endif