#include <stdio.h>
#include <stdlib.h>
#define N 5    //�궨��
int main()
{
    //��̬¼��
    double score[5];
    int i;
    for(i = 0;i<N;i++)
    {
        printf("�������%dΪͬѧ�ĳɼ���",i+1);
        scanf("%lf",&score[i]);
    }
    for(i=0 ;i<N;i++)
    {
        printf("�������%dΪͬѧ�ĳɼ���%.2lf\n",i+1,score[i]);
    }
    return 0;
}
