#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j;
    for(i=1;i<10;i++)
    {
        for(j=1;j<10;j++)
            {
                printf("%d*%d=%-3d\t",i,j,i*j);//-3表示左对齐，占3位
            }
            printf("\n");
    }
    return 0;
    /*printf("Hello world!\n");
    return 0;*/
}
