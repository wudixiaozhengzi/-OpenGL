#include <stdio.h>
#include <stdlib.h>
#include<math.h>
/*int main()
{
    //101-200֮���ж��ٸ���������������������������ĸ���
    //��һ�����ֱ��2��sqrt������ܹ���������������������������
    //��Ҫ������account
    //��2��sqr����ʼ����i
    //��101-200�ı���x
    /*int account=0,i,x,k,leap;
    for(x=101;x<=200;x++)       //һ������
    {
        k = sqrt(x);
        for(i=2;i<=k;i++)     //һ������
        {
            if(x%i==0)
            {
                leap=0;
                break;
            }
            if(leap)
            {

            }
                account++;          //������
                printf("%d",x);//���
                if(account%10==0);
                printf("\n");
        }
        leap=1;
    }
    printf("101-200֮��������ܹ���%d\n",account);    //�������
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







