#include <stdio.h>
#include <stdlib.h>

int Fbi(int i)
{
    if(i<2)
        return i == 0 ? 0 : 1;
    return Fbi(i-1) + Fbi(i-2);
}

int main()
{
    int i,a[40];
    printf("������ʾ쳲��������У�\n");
    a[0]=0;
    a[1]=1;
    printf("%d\n",a[0]);
    printf("%d\n",a[1]);
    for(i=2; i<10; i++)
    {
        a[i]=a[i-1]+a[i-2];
        printf("%d\n",a[i]);
    }
    printf("\n");
    printf("�ݹ���ʾ쳲��������У�\n");
    for(i=0; i<10; i++)
        printf("%d\n",Fbi(i));
    return 0;
}
