#include <stdio.h>
#include <stdlib.h>
//c�����е��ַ���ƴ��
//strcat(str1,str2) ��2���ַ���ƴ�ӵ�1��


int main()
{
    char str1[100] = "��ã��й���";
    char str2[20] = "���";

    strcat(str1,str2);
    printf("str1:%s\tstr2:%s",str1,str2);



    return 0;
}
