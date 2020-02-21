#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    /*
     //ceil -   进一法     floor - 去尾法
     //如果是负数规律相反
    printf("%.2lf\n",ceil(-98.1));
    printf("%.2lf\n",floor(-98.9));

     printf("%.2lf\n",sqrt(9));

      printf("%.2lf\n",pow(5,2));

       printf("%.2lf\n",abs(-98));      //求绝对值

    //1.设置随机种子--一般跟时间连用
    srand(NULL);
    //2.取随机数
    int num = rand();
    printf("%d\n",num);

    exit(0);    //0正常退出应用程序     非0表示不正常退出

    printf("无");
    //system("color 4E");
    //system("pause");
    printf("啥");
   // system("cls");      //清屏-
    //system("shutdown /r /t 180");   //180秒后自动关机
    system("shutdown /a");              //取消自动关机

    int *nums;
    int i;
    //为前面的指针动态分配了20个字节的空间
    nums = (int *)malloc(20);       //
    //double *dnums = (double *)malloc(sizeof(double)*5)
    //nums = (int *)malloc(sizeof(double) * 5);
    //数组名就是数组的首地址
    //等于int nums[5];
    //为指针动态分配空间后，指针变成了数组

    for(i = 0; i < 5; i++)
    {
        printf("请输入第%d个元素：",i+1);
        scanf("%d",nums + i);
    }



    printf("数组元素为：\n");
    for(i = 0; i < 5; i++)
    {
        printf("%d\t",*(nums + i));
    }
    free(nums);//释放动态分配的内存
    nums = NULL;*/





    int *nums;
    int i;
    //为前面的指针动态分配了20个字节的空间

    nums = calloc(5,sizeof(int));

    //数组名就是数组的首地址
    //等于int nums[5];
    //为指针动态分配空间后，指针变成了数组

    nums[3] = 1212;

    printf("数组元素为：\n");
    for(i = 0; i < 5; i++)
    {
        printf("%d\t",*(nums + i));
    }
    free(nums);//释放动态分配的内存
    nums = NULL;









    printf("Hello world!\n");
    return 0;
}
