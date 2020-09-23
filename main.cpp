#include<iostream>
#include<fstream>
#include<windows.h>
#include"Game.h"

using namespace std;

int main(){
    char choice;
    string username;
    system("cls");
    cout<<"\n\tEnter Username : ";
    cin>>username;
    cout<<"\n\tInstructions:\n\t\t1. Use 'A', 'W', 'S', 'D' Keys to move Left, Up, Down and Right\n\t\t2. Press F to Pause and C to Exit \n";
    cout<<"\tEnter any key to continue ..."<<endl;
    if(getch()){
        do{
            Game G;
            while(!G.Over()){
                G.Draw();
                G.Input();
                G.Logic();
                Sleep(50);
            }
            G.Draw();
            int score = G.showScrore();
            ofstream out("GameDB.txt",ios::app);
            out<<username<<"\t"<<score<<endl;
            out.close();
            cout<<"\n\t CONTINUE ?(Y/N) ";
            cin>>choice;
        }while(choice != 'N');
    }

    cout<<"\n\tPress Any Key to exit ...";
    getch();
    return 0;
}
