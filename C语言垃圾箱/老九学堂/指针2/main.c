#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1 = 1024;
    int num2 = 2048;
    int * ptr1;
    int * ptr2;
    ptr1 = &num1;
    ptr2 = &num2;
    printf("num1��ֵ��%d\tnum1�ĵ�ַ�ǣ�%p\n",num1,ptr1);
    printf("num2��ֵ��%d\tnum2�ĵ�ַ�ǣ�%p\n",num2,ptr2);
    //num2 = num1;
    //*ptr2 = *ptr1;
    ptr2 = ptr1;
    printf("���¸�ֵ��\n");
    printf("num1��ֵ��%d\tnum1�ĵ�ַ�ǣ�%p\n",num1,ptr1);
    printf("num2��ֵ��%d\tnum2�ĵ�ַ�ǣ�%p\n",num2,ptr2);

    *ptr2 = 11111;
     printf("���¸�ֵ��\n");
    printf("num1��ֵ��%d\tnum1�ĵ�ַ�ǣ�%p\n",num1,ptr1);
    printf("num2��ֵ��%d\tnum2�ĵ�ַ�ǣ�%p\n",num2,ptr2);

    printf("Hello world!\n");
    return 0;
}













