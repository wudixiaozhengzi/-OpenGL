#include <stdio.h>
#include <stdlib.h>
//指针是一个值为内存地址的变量
int main()
{
    int num = 0;
    int *ptr_num = &num;
    //头疼点：指针的地址
    int *ptr_num2 = &ptr_num;
    //%p指针占位符，%x  16进制占位符
    printf("num变量的地址是：%p\n%x\n",ptr_num,&num);

    printf("\n指针ptr_num的地址是：%p\n%x\n",ptr_num2,&num);

    //使用指针修改变量值
    /*
    *ptr_num = 9999;
    printf("*ptr_num对应的值为：%d\n",*ptr_num);
    printf("*ptr_num对应的值为：%d\n",num);*/
    return 0;
}
