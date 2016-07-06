#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

#ifdef _WIN32
#include <windows.h>
#include<conio.h>
#define DIV 1048576 
#define WIDTH 7
#else
#include <termios.h>
static struct termios old, newt;
void initTermios(int echo) 
{
  tcgetattr(0, &old);
  newt = old; 
  newt.c_lflag &= ~ICANON; 
  newt.c_lflag &= echo ? ECHO : ~ECHO; 
  tcsetattr(0, TCSANOW, &newt); 
}
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}
char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}
char getch(void) 
{
  return getch_(0);
}

char getche(void) 
{
  return getch_(1);
}
#endif

using namespace std;

int x=3,y=3;
char mat[50][50];
int score=0;

void insertRandomPrizes(){
    int prizex=rand()%48+2;
    int prizey=rand()%19+2;
    if(mat[prizey][prizex]=='0')
    	mat[prizey][prizex]='*';
    else insertRandomPrizes();
}
char colors[]="ABCDEFGHIJ";
void changeCollor(){
    char colorCommand[]="color  ";
    colorCommand[6]=colors[score%5];
    system(colorCommand);
}
void changeCollorPostEnding(){
    char colorCommand[]="color  ";
    colorCommand[6]=colors[rand()%5];
    system(colorCommand);
}
void clear(){
	#ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}
void printScreen(){
	clear();
    for(int i=0;i<20;i++){
        for(int j=0;j<50;j++){
            if(x==j&&y==i){
                if(mat[i][j]=='*'){
                	#ifdef _WIN32
                    changeCollor();
                    #endif
                    score++;
                    mat[i][j]='0';
                }
                cout<<'v';
            }
            else
                if(mat[i][j]=='0')
                cout<<' ';
            else{
                if(mat[i][j]=='*')
                    cout<<'*';

                else cout<<'@';
            }
        }
        cout<<endl;
    }
    cout<<"Score: "<<score<<" stars\n";
}
void readMap(){
    ifstream mapInput("input.in");
    for(int i=0;i<50;i++){
        for(int j=0;j<50;j++)
            mapInput>>mat[i][j];
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

int main(){
    //for random goal generation
    srand(time(NULL));
    readMap();
    const int goal=14;
    for(int i=0;i<goal;i++)
        insertRandomPrizes();
    
    //Main game loop for one game
    bool keepPlaying=true;
    while(keepPlaying){
        if(score>=goal)
            keepPlaying=false;
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
                cout<<":(";
                return 0;

        }

   }  
         cout<<"*************************\n";
        cout<<"**********WINNER*********\n";
        cout<<"*************************\n";

    return 0;
}
