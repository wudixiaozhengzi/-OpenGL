#include <stdio.h>
#include <stdlib.h>

//break�������ã�����ѭ����ִ��ѭ����������




int main()
{
    //ѭ��������ҵ����䣬�������Ϊ����ֹͣ���룬��ʾ�������
    int age;
    //for(;;)
    for(;;)
    {
        printf("������������䣺");
        scanf("%d",&age);
        if(age<0)
        {
            printf("���䲻��Ϊ����������ǿ���˳���\n");
            break;
        }
    }
    return 0;
}










