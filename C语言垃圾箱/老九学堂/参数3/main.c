#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 /*����ͼ�ε�������㹫ʽ���£�
    Բ��s = PI*r*r;
    �����Σ�s = width*height;
    ���Σ�s = width*height;
    ʹ�ú����ֱ�ʵ������ͼ�ε�������㣬��ӡ��������
    */

//����ԭ��
double calcCircle(double);      //���ݴ���İ뾶������Բ���
double calcRectangle(double,double);   //���ݴ���ĳ������ؾ��ε����

//��Ҫ���û���������зǸ���֤
int validate(double);        //��֤�����double���������Ƿ�Ϊ����

//���û�������ȷ��ֵ
double input();             //������ֱ�����û����룬���������Ҫ�������¼��



double calcCircle(double radius)
{
    double s;

    s = 3.14 * pow(radius,2);

    return s;

}



/*
    ������ε����������ʵ�֣�
*/
double calcRectangle(double width,double height)
{
    double s;      //�����

    s = width * height;

    return s;
}





int validate(double num)        //��֤�����double���������Ƿ�Ϊ����
{
    return num > 0;            //���num>0���᷵��һ������ֵ����ʾ��
}





int main()
{
    double radius;      //�û�����İ뾶
    double width,height;
    double s;           //ͼ�ε����
    int choice;

    printf("1.Բ\n");
    printf("2.����\n");
    printf("3.������\n");
    printf("��ϵͳ֧�ּ�������ͼ�ε��������ѡ��\n");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        printf("������Բ�뾶����������Բ�������");
        do{
            scanf("%lf",&radius);
            if(!validate(radius))
            {
            printf("��¼������ݲ���Ϊ������������һ��������");
            }
        }while(!validate(radius));      //����֤��ͨ����ʱ������¼��
        s = calcCircle(radius);         //����Բ�������ʽ
        printf("Բ�����Ϊ%lf\n",s);
         break;

    case 2:
        printf("�������͸ߣ�");
         do{
            scanf("%lf%lf",&width,&height);
            if(!validate(width) || !validate(height))
            {
                printf("��¼������ݲ���Ϊ����������������������");
            }
        }while(!validate(width) || !validate(height));      //����֤��ͨ����ʱ������¼��

        s = calcRectangle(width,height);
        printf("���ε����Ϊ%lf\n",s);

        break;

    case 3:

        break;

    default:

        printf("��ϵͳֻ֧��3��ͼ�Σ�����1-3֮��ѡ��!");
        scanf("%d",&choice);
    }


    return 0;
}









