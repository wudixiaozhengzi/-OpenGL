#include <stdio.h>
#include <stdlib.h>

int main()
/*  double num = 6;  С����ת������  Ϊ�Զ�����ת��
    int num1=num��   ������תΪС���ͣ���ʧ����  Ϊǿ������ת��


{
    int num=10;
    num++;//�ȼ���num=num+1
    num += 5;//�ȼ���num = num + 5
    printf("%d\n",num);
    return 0;
}

{
    int num = 5,num1 = 10;
    int result = num++;
    //�൱���Ȱ�num����result��Ȼ��num���Լ�
    int result1 = --num1;
    //�൱���Ȱ�num1�Լ����ٸ���result1
    printf("result = %d\nnum=%d\n",result,num);
    printf("result1 = %d\nnum1=%d\n",result1,num1);
    return 0;
}

{
    //sizeof
    printf("������ռ�Ŀռ���%d�ַ�\n",sizeof(int));
}
*/

{
    //ɱ����switch�ṹ���÷�
    //һ�����������е�ĳ����������
    //��֪��ĳ�����ж�����
    int month;
    printf("�������·ݣ������ж�������");
    scanf("%d",&month);
    switch(month)
    {
    case 1:
        printf("31\n");
        break;
    case 2:
        printf("28\n");
        break;
    case 3:
        printf("31\n");
        break;
    default:
        printf("��ʱ�޷��ж�");
        break��
    }
}
















