#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*二维数组实例
    学生多门学科成绩
    玩家背包数据
    游戏角色行走动画

    */
    //使用二维数组表示学生的成绩表
    //四个学生的3门成绩 4行  3列
    int i,j;
    double scores[4][3]={
        {98,75,66},
        {56,78,51},
        {95,23,75},
        {45,48,23}
    };
    //使用循环打印每个数组元素
    for(i = 0; i < 4; i++)//外层循环控制有几个学生
    {
        for(j = 0; j < 3; j++)
        {
            printf("%-8.2lf",scores[i][j]); //-8.2左对齐
        }
        printf("\n");
    }



    printf("Hello world!\n");
    return 0;
}
