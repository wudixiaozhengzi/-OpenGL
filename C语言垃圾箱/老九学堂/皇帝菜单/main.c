#include <stdio.h>
#include <stdlib.h>
//while循环和do-while循环的区别
//执行顺序不同
//初始情况不满足循环条件时  1.while循环一次都不会执行    2.do-while循环不管任何情况都至少执行一次


int main()
{
    int choice;                 //用户的选择
    //打印游戏菜单
    while(1)
    {
    printf("性格测试：\n");
    printf("如果您是一位君王，对于身旁的伴侣您希望：\n");
    printf("1.只有一位真爱的妻子\n");
    printf("2.可以两位以上的爱人\n");
    printf("3.拥有三千佳丽\n");
    do{//如果输入错误。将会一直循环输入
        printf("请选择：");
        scanf("%d",&choice);
        if(choice <= 0||choice >3)
        {
            printf("只要输入1-3之间的数字！请重新输入：\n");
        }
    }while(choice <= 0||choice >3);
    //如果执行到了这里，证明用户的输入时正确的，在1-3之间
    switch(choice)
    {
    case 1:
        printf("您选择了生命中的唯一，然而郑半仙已经看穿了一切！\n");
        break;
    case 2:
        printf("你个花心大萝卜！\n");
        break;
    case 3:
        printf("金哥金哥，10元/包，江浙泸包邮！\n");
        break;
    }
    }
    return 0;
}
