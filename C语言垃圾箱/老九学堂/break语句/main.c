#include <stdio.h>
#include <stdlib.h>

//break语句的作用：跳出循环，执行循环语句后的语句




int main()
{
    //循环输入玩家的年龄，如果年龄为负则停止输入，提示输入错误
    int age;
    //for(;;)
    for(;;)
    {
        printf("请输入玩家年龄：");
        scanf("%d",&age);
        if(age<0)
        {
            printf("年龄不能为负数！程序强制退出！\n");
            break;
        }
    }
    return 0;
}










