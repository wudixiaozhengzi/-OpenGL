#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0;     //ѭ������
    int password;//����

    while(i < 3)
    {
        printf("���������룺");
    scanf("%d",&password);
        if(123456 != password)
        {
            printf("error,��ǰ�����%d������\n",i+1);
        }
        //�������������ͻ�ǿ���˳�ϵͳ
        if(i==2)
        {
            printf("����������Σ�ǿ���˳�ϵͳ\n");
            exit(0);//���߲���ϵͳ�����������˳�
        }
        i++;

    }











    /*printf("Hello world!\n");
    return 0;*/
}
