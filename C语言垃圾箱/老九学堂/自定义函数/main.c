#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//����ԭ��
void calcCircle();
void calcRectangle();
int calcSun();         //��һ��һ�ٵ�ż����
/*
    ����Բ�����������ʵ�֣�
*/
void calcCircle()
{
    double radius,s;
    printf("������Բ�뾶��");
    scanf("%lf",&radius);
    s = 3.14 * pow(radius,2);
    printf("Բ�����Ϊ%lf\n",s);
}

void calcRectangle()
{
    double width,height,s;      //�����
    printf("�������͸ߣ�");
    scanf("%lf%lf",&width,&height);
    if(width <= 0 || height <=0)
    {
        printf("�������ֵ����Ϊ��ֵ");
        return;
    }
    s = width * height;
    printf("���ε����Ϊ%lf\n",s);
}

int calcSun()
{
    //��һ��һ�ٵ�ż����
    int sum = 0;
    int i = 1;
    for(i = 1; i <= 100; i++)
    {
        if(i % 2 == 0)
            sum += i;
    }
}


int main()
{
    /*����ͼ�ε�������㹫ʽ���£�
    Բ��s = PI*r*r;
    �����Σ�s = width*height;
    ���Σ�s = width*height;
    ʹ�ú����ֱ�ʵ������ͼ�ε�������㣬��ӡ��������
    */
    //��д�����Ĳ��裬��ɺ�����Ҫ��
    //��������Ҫһ��ʼ��ȥ����������ĳ������

    //��Ҫ����ֵ��
    //��������ʲô
    //��Ҫ�����

    calcCircle();       //���ü���Բ����ĺ���
    calcRectangle();

    //��������з���ֵ������ʱ���ǵ�ʹ�ö�Ӧ���͵ı���������
    int sum = calcSun();
    printf("1-100֮���ż����Ϊ��%d\n",sum);

    printf("Hello world!\n");
    return 0;
}
