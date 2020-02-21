#include <stdio.h>
#include <stdlib.h>
#include<math.h>
/*int main()
{
    //101-200之间有多少个素数，并输出所有素数和素数的个数
    //用一个数分别除2到sqrt，如果能够被整除，则表明这个数不是素数
    //需要计总数account
    //由2到sqr的起始变量i
    //由101-200的变量x
    /*int account=0,i,x,k,leap;
    for(x=101;x<=200;x++)       //一个个上
    {
        k = sqrt(x);
        for(i=2;i<=k;i++)     //一个个除
        {
            if(x%i==0)
            {
                leap=0;
                break;
            }
            if(leap)
            {

            }
                account++;          //计总数
                printf("%d",x);//输出
                if(account%10==0);
                printf("\n");
        }
        leap=1;
    }
    printf("101-200之间的素数总共有%d\n",account);    //输出总数
    /*printf("Hello world!\n");
    return 0;
}*/
    main()
    {
        int m,i,k,h=0,leap=1;
        printf("\n");
        for(m=101;m<=200;m++)
        {
            k=sqrt(m+1);
            for(i=2;i<=k;i++)
                if(m%i==0)
            {
                leap=0;break;
            }
            if(leap=0)
            {
                printf("%-4d",m);h++;
                if(h%10==0)
                    printf("\n");
            }
            leap=1;
        }
        printf("\nthe total is %d",h);
    }







