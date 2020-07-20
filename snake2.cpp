/**********************************************************************;
* Project           : Snake2
*
* Program name      : snake2.cpp
*
* Author            : sanaro1999@gmail.com
*
* Date created      : 31/05/2018
*
* Purpose           : Nope.
*
**********************************************************************/

#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<cstdlib>
#include<time.h>
#include<unistd.h>

using namespace std;

COORD coord={0,0};

void gotoxy(int x,int y)
{
       coord.X=x;
       coord.Y=y;
       SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void box()
{
       gotoxy(0,0);
       cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";

       for(int i=0;i<21;i++)
       {
              gotoxy(0,i);
              cout<<"X";
       }

       for(int i=0;i<21;i++)
       {
              gotoxy(70,i);
              cout<<"X";
       }
       gotoxy(0,20);
       cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
}

void poster()
{
       gotoxy(0,22);
       cout<<"     _______..__   __.      ___       __  ___  _______ ___   "<<endl;
       cout<<"    /       ||  \\ |  |     /   \\     |  |/  / |   ____|__ \\  "<<endl;
       cout<<"   |   (----`|   \\|  |    /  ^  \\    |  '  /  |  |__     ) | "<<endl;
       cout<<"    \\   \\    |  . `  |   /  /_\\  \\   |    <   |   __|   / /  \t\t- Sanaro99"<<endl;
       cout<<".----)   |   |  |\\   |  /  _____  \\  |  .  \\  |  |____ / /_  "<<endl;
       cout<<"|_______/    |__| \\__| /__/     \\__\\ |__|\\__\\ |_______|____| ";

}

unsigned long int gamespeed(int length)
{
       unsigned long int delay=100000;

       if(length<=10)
              return delay;
       else
       if(length<=20)
              return 2*delay/3;
       else
       if(length<=30)
              return delay/3;
       else
       if(length<=40)
              return delay/6;
       else
              return delay/10;
}

void gameover(int length)
{
       char arb;
       gotoxy(0,150);
       cout<<"Press any key to view your final length";
       arb=getch();
       system("cls");
       cout<<"Final length : "<<length<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
       exit(0);
}

int main()
{
       unsigned long int delay;
       int rand();
       int food[2];
       int length=3,i[200]={20},j[200]={10},p=0,k[200]={0},flag=0;
       int nextpos[200][2];
       int inc;
       char dir='d';

       box();
       poster();

       gotoxy(i[0],j[0]);
       for(p=0;p<length;p++)
       {
              i[p]=i[0]-p;
              j[p]=10;
              gotoxy(i[p],j[p]);
              cout<<"O";
              nextpos[(p+1)][0]=i[p];
              nextpos[(p+1)][1]=j[p];
       }

       do{
              srand(time(NULL));
              food[0]=rand()%68+1;
              food[1]=rand()%18+1;
              gotoxy(food[0],food[1]);
              cout<<"#";

              do
              {
                     inc=length;
                     fflush(stdin);
                     gotoxy(0,0);
                     if(kbhit())
                     dir=getch();
                     gotoxy(food[0],food[1]);
                     cout<<"#";

                     gotoxy(i[length-1],j[length-1]);
                     cout<<" ";

                     switch(dir)
                     {
                            case 'd': i[0]++;
                                          break;

                            case 'a': i[0]--;
                                          break;

                            case 's': j[0]++;
                                          break;

                            case 'w': j[0]--;
                                          break;
                     }

                     if(i[0]==food[0] && j[0]==food[1])
                            length++;

                     for(p=0;p<length;p++)
                     {
                            if(p!=0)
                            {
                                   i[p]=nextpos[p][0];
                                   j[p]=nextpos[p][1];
                            }
                            gotoxy(i[p],j[p]);
                            cout<<"O";
                     }

                     for(p=0;p<length;p++)
                     {
                            nextpos[p+1][0]=i[p];
                            nextpos[p+1][1]=j[p];
                     }

                     gotoxy(80,10);
                     cout<<"Length : "<<length;

                     for(p=1;p<length;p++)
                     {
                            if(i[0]==i[p] && j[0]==j[p])
                            gameover(length);
                     }

                     delay=gamespeed(length);
                     usleep(delay);

                     if(i[0]==0 || i[0]==70 || j[0]==0 || j[0]==20)
                           gameover(length);

              }while(inc==length);
       }while(flag==0);
}


