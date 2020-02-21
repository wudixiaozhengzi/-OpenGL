#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//函数原型
void calcCircle();
void calcRectangle();
int calcSun();         //求一到一百的偶数和
/*
    计算圆的面积（函数实现）
*/
void calcCircle()
{
    double radius,s;
    printf("请输入圆半径：");
    scanf("%lf",&radius);
    s = 3.14 * pow(radius,2);
    printf("圆的面积为%lf\n",s);
}

void calcRectangle()
{
    double width,height,s;      //长宽高
    printf("请输入宽和高：");
    scanf("%lf%lf",&width,&height);
    if(width <= 0 || height <=0)
    {
        printf("输入的数值不能为负值");
        return;
    }
    s = width * height;
    printf("矩形的面积为%lf\n",s);
}

int calcSun()
{
    //求一到一百的偶数和
    int sum = 0;
    int i = 1;
    for(i = 1; i <= 100; i++)
    {
        if(i % 2 == 0)
            sum += i;
    }
}


int main()
{
    /*三种图形的面积计算公式如下：
    圆：s = PI*r*r;
    三角形：s = width*height;
    矩形：s = width*height;
    使用函数分别实现三种图形的面积计算，打印计算结果；
    */
    //书写函数的步骤，完成函数三要素
    //误区：不要一开始就去考虑如何完成某个功能

    //需要返回值吗？
    //函数名是什么
    //需要给这个

    calcCircle();       //调用计算圆面积的函数
    calcRectangle();

    //如果函数有返回值，调用时，记得使用对应类型的变量来接收
    int sum = calcSun();
    printf("1-100之间的偶数和为：%d\n",sum);

    printf("Hello world!\n");
    return 0;
}
