#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 1234;

    while(num > 0);
    {
        printf("%d\n",num % 10);
        num /= 10;//ȡ����λ��������ȥ����λ��
    }
    return 0;
}

exit(0);//�˳�ϵͳ��0���������˳�����0λ�������˳�


/*//��4λ����ûһλ����ȡ����
    printf("��λ��%d\n",num%10);
    printf("ʮλ��%d\n",num / 10 % 10);
    printf("��λ��%d\n",num / 100 % 10);
    printf("ǧλ��%d\n",num / 1000 %10);
    //���ɣ���10��ģ10
    int temp;            //��ʱ����*/
