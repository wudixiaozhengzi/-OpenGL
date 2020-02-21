#include <stdio.h>
#include <stdlib.h>

int main()
/*  double num = 6;  小类型转大类型  为自动类型转换
    int num1=num；   大类型转为小类型，损失精度  为强制类型转换


{
    int num=10;
    num++;//等价于num=num+1
    num += 5;//等价于num = num + 5
    printf("%d\n",num);
    return 0;
}

{
    int num = 5,num1 = 10;
    int result = num++;
    //相当于先把num赋给result，然后num再自加
    int result1 = --num1;
    //相当于先把num1自减，再赋给result1
    printf("result = %d\nnum=%d\n",result,num);
    printf("result1 = %d\nnum1=%d\n",result1,num1);
    return 0;
}

{
    //sizeof
    printf("整型所占的空间是%d字符\n",sizeof(int));
}
*/

{
    //杀鸡刀switch结构的用法
    //一般树立数轴中的某几个点的情况
    //想知道某个月有多少天
    int month;
    printf("请输入月份，我来判断天数：");
    scanf("%d",&month);
    switch(month)
    {
    case 1:
        printf("31\n");
        break;
    case 2:
        printf("28\n");
        break;
    case 3:
        printf("31\n");
        break;
    default:
        printf("暂时无法判断");
        break；
    }
}
















