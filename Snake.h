#ifndef SNAKE_H
#define SNAKE_H

enum Direction{PAUSE = 0, UP, DOWN, RIGHT, LEFT, EXIT};

class Snake{
    int headX;
    int headY;
    int nTail;
    int tailX[100];
    int tailY[100];
    Direction Dir;

public:
    Snake(){
        headX = 3;
        headY = 3;
        nTail = 0;
        Dir = PAUSE;
    }

    void changeDirection(char x){
        switch(x){
            case 'a': 
                Dir = LEFT;
                break;
            case 'd':
                Dir = RIGHT;
                break;
            case 'w':
                Dir = UP;
                break;
            case 's':
                Dir = DOWN;
                break;
            case 'f':
                Dir = PAUSE;
                break;
            case 'x':
                Dir = EXIT;
                break;
            default:
                break;
        }
    }
    friend class Game;
};

#endif