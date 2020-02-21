#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 1234;

    while(num > 0);
    {
        printf("%d\n",num % 10);
        num /= 10;//取出个位数后，立即去掉个位数
    }
    return 0;
}

exit(0);//退出系统。0的是正常退出。非0位非正常退出


/*//讲4位数的没一位数都取出来
    printf("个位：%d\n",num%10);
    printf("十位：%d\n",num / 10 % 10);
    printf("百位：%d\n",num / 100 % 10);
    printf("千位：%d\n",num / 1000 %10);
    //规律：除10在模10
    int temp;            //临时变量*/
