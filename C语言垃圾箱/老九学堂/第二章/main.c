#include <stdio.h>
#include <stdlib.h>
/*
1.������������ĸ���»���
2.��������������ĸ�����»��ߡ����ֵ� ��ĸ
3.����ʹ�ùؼ���

       8 bit�����أ�=1 byte(�ֽ�)

int main()
{
    //ʹ�ñ�����ʾ��Ϸ��ɫ�Ĺ�����
    //1.��������ʲô���͵�����
    //2.��ʲô���Ʊ�ʾ������
    int gongjiPower;//������

    return 0;
}

int main()
{
    int num1=10
    ,num2=8;
    printf("%d����˼\n%dĿ����",num1,num2);
}

int main()
{
    float height=150.0f,width=25.0f;
    float s=height*width;
    printf("�����ε����Ϊ��%.2f\n",s);//.2ֻ������λС��
    return 0;
}

void main()
{
    double radius=2.5,area=30141592653*radius*radius;
    printf("Բ�İ뾶Ϊ%lf�����Ϊ%lf\n",radius,area);//%lf����double
}

int main()
{
    char ch='A';//�ַ�
    printf("ascll��%d\t%c\n",ch);
    return 0;
}
*/
int main()
{
    //��Ҫ���弸������������ʵ������˺�����ҵ���������������˺�
    //��Ӧʲô�������ͣ�    double         int          double
    double factshanghai;//����ʵ������˺�
    int strength;//�������
    double maxshanghai=256;//��������˺�
    printf("��������뵱ǰ��ɫ��������");
    //&ȡ��ַ
    scanf("%d",&strength);
    //���ù�ʽ
    factshanghai = maxshanghai * (strength + 100) / 100;
    printf("����ʵ���˺���%.2lf",factshanghai);
    return 0;
}




