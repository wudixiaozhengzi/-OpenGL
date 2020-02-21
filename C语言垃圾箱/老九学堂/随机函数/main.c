#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<windows.h>//Sleep
int main()
{
 /*   //使用时间做种子，产生不一样的随机数字随机函数
    srand(time(NULL));
    printf("随机数字：%d\n",rand());
    //rand的范围是0~32767
    rand() % 10,表示模取0-9
    rand() % 16,表示模取0-15
    如果要取5-15
    rand() % 11 + 5     上下限都加5
    a为下限，b为上限。
    rand() % (b - a + 1) + a
使用循环模拟实现玩家对战
双方初始HP为100
每次伤害共计5-15
    HP最先到零或以下的被KO*/
    int hp1 = 100,hp2 = 100;    //1p和2p的初始血量
    int att1,att2;              //1p和2p的每次攻击
    int i = 0;
    while(hp1 >=0 && hp2 >=0)//当两个玩家都活着的时候，继续进行对战。
    {
        //默认1p首先攻击
        att1 = rand() % 11 + 5;
        att2 = rand() % 11 + 5;

        //1p攻击，2p掉血
        hp2 -= att1;
        //2p攻击，1p掉血
        hp1 -= att2;

        printf("******************************\n");
        printf("第%d轮：\n",i+1);
        printf("玩家1攻击力：%d，玩家2剩余血量%d\n",att1,hp2);
        printf("玩家2攻击力：%d，玩家1剩余血量%d \n",att2,hp1);
        i++;
        Sleep(500);//休眠500毫秒
    }
    printf("\nKO!~游戏结束，玩家1的血量：%d\t玩家2的血量：%d\n",hp1,hp2);


}
