#include <stdio.h>
#include <stdlib.h>
/*
��Ҫһ���������������ÿ�����ֵ
1.ѭ�������ĳ�ֵ
int = 1
2.ѭ���������ж�
while��i<101��
{
3.ѭ�������ĸ���
i++
}

*/
int main()
{
    int i=1;
    int add=0;    //���ÿ�����ֵ
    while(i<=100)
    {
        add=add+i;
  i++;
    }

    printf("1-100�ĺ�Ϊ��%d\n",add);
    return 0;
}










