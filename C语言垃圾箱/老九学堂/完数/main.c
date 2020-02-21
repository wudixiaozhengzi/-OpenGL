#include <stdio.h>
#include <stdlib.h>
//一个数如果恰好等于她的因子之和，这个数就称为“完数”，例如6=1+2+3
//编程找出1000以内的所有完数。
int main()
{

}



/*
int main()
{
    static int k[10];
    int i,j,n,s;
    for(j=2;j<1000;j++)
    {
        n=-1;
        s=j;
        for(i=1;i<j;i++)
        {
            if(j%i==0)
            {
                n++;
                s=s-i;
                k[n]=i;
            }
        }
        if(s==0)
        {
            printf("%d is a wanshu: ",j);
            for(i=0;i<n;i++)
                printf("%d",k[i]);
            printf("%d\n",k[n]);
        }
    }















    /*printf("Hello world!\n");
    return 0;
}
*/
