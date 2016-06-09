#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstdlib>
#include <cstdio>
#include<conio.h>
#include <ctime>
using namespace std;
int x=3,y=3;
char mat[50][50];
int score=0;
int insertRandomPrizes(){
    int prizex=rand()%48+2;
    int prizey=rand()%19+2;
    mat[prizey][prizex]='*';
}
char colors[]="ABCDEFGHIJ";
void changeCollor(){
    char cs[]="color  ";
    cs[6]=colors[score%5];
    system(cs);
}
void changeCollor2(){
    char cs[]="color  ";
    cs[6]=colors[rand()%5];
    system(cs);
}
void printScreen(){
    system("cls");
    for(int i=0;i<21;i++){
        for(int j=0;j<50;j++){
            if(x==j&&y==i){
                if(mat[i][j]=='*'){

                    changeCollor();
                    score++;
                    mat[i][j]='0';
                }
                cout<<(char)31;
            }
            else
                if(mat[i][j]=='0')
                cout<<' ';
            else{
                if(mat[i][j]=='*')
                    cout<<'*';

                else cout<<(char)219;
            }
        }
        cout<<endl;
    }
    cout<<"Score: "<<score<<" stars\n";
}
void readMap(){
    ifstream f("input.in");
    for(int i=0;i<50;i++){
        f.getline(mat[i],51);

    }
}
void moveUp(){
    if(mat[y-1][x]!='1')
        y--;
}
void moveDown(){
    if(mat[y+1][x]!='1')
        y++;
}
void moveLeft(){
    if(mat[y][x-1]!='1')
        x--;
}
void moveRight(){
    if(mat[y][x+1]!='1')
        x++;
}
int main()
{srand(time(NULL));
    char command;
    readMap();
    for(int i=0;i<14;i++)
        insertRandomPrizes();
    int win=1;
    while(win){
        if(score==13)
            win=0;
        printScreen();
        switch(getch()){
            case 65:
                moveUp();
                break;
            case 66:
                moveDown();
                break;
            case 67:
                moveRight();
                break;
            case 68:
                moveLeft();
                break;
            case 'w':
                moveUp();
                break;
            case 's':
                moveDown();
                break;
            case 'd':
                moveRight();
                break;
            case 'a':
                moveLeft();
                break;
            case '0':
                cout<<"Ce las esti";
                return 0;

        }

    }while(1){
        changeCollor2();
        cout<<"*************************\n";
        cout<<"**********WINNER*********\n";
        cout<<"*************************\n";

        for(int i=0;i<100000000;i++);
        system("cls");
    }
    return 0;
}
