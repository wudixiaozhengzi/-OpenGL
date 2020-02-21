#include <stdio.h>
#include <stdlib.h>
//实现字符串的加密与解密
//加密方式：将字符串中每个字符加上他在字符串中的位置和一个偏移量5
//例如xuetang9中，第一个字符x在字符串中的位置为0，那么他对于的莫问是'm'+0+5
#define KEY 5   //偏移量

char * encrpy(char []);
char * dencrpy(char []);
/*
 *加密传入的 字符串
 *参数1：要加密的字符串
 *返回值：返回加密后的字符串
 */
int main()
{
    char password[50] = "132";
    encrpy(password);
    printf("加密后的字符串为：%s\n",password);
    dencrpy(password);
    printf("解密后的字符串为：%s\n",password);
    return 0;
}

char *encrpy(char password[])
{
    int i = 0;
    int count = strlen(password);
    for(;i < count; i++)
    {
        //将字符串中每个字符加上他在字符串中的位置和一个偏移量5
    password[i] = password[i] + i + KEY;

    }
    return password;
}
//解密
char * dencrpy(char password[])
{
    int i = 0;
    int count = strlen(password);
    for(;i < count; i++)
    {
        //将字符串中每个字符加上他在字符串中的位置和一个偏移量5
    password[i] = password[i] - i - KEY;

    }
    return password;
}








