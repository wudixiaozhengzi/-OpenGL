#include <stdio.h>
#include <stdlib.h>

int main()
{
    //理解字符串和字符指针的区别
    char str1[] = "For The Hords";
    char *str2 = "For The Hords";

    printf("字符串常量的地址：%p\n","For The Hords");
    printf("字符数组的首地址：%p\n",str1);
    printf("字符指针的取值：%p\n",str2);


    return 0;
}
