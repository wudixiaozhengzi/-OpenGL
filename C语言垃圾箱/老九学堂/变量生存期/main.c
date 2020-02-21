#include <stdio.h>
#include <stdlib.h>

//1.计算某个函数被调用了多少次

//全局变量的作用域是本文件
int whileCount=0;


int main()
{
    int value;      //自动变量
    register int i;//将循环变量设置为寄存器存储模式
    printf("请输入循环执行的次数（按0 退出）；");
    //用户输入的value为整型数字且大于0时，进入循环
    while(scanf("%d",&value) == 1 && value > 0)//实现一个循环录入的效果
    {
        whileCount++;
        for(i = value; i >= 0; i--)
        {
            counter(i);//每次循环调用counter函数
        }
        printf("请输入循环执行的次数（按0 退出）；");
    }

    return 0;
}
