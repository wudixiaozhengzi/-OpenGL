#include <stdio.h>
#include <stdlib.h>
#define N 5
int main()
{

    int array[N] = {15,25,30,45,65};
    //ʵ�����������ԭ�����������βԪ�ؽ��н���
    int temp;
    int i;
    int *ptr_array_start = array;           //ָ��������Ԫ�ص�ָ��
    int *ptr_array_end = array + N - 1;     //ָ������ĩԪ�ص�ָ��
    while(ptr_array_start != ptr_array_end)
    {
        temp = *ptr_array_start;
        *ptr_array_start = *ptr_array_end;
        *ptr_array_end = temp;
        //��Ԫ��ָ��Ҫ����ƶ�
        ptr_array_start++;
        //ĩԪ��ָ��Ҫ��ǰ��
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
        //��i��Ԫ�غ͵�N-i-1��ֵ����
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
