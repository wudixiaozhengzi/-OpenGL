#include <stdio.h>
#include <stdlib.h>
/*
for(表达式1;表达式2;表达式3)
    表达式1，通常为循环变量赋初值，可省略
    表达式2，循环条件，是否继续执行循环，可省略
    表达式3，更新循环变量的值，可省略
    分号不能省略
{
语句
}
const常量     不能被修改的量


int main()
{
    const int num = 100;
    num++;
    return 0;
}

int main()
{
    int i;
    double salary;      //工资
    double total_salary = 0;    //6个月的总工资
    double avg_salary;      //6个月平均工资
    for(i=0;i<6;i++)
    {
        printf("请输入第%d个月的工资：",i+1);
        scanf("%lf",&salary);
        //累加
        total_salary += salary;
    }
    avg_salary = total_salary / 6;
    printf("总工资为%lf\n平均工资为%lf",total_salary,avg_salary);
    return 0;
}
*/

//建议加法表
int main()
{
    int num;
    int i;
    printf("请输入一个数字：");
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        printf("%d + %d = %d",i,(num-i),num);
        if(i%2==0)
        {
            printf("\t");
        }
        else
        {
            printf("\n");
        }
    }
    return 0;
}










