#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y,z;      //x大鸡数量，y不大不小的数量，z小鸡的数量
    for(x = 0; x < 100; x++)
        for(y = 0; y < 100; y++)
            {
                z=100-x-y;
                if(z < 0)
                    continue;
                if(((x*3+y*2+z/3) == 100)&&((z%3) == 0))    //三种鸡花费一共100，z%3==0表示小鸡的数量一定要是3的倍数
                {
                    printf("x=%d,y=%d,z=%d\n",x,y,z);
                }
            }
    return 0;
}
