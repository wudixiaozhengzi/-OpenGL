#include <stdio.h>
#include <stdlib.h>

//变量只存在于定义他呢吧的语句块中
//变量在一个快内声明是创建，在这个块结束时销毁-自动变量
//变量存在的时间成为变量生存期
//全局变量默认值为0

void changeNum()
{
    //局部变量
    int num1 = 5,num2 = 8;
    num1 = 55;
    num2 = 288;
}



int main()
{
     int num1 = 5,num2 = 8;
     changeNum();
     printf("num1=%d\tnum2 = %d\n",num1,num2);
     /*
     int count1 = 0;
     do
     {
         int count2 = 0;
         count2++;
         printf("count1 = %d\tcount2 = %d\n",count1,count2);
     }while(++count1 < 5);*/
    return 0;
}
