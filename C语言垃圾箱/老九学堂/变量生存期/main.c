#include <stdio.h>
#include <stdlib.h>

//1.����ĳ�������������˶��ٴ�

//ȫ�ֱ������������Ǳ��ļ�
int whileCount=0;


int main()
{
    int value;      //�Զ�����
    register int i;//��ѭ����������Ϊ�Ĵ����洢ģʽ
    printf("������ѭ��ִ�еĴ�������0 �˳�����");
    //�û������valueΪ���������Ҵ���0ʱ������ѭ��
    while(scanf("%d",&value) == 1 && value > 0)//ʵ��һ��ѭ��¼���Ч��
    {
        whileCount++;
        for(i = value; i >= 0; i--)
        {
            counter(i);//ÿ��ѭ������counter����
        }
        printf("������ѭ��ִ�еĴ�������0 �˳�����");
    }

    return 0;
}
