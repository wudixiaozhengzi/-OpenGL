#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y,z;      //x��������y����С��������zС��������
    for(x = 0; x < 100; x++)
        for(y = 0; y < 100; y++)
            {
                z=100-x-y;
                if(z < 0)
                    continue;
                if(((x*3+y*2+z/3) == 100)&&((z%3) == 0))    //���ּ�����һ��100��z%3==0��ʾС��������һ��Ҫ��3�ı���
                {
                    printf("x=%d,y=%d,z=%d\n",x,y,z);
                }
            }
    return 0;
}
