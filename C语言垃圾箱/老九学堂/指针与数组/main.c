#include <stdio.h>
#include <stdlib.h>
//存储在一块连续的内存空间内
//数组名就是这块连续内存空间的首地址
int main()
{
    //数组名就是数组的首地址
    int i;
    double score[] = {98,87,65,43,76};
    double *ptr_score;
    ptr_score = score;
    printf("double\n");
    for(i = 0; i < 5; i++)
    {
       // printf("%.2lf\n",ptr_score[i]);
        printf("%.2lf\n",*(ptr_score+ i));
        //printf("%.2lf\n",*ptr_score++);
    }
    printf("数组的首地址：%p\t数组首元素的地址：%p\n",score,&score[0]);
    printf("Hello world!\n");
    //重新访问数组元素前，记得重置指针的位置
    ptr_score = socre;
    for(i = 0; i < 5; i++)
    {
       // printf("%.2lf\n",ptr_score[i]);
        printf("%.2lf\n",*(ptr_score+ i));
        //printf("%.2lf\n",*ptr_score++);
    }
    return 0;
}
