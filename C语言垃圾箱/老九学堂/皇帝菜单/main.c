#include <stdio.h>
#include <stdlib.h>
//whileѭ����do-whileѭ��������
//ִ��˳��ͬ
//��ʼ���������ѭ������ʱ  1.whileѭ��һ�ζ�����ִ��    2.do-whileѭ�������κ����������ִ��һ��


int main()
{
    int choice;                 //�û���ѡ��
    //��ӡ��Ϸ�˵�
    while(1)
    {
    printf("�Ը���ԣ�\n");
    printf("�������һλ�������������Եİ�����ϣ����\n");
    printf("1.ֻ��һλ�氮������\n");
    printf("2.������λ���ϵİ���\n");
    printf("3.ӵ����ǧ����\n");
    do{//���������󡣽���һֱѭ������
        printf("��ѡ��");
        scanf("%d",&choice);
        if(choice <= 0||choice >3)
        {
            printf("ֻҪ����1-3֮������֣����������룺\n");
        }
    }while(choice <= 0||choice >3);
    //���ִ�е������֤���û�������ʱ��ȷ�ģ���1-3֮��
    switch(choice)
    {
    case 1:
        printf("��ѡ���������е�Ψһ��Ȼ��֣�����Ѿ�������һ�У�\n");
        break;
    case 2:
        printf("������Ĵ��ܲ���\n");
        break;
    case 3:
        printf("����磬10Ԫ/������������ʣ�\n");
        break;
    }
    }
    return 0;
}
