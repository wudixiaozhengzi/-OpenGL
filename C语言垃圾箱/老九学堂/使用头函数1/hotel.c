//对应hotel.h的实现文件
#include <stdio.h>
//包含自定义头文件时，使用双引号
#include "hotel.h"

char HOTELNAMES[4][50] = {"喜来登","希尔顿","洲际","城市便捷"};
int days;

int menu(void)
{
    int choice;//用户的选择
    int result;//用户输入后的结果判断 0 表示非法，1 表示真
    int i;
    printf("请选择入住的酒店：\n");
    for(i = 0; i < 4; i++)
    {
        printf("%d、%s\n",i+1,HOTELNAMES[i]);
    }
    printf("5、退出函数\n");
    printf("请输入你的选择：");
    //当用户输入的值不合法时，要求重新输入
    while((result=scanf("%d",&choice)) != 1 || choice < 1 ||choice > 5)
    {
        if(result != 1) //如果用户输入的不是数字类型
        {
            scanf("%*s");//用来处理非整数的输入，*表示输入项在读入后不赋值给对应的变量
            fflush(stdin);//清空缓冲区，
        }
        printf("请输入1-5之间的整数：");
        scanf("%d",&choice);
    }
    //用户的选择不能是非数字
    //用户必须输入1-4之间
    return choice;
}

//返回用户预订的天数
int getNights(void)
{

    printf("请输入预订天数：");
    while(scanf("%d",&days) != 1)
    {
        scanf("%*s");
        printf("请输入预订天数：");
    }

    return days;
}

void showPrice(int days,double price)
{
    //总价格=累加前一天的95%
    double total = 0;
    int i;
    for(i = 0; i < days; i++)
    {
        total += price;
        price = price * DISCOUNT;

    }
    printf("入住%d天，共花费：%.2lf元",days,total);
}




