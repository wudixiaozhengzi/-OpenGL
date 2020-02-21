#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "game.h"
#include "gameLib.h"
extern int X,Y;
int main()
{
    char key;           //接收到的用户的按键
    SetTitle("笑傲江湖之精忠报国");
    SetColor(10,0);
    SetPostion(0,0);
    ShowWelcome();
    ShowInformation();
    ShowMainMenu();
    ShowProp();
    ShowPlayer(0);

    while(1)
    {
        key = getch();
        if(key=='1'||key=='2'||key=='3'||key=='4'||key=='5')
        {
            printf("1-5之间的游戏菜单");
        }else if(key==38)//(VK_UP)用户按了上键
        {
            Y--;
        }else if(key==39)//右
        {
            X++;
        }else if(key==40)//下
        {
            Y++;
        }else if(key==37)//左
        {
            X--;
        }
        if(X>7) X=0;
        if(X<0) X=7;
        if(Y>7) Y=0;
        if(Y<0) Y=7;
        ShowMap();
    }
    return 0;
}
