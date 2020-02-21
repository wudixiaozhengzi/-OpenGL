#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*删除的逻辑
    12  34  23  67  9
    1.  查找要删除数字的下标  2
    12  34  67  9   9
    2.  从下标开始，后面的一个覆盖前面的数字
    3.数组总长度-1
    12  34  67  9
    */
    int count = 5;        //表示数组元素的个数
    double  powers[]={42322,45771,40907,41234,40767};
    double deletepower;    //用户要删除的战力值
    int deleteIndex = -1;    //要删除战力值的下标，给一个不可能的值，方便判断
    int i;              //循环变量
    double InsertPower; //新插入的战力值
    printf("请输入要删除的战力值");
    scanf("%lf",&deletepower);
    for(i = 0; i < count; i++)
    {
        if(deletepower == powers[i])
        {
            //记录下当前的下标
            deleteIndex = i;
            break;
        }
    }
    //根据判断（是否找到），执行后续操作
    if(-1 == deleteIndex)
    {
        printf("很遗憾没有找到");
    }
    else
    {
        //从下标开始，后面一个覆盖前面的一个数
        for(i = deleteIndex; i < count; i++)
        {
            powers[i] = powers[i+1];
        }
        //删除完，记得数组总长度-1
        count--;

    }
    printf("删除后的结果为：\n");
    for(i=0;i<count;i++)
    {
        printf("%.2lf\t",powers[i]);
    }
    //删除后进行插入
    printf("\n请输入新战力值：");
    scanf("%lf",&InsertPower);
    powers[count]=InsertPower;//插入到最后
    count++;
     printf("插入后的结果为：\n");
    for(i=0;i<count;i++)
    {
        printf("%.2lf\t",powers[i]);
    }
    //如果想让战力值有序，用冒泡法

    printf("Hello world!\n");
    return 0;
}










