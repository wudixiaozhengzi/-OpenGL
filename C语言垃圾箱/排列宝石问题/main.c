#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define N 50
#define true 1
#define false 0
/** \brief ���б�ʯ����
 *����n�ֲ�ͬ��ɫ��ͬһ����״��n�ű�ʯ�ֱ���в�ͬ����ɫ������n�ֲ�ͬ��״�ı�ʯ����n*n��
 ����n*n�ű�ʯ���г�n��n�еķ���ʹ������ÿһ��ÿһ�ж���n�ֲ�ͬ����ɫ��n�ֲ�ͬ��״��
 ����㷨����������ڸ�����n�ж����ֱ�ʯ���з�����
 *2019-01-26
 *
 * \return
 *
 */


typedef struct
{
    int shape;
    int color;
}Node;
Node a[N][N];
int n=2;
long num;
int IsOk[N][N];         //���������Ϊ1

void compare(int k)
{
    int i,j;
    int i1,j1;
    int i2,j2;

    if(k>=n*n){
        printf("\n");
        for(i=0;i<n;i++,printf("\n"))
            for(j=0;j<n;j++)
                printf("(%d,%d)",a[i][j].shape,a[i][j].color);
        num++;
    }
    int row,col;
    i=k/n;j=k%n;
    //ö�����п��ܵ����
    for(i1=0;i1<n;i1++)
        for(j1=0;j1<n;j1++){
            if(!IsOk[i1][j1]){
                col=true;row=true;
                for(i2=0;i2<i;i2++)
                    if(a[i2][j1].color==j1 || a[i2][j1].shape==i1){
                        col=false;
                        break;
                    }
                for(j2=0;j2<j;j2++)
                    if(a[i1][j2].shape==i1 || a[i1][j2].color==j1){
                        row=false;
                        break;
                    }
                if(col&&row){
                    //���ж�����
                    IsOk[i1][j1]=1;
                    a[i][j].color=j1;
                    a[i][j].shape=i1;
                    //��һ��
                    compare(k+1);
                    //����ǰ��������
                    IsOk[i][j]=0;
                    a[i][j].color=-1;
                    a[i][j].shape=-1;
                }

            }
        }
        return;
}
int main()
{
    int i,j;
    //printf("input n:");
    //scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            IsOk[i][j]=0;
            a[i][j].color=-1;
            a[i][j].shape=-1;
        }
    num=0;
    compare(0);
    printf("the number of method:%ld\n",num);
    return 0;
}
