#include <stdio.h>
#include <stdlib.h>
//ʵ��pow����
//���һ��������n����

double  pow1(double,int);


int main()
{
    //ʵ�ʲ��� - ����
    printf("%d��%d���ݵ��ڣ�%.2lf\n",5,2,pow1(5,2));
    printf("Hello world!\n");
    return 0;
}
//double num1,double num2------��ʽ����
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



















