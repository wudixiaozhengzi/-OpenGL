#include <stdio.h>
#include <stdlib.h>

int main()
{
    //����������������׵�ַ
    int i,j;
    double score[5][3] ={
    {45,68,35},
    {35,38,45},
    {25,78,55},
    {15,18,65},
    {5,28,75}
    };
    double (*ptr_score)[3] = score;

    //������һ�����ݣ���һ�е�����������score[0]
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 3; j++)
        {
            //printf("%.2lf\t",score[i][j]);
            //printf("%.2lf\t",*(*(score + i) + j));
            //printf("%.2lf\t",*(score[i] + j));
            printf("%.2lf\t",*(ptr_score[i] + j));
        }
        printf("\n");
    }





    printf("Hello world!\n");
    return 0;
}
