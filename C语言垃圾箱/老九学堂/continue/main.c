#include <stdio.h>
#include <stdlib.h>

int main()
{
    int age;
    int i;
    int count=0;
    for(i=0;i<5;i++);
    {
        printf("请输入玩家年龄：");
        scanf("%d",&age);
        if(age>=0)
        {
            continue;
        }
            count++;

    }
    printf("输入错误次数：%d\n",count);
    return 0;
}











