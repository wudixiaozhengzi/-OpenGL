#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "game.h"
#include "gameLib.h"
extern int X,Y;
int main()
{
    char key;           //���յ����û��İ���
    SetTitle("Ц������֮���ұ���");
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
            printf("1-5֮�����Ϸ�˵�");
        }else if(key==38)//(VK_UP)�û������ϼ�
        {
            Y--;
        }else if(key==39)//��
        {
            X++;
        }else if(key==40)//��
        {
            Y++;
        }else if(key==37)//��
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
