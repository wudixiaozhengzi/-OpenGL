#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "GameLib.h"
#include "Game.h"

extern char Maps[8][8][10];
extern enum GameStatus CurrGameStatus;
extern Martial martials[20];
extern int X;
extern int Y;
int main()
{
    SetConsoleWindowSize(121, 31);
    int i = 0, j = 0;
    char key;   //�û����µļ�
    SetTitle("Ц������֮���ұ���C���԰� v0.1 :: �����������QQ:614940318");
    SetColor(10, 0);
    SetPosition(MARGIN_X, 0);
    printf("-----------------------------------------------------------------------------\n");
    SetPosition(MARGIN_X, 1);
    printf("|\t\t\t��ӭ������Ц������֮���ұ�����");
    SetPosition(MARGIN_X + 76, 1);
    printf("|");
    SetPosition(MARGIN_X, 2);
    printf("-----------------------------------------------------------------------------\n");
    InitializeGame();
    ShowMap();

    while(1){
        //Clear(20, 2);
        SetPosition(MARGIN_X, 19);
        printf("-----------------------------------------------------------------------------\n");
        SetPosition(MARGIN_X, 20);
        printf("��Ϸ�˵�\n");
        SetPosition(MARGIN_X, 21);
        printf("1����������\n");
        SetPosition(MARGIN_X, 22);
        printf("2��̽��(���)\n");
        SetPosition(MARGIN_X, 23);
        printf("3�����ܲ�\n");
        SetPosition(MARGIN_X, 24);
        printf("4������װ��\n");
        SetPosition(MARGIN_X, 25);
        printf("5����Ŀ����(�����)\n");
        SetPosition(MARGIN_X, 26);
        printf("6������һ��(�����)\n");
        SetPosition(MARGIN_X, 27);
        printf("7���˳���Ϸ");
        SetPosition(MARGIN_X, 28);
        printf("������ѡ����ķ����ƶ���");
        key = GetKey();//�ȴ��û�����
        if(key == 38){//��
            X--;
        }else if(key == 39){//��
            Y++;
        }else if(key == 40){//��
            X++;
        }else if(key == 37){//��
            Y--;
        }else if(key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6'){
            Process(key);
            continue;
        }
        else if(key == '7'){
            exit(0);
        }
        else
        {
            continue;
        }

            //getch();
        if(X > 7) X = 0;
        if(X < 0) X = 7;
        if(Y > 7) Y = 0;
        if(Y < 0) Y = 7;
        ShowMap();

    }
    SetColor(15, 0);
    //InitializeGame();
    //ShowPlayer();
    return 0;
}

