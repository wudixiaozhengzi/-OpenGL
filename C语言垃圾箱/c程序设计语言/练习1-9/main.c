#include <stdio.h>
#define NONBLANK 'a'

int main()
{

int c,lastc;
//�����븴�Ƶ�����ĳ��򣬲������������Ķ���ո���һ���ո����
    lastc = NONBLANK;
    while ((c = getchar()) != EOF)
    {
        if(c != ' ' || lastc != ' ')
            putchar(c);
        lastc = c;
    }
}
