#include <stdio.h>
#include <stdlib.h>
#define N 5
int main()
{

    int array[N] = {15,25,30,45,65};
    //实现数组的逆序，原理就是数组首尾元素进行交换
    int temp;
    int i;
    int *ptr_array_start = array;           //指向数组首元素的指针
    int *ptr_array_end = array + N - 1;     //指向数组末元素的指针
    while(ptr_array_start != ptr_array_end)
    {
        temp = *ptr_array_start;
        *ptr_array_start = *ptr_array_end;
        *ptr_array_end = temp;
        //首元素指针要向后移动
        ptr_array_start++;
        //末元素指针要向前移
        ptr_array_end--;
    }
    printf("\n");
    for(i = 0; i < N; i++)
    {
        printf("%d\t",*(array + i));
    }

    /*
    for(i = 0; i < N/2; i++)
    {
        //第i个元素和第N-i-1的值调换
        temp = array[i];
        array[i] = array[N-i-1];
        array[N-i-1] = temp;
    }
    printf("\n");
    for(i = 0; i < N; i++)
    {
        printf("%d\t",*(array + i));
    }
*/
    printf("Hello world!\n");
    return 0;
}
