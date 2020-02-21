#include <stdio.h>


main()
{
int c,lastc;
//将输入复制到输出的程序，并将其中的指标表符替换为\t，把回退符换为\b，把反斜杠替换为\\。
    while ((c = getchar()) != EOF)
    {
        if(c == '\t')
            printf("\\t");
        else if(c == '\b')
            printf("\\b");
        else if(c == '\\')
            printf("\\\\");
        else
            putchar(c);
        /*
        if(c == '\t')
            printf("\\t");
        if(c == '\b')
            printf("\\b");
        if(c == '\\')
            printf("\\\\");
        if(c != '\b')
            if(c != '\t')
                if(c != '\\')
                    putchar(c);*/
    }
}
