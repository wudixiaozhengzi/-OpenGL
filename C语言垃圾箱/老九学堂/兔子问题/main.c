#include <stdio.h>
#include <stdlib.h>

int main()
{
    //��һ�����ӣ��ӳ��������������ÿ���¶���һ������
    //С���ӳ�������������һ�����ӣ��������Ӳ�������ÿ�������������ж��ٶԡ�
    //
    long rib1,rib2;                 //rib1ǰһ�����Ӷ�����rib2��һ����������
    int month;
    //printf("������ٸ��£����Ϊ12����");
   // scanf("%d",month);
    rib1 = rib2 = 1;
    for(month=1;month<=20;month++)
    {
        printf("%12ld%12ld",rib1,rib2);
        if(month%2==0)              //���������ÿ���ĸ���
            printf("\n");
        rib1=rib1+rib2;           //ǰ�����¼�����������������
        rib2=rib1+rib2;           //ǰ�����¼�����������������
    }
   /* printf("Hello world!\n");
    return 0;*/
}
