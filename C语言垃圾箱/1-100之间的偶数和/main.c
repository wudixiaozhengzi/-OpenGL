#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int sum=0;
    /*����һ
    for(i=0;i<100;i+=2)
    {
        sum+=i;
    }
    */
    //������
    for(i=0;i<100;i++)
    {
        if(i%2!=0)
            continue;
        sum+=i;
    }
    printf("1-100��ż����Ϊ%d",sum);
    return 0;
}
