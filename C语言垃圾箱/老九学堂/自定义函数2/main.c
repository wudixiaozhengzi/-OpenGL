#include <stdio.h>
#include <stdlib.h>
/*书写函数实现数组元素的查找，要求返回找到的元素下标
书写函数实现冒泡排序并返回排序后的数组
书写函数要求用户输入密码（6位，错误则重新输入），返回并打印用户输入的正确密码*/


//书写函数实现数组元素的查找，要求返回找到的元素下标
int search();
//书写函数实现冒泡排序并返回排序后的数组
//double[] sort();
//书写函数要求用户输入密码（6位，错误则重新输入），返回并打印用户输入的正确密码
//char * password();


int main()
{
     int index=search();
     printf("找到的元素下标为%d\n",index);
    printf("Hello world!\n");
    return 0;
}

int search()
{
    int nums[] = {45,35,84,46,21};
    int i;
    //要查找的数字，所查找数字的下标，没找到index为-1
    int searchNum,searchIndex = -1;

    printf("请输入要查找的整型数字：");
    scanf("%d",&searchNum);
    //穷举法
    for(i = 0; i < 5; i++)
    {
        if(searchNum == *(nums + i))
        {
            searchIndex = i;//记录下查找大下标
            break;
        }
    }
    return searchIndex;
}
















