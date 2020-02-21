#include <stdio.h>
#include <stdlib.h>


//将输入复制到输出
int main()
{
    int c;

    while ((c = getchar())!= EOF)
        putchar(c);
    /*
    c = getchar();
    while(c != EOF)
    {
        putchar(c);
        c = getchar();
    }
*/
}
