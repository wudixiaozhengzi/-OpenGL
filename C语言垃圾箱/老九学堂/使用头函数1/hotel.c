//��Ӧhotel.h��ʵ���ļ�
#include <stdio.h>
//�����Զ���ͷ�ļ�ʱ��ʹ��˫����
#include "hotel.h"

char HOTELNAMES[4][50] = {"ϲ����","ϣ����","�޼�","���б��"};
int days;

int menu(void)
{
    int choice;//�û���ѡ��
    int result;//�û������Ľ���ж� 0 ��ʾ�Ƿ���1 ��ʾ��
    int i;
    printf("��ѡ����ס�ľƵ꣺\n");
    for(i = 0; i < 4; i++)
    {
        printf("%d��%s\n",i+1,HOTELNAMES[i]);
    }
    printf("5���˳�����\n");
    printf("���������ѡ��");
    //���û������ֵ���Ϸ�ʱ��Ҫ����������
    while((result=scanf("%d",&choice)) != 1 || choice < 1 ||choice > 5)
    {
        if(result != 1) //����û�����Ĳ�����������
        {
            scanf("%*s");//������������������룬*��ʾ�������ڶ���󲻸�ֵ����Ӧ�ı���
            fflush(stdin);//��ջ�������
        }
        printf("������1-5֮���������");
        scanf("%d",&choice);
    }
    //�û���ѡ�����Ƿ�����
    //�û���������1-4֮��
    return choice;
}

//�����û�Ԥ��������
int getNights(void)
{

    printf("������Ԥ��������");
    while(scanf("%d",&days) != 1)
    {
        scanf("%*s");
        printf("������Ԥ��������");
    }

    return days;
}

void showPrice(int days,double price)
{
    //�ܼ۸�=�ۼ�ǰһ���95%
    double total = 0;
    int i;
    for(i = 0; i < days; i++)
    {
        total += price;
        price = price * DISCOUNT;

    }
    printf("��ס%d�죬�����ѣ�%.2lfԪ",days,total);
}




