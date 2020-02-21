#include<stdio.h>
void main()
{
    int a[10],max,min,i;
    printf("Please input numbers:");
    for(i=0;i<10;i++)
    {
        printf("\n%d.  ",i+1);
        scanf("%d",&a[i]);
    }

    max = min = a[0];
    for(i=1;i<10;i++)
    {
        if(a[i]>max)    max = a[i];
        if(a[i]<min)    min = a[i];
    }
    printf("The max Number:%d,The min Number:%d.\n",max,min);
}
