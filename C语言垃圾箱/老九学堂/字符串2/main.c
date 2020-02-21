#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//最大接收的字符长度
char * MyFgets(char [],int);

int main()
{
    char word1[50] = "Helloworld";
    char word2[] = {'H','e','l','l','o','w','o','r','l','d','\0'};
    char word3[] = "你好，老九学堂！";
    printf("word1的长度为：%d\n",strlen(word1));
    printf("word2的长度为：%d\n",strlen(word2));
    printf("word3的长度为：%d\n",strlen(word3));

    char word4[20];

    printf("请输入字符串：");
    MyFgets(word4,50);
    //使用内置函数，将word2中的内容复制到word1数组中
    strcpy(word1,word2);
    printf("%s\t%s\t",word1,word2);

    return 0;

}

char * MyFgets(char *str,int maxLen)
{
    fgets(str,maxLen,stdin);
    //去掉最后一位空格
    //找到最后一位
    //初学者可能比较喜欢的循环方式
    int count = 0;
    while(str[count] != '\n')
    {
        if(str[count] != '\n')
            break;
        count++;
    }
    return count;
}






