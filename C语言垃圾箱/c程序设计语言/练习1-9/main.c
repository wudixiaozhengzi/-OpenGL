#include <stdio.h>
#define NONBLANK 'a'

int main()
{

int c,lastc;
//将输入复制到输出的程序，并将其中连续的多个空格用一个空格代替
    lastc = NONBLANK;
    while ((c = getchar()) != EOF)
    {
        if(c != ' ' || lastc != ' ')
            putchar(c);
        lastc = c;
    }
}
