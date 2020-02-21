#include <stdio.h>
#include <stdlib.h>
#define N 5    //宏定义
int main()
{
    //动态录入
    double score[5];
    int i;
    for(i = 0;i<N;i++)
    {
        printf("请输入第%d为同学的成绩：",i+1);
        scanf("%lf",&score[i]);
    }
    for(i=0 ;i<N;i++)
    {
        printf("请输入第%d为同学的成绩是%.2lf\n",i+1,score[i]);
    }
    return 0;
}
