#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*ɾ�����߼�
    12  34  23  67  9
    1.  ����Ҫɾ�����ֵ��±�  2
    12  34  67  9   9
    2.  ���±꿪ʼ�������һ������ǰ�������
    3.�����ܳ���-1
    12  34  67  9
    */
    int count = 5;        //��ʾ����Ԫ�صĸ���
    double  powers[]={42322,45771,40907,41234,40767};
    double deletepower;    //�û�Ҫɾ����ս��ֵ
    int deleteIndex = -1;    //Ҫɾ��ս��ֵ���±꣬��һ�������ܵ�ֵ�������ж�
    int i;              //ѭ������
    double InsertPower; //�²����ս��ֵ
    printf("������Ҫɾ����ս��ֵ");
    scanf("%lf",&deletepower);
    for(i = 0; i < count; i++)
    {
        if(deletepower == powers[i])
        {
            //��¼�µ�ǰ���±�
            deleteIndex = i;
            break;
        }
    }
    //�����жϣ��Ƿ��ҵ�����ִ�к�������
    if(-1 == deleteIndex)
    {
        printf("���ź�û���ҵ�");
    }
    else
    {
        //���±꿪ʼ������һ������ǰ���һ����
        for(i = deleteIndex; i < count; i++)
        {
            powers[i] = powers[i+1];
        }
        //ɾ���꣬�ǵ������ܳ���-1
        count--;

    }
    printf("ɾ����Ľ��Ϊ��\n");
    for(i=0;i<count;i++)
    {
        printf("%.2lf\t",powers[i]);
    }
    //ɾ������в���
    printf("\n��������ս��ֵ��");
    scanf("%lf",&InsertPower);
    powers[count]=InsertPower;//���뵽���
    count++;
     printf("�����Ľ��Ϊ��\n");
    for(i=0;i<count;i++)
    {
        printf("%.2lf\t",powers[i]);
    }
    //�������ս��ֵ������ð�ݷ�

    printf("Hello world!\n");
    return 0;
}










