#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;//ÐÐ
    int j;//ÁÐ
    for(i=0;i<4;i++)
    {
        for(j=0;j<=2-i;j++)
        {
            printf(" ");
        }
        for(j=0;j<=i*2;j++)
        {
            if(i==0||i==3||j==0||j==2*i)
            printf("*");
            else
                printf(" ");
        /*printf("%c",'A'+i);
        printf("%c",'A'+j);*/
        }
        printf("\n");

    }
    return 0;
}

