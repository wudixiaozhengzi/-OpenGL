#include <stdio.h>
#include <stdlib.h>

int main()
{
    //有一对兔子，从出生后第三个月起每个月都生一对兔子
    //小兔子长到三个月又生一对兔子，假如兔子不死，问每个月兔子总数有多少对。
    //
    long rib1,rib2;                 //rib1前一个兔子对数，rib2后一个月兔子数
    int month;
    //printf("输入多少个月，最高为12个月");
   // scanf("%d",month);
    rib1 = rib2 = 1;
    for(month=1;month<=20;month++)
    {
        printf("%12ld%12ld",rib1,rib2);
        if(month%2==0)              //控制输出，每行四个数
            printf("\n");
        rib1=rib1+rib2;           //前两个月加起来赋给第三个月
        rib2=rib1+rib2;           //前两个月加起来赋给第三个月
    }
   /* printf("Hello world!\n");
    return 0;*/
}
