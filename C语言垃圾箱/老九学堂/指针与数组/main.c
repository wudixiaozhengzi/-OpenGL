#include <stdio.h>
#include <stdlib.h>
//�洢��һ���������ڴ�ռ���
//������������������ڴ�ռ���׵�ַ
int main()
{
    //����������������׵�ַ
    int i;
    double score[] = {98,87,65,43,76};
    double *ptr_score;
    ptr_score = score;
    printf("double\n");
    for(i = 0; i < 5; i++)
    {
       // printf("%.2lf\n",ptr_score[i]);
        printf("%.2lf\n",*(ptr_score+ i));
        //printf("%.2lf\n",*ptr_score++);
    }
    printf("������׵�ַ��%p\t������Ԫ�صĵ�ַ��%p\n",score,&score[0]);
    printf("Hello world!\n");
    //���·�������Ԫ��ǰ���ǵ�����ָ���λ��
    ptr_score = socre;
    for(i = 0; i < 5; i++)
    {
       // printf("%.2lf\n",ptr_score[i]);
        printf("%.2lf\n",*(ptr_score+ i));
        //printf("%.2lf\n",*ptr_score++);
    }
    return 0;
}
