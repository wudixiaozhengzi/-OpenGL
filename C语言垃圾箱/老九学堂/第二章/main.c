#include <stdio.h>
#include <stdlib.h>
/*
1.变量名的首字母或下划线
2.变量名的其他字母包含下划线、数字的 字母
3.不能使用关键字

       8 bit（比特）=1 byte(字节)

int main()
{
    //使用变量标示游戏角色的攻击力
    //1.攻击力是什么类型的数据
    //2.用什么名称表示攻击力
    int gongjiPower;//攻击力

    return 0;
}

int main()
{
    int num1=10
    ,num2=8;
    printf("%d口心思\n%d目共赏",num1,num2);
}

int main()
{
    float height=150.0f,width=25.0f;
    float s=height*width;
    printf("长方形的面积为：%.2f\n",s);//.2只保留两位小数
    return 0;
}

void main()
{
    double radius=2.5,area=30141592653*radius*radius;
    printf("圆的半径为%lf，面积为%lf\n",radius,area);//%lf代表double
}

int main()
{
    char ch='A';//字符
    printf("ascll：%d\t%c\n",ch);
    return 0;
}
*/
int main()
{
    //需要定义几个变量？武器实际最大伤害，玩家的力量，武器最大伤害
    //对应什么数据类型？    double         int          double
    double factshanghai;//武器实际最大伤害
    int strength;//玩家力量
    double maxshanghai=256;//武器最大伤害
    printf("请玩家输入当前角色的力量：");
    //&取地址
    scanf("%d",&strength);
    //套用公式
    factshanghai = maxshanghai * (strength + 100) / 100;
    printf("武器实际伤害：%.2lf",factshanghai);
    return 0;
}




