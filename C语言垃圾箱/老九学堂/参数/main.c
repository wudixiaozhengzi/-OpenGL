#include <stdio.h>
#include <stdlib.h>
//实现pow函数
//求第一个参数的n次幂

double  pow1(double,int);


int main()
{
    //实际参数 - 调用
    printf("%d的%d次幂等于；%.2lf\n",5,2,pow1(5,2));
    printf("Hello world!\n");
    return 0;
}
//double num1,double num2------形式参数
double pow1(double num1,int num2)
{
    double result = 1;
    int i;

    for(i=0; i<num2; i++)
    {
        result *= num1;
    }
    return result;
}



















