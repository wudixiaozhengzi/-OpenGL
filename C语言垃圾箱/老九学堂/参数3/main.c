#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 /*三种图形的面积计算公式如下：
    圆：s = PI*r*r;
    三角形：s = width*height;
    矩形：s = width*height;
    使用函数分别实现三种图形的面积计算，打印计算结果；
    */

//函数原型
double calcCircle(double);      //根据传入的半径，返回圆面积
double calcRectangle(double,double);   //根据传入的长宽，返回矩形的面积

//需要对用户的输入进行非负验证
int validate(double);        //验证输入的double类型数据是否为正数

//让用户输入正确的值
double input();             //函数内直接让用户输入，如果不符合要求就重新录入



double calcCircle(double radius)
{
    double s;

    s = 3.14 * pow(radius,2);

    return s;

}



/*
    计算矩形的面积（函数实现）
*/
double calcRectangle(double width,double height)
{
    double s;      //长宽高

    s = width * height;

    return s;
}





int validate(double num)        //验证输入的double类型数据是否为正数
{
    return num > 0;            //如果num>0，会返回一个非零值，表示真
}





int main()
{
    double radius;      //用户输入的半径
    double width,height;
    double s;           //图形的面积
    int choice;

    printf("1.圆\n");
    printf("2.矩形\n");
    printf("3.三角形\n");
    printf("本系统支持计算三种图形的面积，请选择：\n");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        printf("请输入圆半径，我来计算圆的面积；");
        do{
            scanf("%lf",&radius);
            if(!validate(radius))
            {
            printf("所录入的内容不能为负数，请输入一个正数：");
            }
        }while(!validate(radius));      //当验证不通过的时候，重新录入
        s = calcCircle(radius);         //调用圆的面积方式
        printf("圆的面积为%lf\n",s);
         break;

    case 2:
        printf("请输入宽和高：");
         do{
            scanf("%lf%lf",&width,&height);
            if(!validate(width) || !validate(height))
            {
                printf("所录入的内容不能为负数，请输入两个正数：");
            }
        }while(!validate(width) || !validate(height));      //当验证不通过的时候，重新录入

        s = calcRectangle(width,height);
        printf("矩形的面积为%lf\n",s);

        break;

    case 3:

        break;

    default:

        printf("本系统只支持3中图形，请在1-3之间选择!");
        scanf("%d",&choice);
    }


    return 0;
}









