#include <stdio.h>
#include <stdlib.h>
/*
for(���ʽ1;���ʽ2;���ʽ3)
    ���ʽ1��ͨ��Ϊѭ����������ֵ����ʡ��
    ���ʽ2��ѭ���������Ƿ����ִ��ѭ������ʡ��
    ���ʽ3������ѭ��������ֵ����ʡ��
    �ֺŲ���ʡ��
{
���
}
const����     ���ܱ��޸ĵ���


int main()
{
    const int num = 100;
    num++;
    return 0;
}

int main()
{
    int i;
    double salary;      //����
    double total_salary = 0;    //6���µ��ܹ���
    double avg_salary;      //6����ƽ������
    for(i=0;i<6;i++)
    {
        printf("�������%d���µĹ��ʣ�",i+1);
        scanf("%lf",&salary);
        //�ۼ�
        total_salary += salary;
    }
    avg_salary = total_salary / 6;
    printf("�ܹ���Ϊ%lf\nƽ������Ϊ%lf",total_salary,avg_salary);
    return 0;
}
*/

//����ӷ���
int main()
{
    int num;
    int i;
    printf("������һ�����֣�");
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        printf("%d + %d = %d",i,(num-i),num);
        if(i%2==0)
        {
            printf("\t");
        }
        else
        {
            printf("\n");
        }
    }
    return 0;
}










