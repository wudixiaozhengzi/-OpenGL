#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//返回传入字符串的长度
int GetStrLength(char[]);

//封装fgets，用来接收字符串的字符数组
void GetString(char [],int count);

void GetString(char str[],int count)
{
    //使用fgets函数接收字符串，使用\0字符数的最后一位\n
    fgets(str,count,stdin);
    //查找\n
    char * find = strchr(str,'\n');
    if(find)//如果找到了
        *find = '\0';   //根据找到的指针，修改指向的元素为\0

}

int GetStrLength(char str[])
{
    int count = 0; //字符串中的字符个数
    int i;
    while(str[count]!='\0')
    {   /*
        if(str[count] == '\n')
        {
            str[count] = '\0';
            break;
        }
        */
        count++;
    }
    return count;
}


int main()
{
    char names1[50];
    //fgets(names1,5,stdin);
    GetString(names1,20);
    int len = GetStrLength(names1);
    printf("字符串的长度为：%d\n",len);


    /*
    int i;
    //定义字符串的几种方式
    //字符串和字符数组的区别：最后一位是否空字符
    char names[] = {'4','a','4','f','d'};   //字符数组

    char names1[] = {'j','a','c','k','\0'}; //字符串

    char names2[] = "jack";

    //printf("数组占空间的大小：%d\n",sizeof(names1));
    //printf("数组占空间的大小：%d\n",sizeof(names2));
    printf("请输入新名称：");

    //gets函数不对接受字符串的buffer进行边界检测，会造成越界，从而产生bug
    //可以使用fgets(words1,20,stdin);代替gets，20表示最多读入20-1个字符
    //gets(names2);    //scanf("%s",names2);
    //put(names2);    //printf("%s\n",names2);
    //fgets会默认给最后一个元素设置为\n
       fgets(names2,10,stdin); //从标准输入流汇总读取10个字节到数组names2中
    printf("数组names2中的内容：\n");
    for(i = 0; i < 50; i++)
    {
        printf("%c\n",names2[i]);
    }*/
    return 0;
}
