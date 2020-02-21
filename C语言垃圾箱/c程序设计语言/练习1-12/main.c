#include <stdio.h>
#define IN 1        //在单词内
#define OUT 0       //在单词外
//以每行一个单词的形势打印其输入
main()
{
    int c,state,words;

    state = OUT;
    while((c =getchar()) != EOF)
    {
        if(c == ' ' || c == '\t' || c == '\n')
        {
            if(state == IN)
            {
            putchar('\n');
            state =OUT;
            }
        }
        else if(state == OUT)
            {
            state = IN;
            putchar(c);
            }
        else
            putchar(c);
    }
}




