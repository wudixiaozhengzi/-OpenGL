#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    /*
     //ceil -   ��һ��     floor - ȥβ��
     //����Ǹ��������෴
    printf("%.2lf\n",ceil(-98.1));
    printf("%.2lf\n",floor(-98.9));

     printf("%.2lf\n",sqrt(9));

      printf("%.2lf\n",pow(5,2));

       printf("%.2lf\n",abs(-98));      //�����ֵ

    //1.�����������--һ���ʱ������
    srand(NULL);
    //2.ȡ�����
    int num = rand();
    printf("%d\n",num);

    exit(0);    //0�����˳�Ӧ�ó���     ��0��ʾ�������˳�

    printf("��");
    //system("color 4E");
    //system("pause");
    printf("ɶ");
   // system("cls");      //����-
    //system("shutdown /r /t 180");   //180����Զ��ػ�
    system("shutdown /a");              //ȡ���Զ��ػ�

    int *nums;
    int i;
    //Ϊǰ���ָ�붯̬������20���ֽڵĿռ�
    nums = (int *)malloc(20);       //
    //double *dnums = (double *)malloc(sizeof(double)*5)
    //nums = (int *)malloc(sizeof(double) * 5);
    //����������������׵�ַ
    //����int nums[5];
    //Ϊָ�붯̬����ռ��ָ����������

    for(i = 0; i < 5; i++)
    {
        printf("�������%d��Ԫ�أ�",i+1);
        scanf("%d",nums + i);
    }



    printf("����Ԫ��Ϊ��\n");
    for(i = 0; i < 5; i++)
    {
        printf("%d\t",*(nums + i));
    }
    free(nums);//�ͷŶ�̬������ڴ�
    nums = NULL;*/





    int *nums;
    int i;
    //Ϊǰ���ָ�붯̬������20���ֽڵĿռ�

    nums = calloc(5,sizeof(int));

    //����������������׵�ַ
    //����int nums[5];
    //Ϊָ�붯̬����ռ��ָ����������

    nums[3] = 1212;

    printf("����Ԫ��Ϊ��\n");
    for(i = 0; i < 5; i++)
    {
        printf("%d\t",*(nums + i));
    }
    free(nums);//�ͷŶ�̬������ڴ�
    nums = NULL;









    printf("Hello world!\n");
    return 0;
}
