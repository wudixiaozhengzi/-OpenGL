#include <stdio.h>


int main()
{
    int nums[]={8,4,2,1,23,344,12};
    int i;                              //循环变量
    int sum;                            //求和
    double avg;                         //求平均值
    int searchnum;                      //要查找的数字
    printf("输出数组元素：\n");
    for(i = 0; i < 7; i++)
    {
        printf("%d\t",nums[i]);
    }
    printf("\n**********************\n");
    //求和求平均值
    for(i=0;i<7;i++)
    {
        sum += nums[i];//经典的累加
    }
    avg=sum/7.0;            //除7.0是为了变成double类型
    printf("平均数为%.2lf",avg);
    //查找数字
    printf("请输入要查找的数字：");
    scanf("%d",&searchnum);
    //穷举法
    for(i=0;i<7;i++)
    {
        //一个个元素进行对比
        if(searchnum==nums[i])
        {
            printf("找到了\n");
            //找到以后跳出循环
            break;
        }

    }
    //结束循环后，我们如何判断是否找到了呢？
    //通过观察，循环正常退出时，i的值应该为7
    if(i==7)
    {
        printf("茫茫人海，没有找到合适的");
    }
}







