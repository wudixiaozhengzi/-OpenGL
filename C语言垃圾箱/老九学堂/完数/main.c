#include <stdio.h>
#include <stdlib.h>
//һ�������ǡ�õ�����������֮�ͣ�������ͳ�Ϊ��������������6=1+2+3
//����ҳ�1000���ڵ�����������
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
