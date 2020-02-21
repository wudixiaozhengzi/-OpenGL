#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define N 50
#define true 1
#define false 0
/** \brief 排列宝石问题
 *设有n种不同颜色，同一种形状的n颗宝石分别具有不同的颜色。现有n种不同形状的宝石共有n*n，
 将这n*n颗宝石排列成n行n列的方阵，使方阵中每一行每一列都有n种不同的颜色和n种不同形状。
 设计算法，计算出对于给定的n有多少种宝石排列方案。
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
int IsOk[N][N];         //如果满足则为1

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
    //枚举所有可能的情况
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
                    //行列都满足
                    IsOk[i1][j1]=1;
                    a[i][j].color=j1;
                    a[i][j].shape=i1;
                    //下一个
                    compare(k+1);
                    //回溯前的清理工作
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
