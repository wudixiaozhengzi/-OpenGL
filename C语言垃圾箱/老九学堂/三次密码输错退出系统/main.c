#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0;     //循环变量
    int password;//密码

    while(i < 3)
    {
        printf("请输入密码：");
    scanf("%d",&password);
        if(123456 != password)
        {
            printf("error,当前输入第%d次密码\n",i+1);
        }
        //第三次输入错误就会强制退出系统
        if(i==2)
        {
            printf("密码错误三次，强制退出系统\n");
            exit(0);//告诉操作系统，程序正常退出
        }
        i++;

    }











    /*printf("Hello world!\n");
    return 0;*/
}
