#include "hero.h"
#include <stdio.h>


Hero heros[100] ={
{"影流之借助",'m',"刺客",579,0,"温度",{2018,7,12}},
{"琴瑟仙女",'f',"法师",69,0,"温度",{2018,7,12}},
{"影流之借助",'m',"刺客",59,0," 温度",{2018,7,12}}
};
int count=3;
void show()
{
    //如何知道结构数组的大小
    //int len=sizeof(heros)/sizeof(Hero);
    //数组元素使用指针时，动态赋值需要首先分配内存
    //printf("请输入名称：");
    //heros[0].name = (char *)malloc(50);     //char name[50];
    //scanf("%s",heros[0].name);
    printf("现有英雄个数：%d\n",count) ;
    int i;
    for(i = 0; i<count;i++)
    {
        printf("%s\t%d\t%d-%d-%d\n",(heros+i)->name,heros[i].life,heros[i].pubTime.year,heros[i].pubTime.month,heros[i].pubTime.day);
    }
}

void Input()
{
   //首先录入内容
   //第一个录入完毕之后，询问是否继续录入
   char answer = 'y';
   int c;
   do{
     if(count == 100)
     {
         printf("英雄栏位已满");
         break;
     }
     printf("当前录入第%d位英雄的信息：\n",count+1);
     printf("hero name:");
     heros[count].name = (char *)malloc(50);
     scanf("%s",heros[count].name);

     printf("hero sex(m/f):");
     fflush(stdin);

     heros[count].sex=getchar();



     printf("hero job:");
     heros[count].job = (char *)malloc(50);
     scanf("%s",heros[count].job);

     heros[count].speed=6.7;
     heros[count].life=1000;

     heros[count].ability="上天入地";
     heros[count].pubTime.year=2018;
     heros[count].pubTime.month=1;
     heros[count].pubTime.day=2;

     count++;               //录入完毕后，英雄总数++
     printf("是否要继续录入y/n");
     answer = getch();      //用户按下键后就立即触发下面语句，不会再让用户敲回车了

   }while(answer=='y'||answer=='Y');

}

void avglife()
{
    int i,lifeofsum;
    double avgL;
    lifeofsum=0;
    avgL=0.0;
    for(i=0;i<count;i++)
    {
       lifeofsum += heros[i].life;
         avgL = (lifeofsum*1.0)/count;
    }
    printf("英雄的平均生命值：%lf\n",avgL);
}










