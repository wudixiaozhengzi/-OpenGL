#include <stdio.h>


int main()
{
    int nums[]={8,4,2,1,23,344,12};
    int i;                              //ѭ������
    int sum;                            //���
    double avg;                         //��ƽ��ֵ
    int searchnum;                      //Ҫ���ҵ�����
    printf("�������Ԫ�أ�\n");
    for(i = 0; i < 7; i++)
    {
        printf("%d\t",nums[i]);
    }
    printf("\n**********************\n");
    //�����ƽ��ֵ
    for(i=0;i<7;i++)
    {
        sum += nums[i];//������ۼ�
    }
    avg=sum/7.0;            //��7.0��Ϊ�˱��double����
    printf("ƽ����Ϊ%.2lf",avg);
    //��������
    printf("������Ҫ���ҵ����֣�");
    scanf("%d",&searchnum);
    //��ٷ�
    for(i=0;i<7;i++)
    {
        //һ����Ԫ�ؽ��жԱ�
        if(searchnum==nums[i])
        {
            printf("�ҵ���\n");
            //�ҵ��Ժ�����ѭ��
            break;
        }

    }
    //����ѭ������������ж��Ƿ��ҵ����أ�
    //ͨ���۲죬ѭ�������˳�ʱ��i��ֵӦ��Ϊ7
    if(i==7)
    {
        printf("ãã�˺���û���ҵ����ʵ�");
    }
}







