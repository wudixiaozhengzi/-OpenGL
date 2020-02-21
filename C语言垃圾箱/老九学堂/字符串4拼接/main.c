#include <stdio.h>
#include <stdlib.h>
//c语言中的字符串拼接
//strcat(str1,str2) 把2号字符串拼接到1号


int main()
{
    char str1[100] = "你好，中国！";
    char str2[20] = "你好";

    strcat(str1,str2);
    printf("str1:%s\tstr2:%s",str1,str2);



    return 0;
}
