#ifndef GAME_H
#define GAME_H
#include<iostream>
#include"Fruit.h"
#include"Snake.h"
#include<conio.h>
#define HEIGHT 30
#define WIDTH 30

using namespace std;

class Game{
    int score;
    Snake s;
    Fruit F;
    bool isOver;
public:
    Game(){
        isOver = false;
        score = 0;
    }

    void Draw(){
        system("cls");
        cout<<"\n\n"<<endl;
        for(int i = 0; i<=HEIGHT; i++){
            cout<<"\t\t";
            for(int j = 0; j<=WIDTH; j++){
                if(i == 15 && j == 10 && Over()){
                    cout<<"Game Over !         #";
                }

                if(i == 0 || j == 0)
                    cout<<"#";

                else if(i == s.headX && j == s.headY){
                    cout<<"O";
                }

                else if(i == HEIGHT || j == WIDTH){
                    if(j == WIDTH && Over() && i == 15)
                        cout<<" ";
                    else{
                        cout<<"#";
                    }
                }
                
                else if(i == F.X && j == F.Y && !Over())
                    cout<<"X";

                else{
                    bool print = false;
                    for (int k = 0; k < s.nTail; k++)
                    {
                        if (s.tailX[k] == i && s.tailY[k] == j)
                        {
                            cout << "o";
                            print = true;
                        }
                    }
                    if (!print)
                        cout << " ";
                }
            }
            cout<<endl;
        }
        cout<<"---------------------------------------------------------------------------------\n"<<endl;
        cout<<"\t\tScore : "<<score<<endl;
        //cout<<F.X<<"  "<<F.Y<<endl;
    }

    void Input(){
        if(_kbhit()){
            s.changeDirection(getch());
        }
    }

    void Logic(){
        int prevX = s.tailX[0];
        int prevY = s.tailY[0];
        int prev2X, prev2Y;
        s.tailX[0] = s.headX;
        s.tailY[0] = s.headY;
        for (int i = 1; i < s.nTail; i++)
        {
            prev2X = s.tailX[i];
            prev2Y = s.tailY[i];
            s.tailX[i] = prevX;
            s.tailY[i] = prevY;
            prevX = prev2X;
            prevY = prev2Y;
        }
        switch (s.Dir)
        {
            case LEFT:
                s.headY--;
                break;
            case RIGHT:
                s.headY++;
                break;
            case UP:
                s.headX--;
                break;
            case DOWN:
                s.headX++;
                break;
            case EXIT:
                isOver = true;
                break;
            default:
                break;
        }
        if(s.headX == F.X && s.headY == F.Y){
            score += 10;
            F.changePosition();
            s.nTail++;
        }

        if(s.headX == WIDTH + 1 || s.headY == HEIGHT + 1 || s.headX == 0 || s.headY == 0){
            isOver = true;
        }

        for (int i = 0; i < s.nTail; i++)
            if (s.tailX[i] == s.headX && s.tailY[i] == s.headY)
                isOver = true;
    }

    bool Over(){
        return isOver;
    }

    int showScrore(){
        return score;
    }
};

#endif
