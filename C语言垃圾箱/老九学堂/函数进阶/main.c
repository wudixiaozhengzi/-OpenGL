#include <stdio.h>
#include <stdlib.h>

//����ֻ�����ڶ������ذɵ�������
//������һ�����������Ǵ���������������ʱ����-�Զ�����
//�������ڵ�ʱ���Ϊ����������
//ȫ�ֱ���Ĭ��ֵΪ0

void changeNum()
{
    //�ֲ�����
    int num1 = 5,num2 = 8;
    num1 = 55;
    num2 = 288;
}



int main()
{
     int num1 = 5,num2 = 8;
     changeNum();
     printf("num1=%d\tnum2 = %d\n",num1,num2);
     /*
     int count1 = 0;
     do
     {
         int count2 = 0;
         count2++;
         printf("count1 = %d\tcount2 = %d\n",count1,count2);
     }while(++count1 < 5);*/
    return 0;
}
