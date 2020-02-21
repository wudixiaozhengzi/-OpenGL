#include <stdio.h>
#include <stdlib.h>
/*
需要一个变量，用来存放每次相加值
1.循环变量的初值
int = 1
2.循环变量的判断
while（i<101）
{
3.循环变量的更新
i++
}

*/
int main()
{
    int i=1;
    int add=0;    //存放每次相加值
    while(i<=100)
    {
        add=add+i;
  i++;
    }

    printf("1-100的和为：%d\n",add);
    return 0;
}










