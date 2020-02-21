#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;
    int x[1000],y[1000];
    double sum=0;
    double area=0;
    printf("请输入点的个数：\n");
    while(scanf("%d",&n) && n!=0)
    {

        printf("请输入坐标点，示例：1 2\n");
        for(i=0; i<n;i++)
        {
            scanf("%d %d",&x[i],&y[i]);
        }
        for(i=0;i<=n-1;i++)
        {
            sum=sum+(x[i]*y[i+1]-x[i+1]*y[i]);
        }
        sum = sum+(x[n]*y[0]-y[n]*x[0]);
        area=0.5*abs(sum);
        printf("%.2lf\n",area);
    }
}
