#include <stdio.h>
#define IN 1        //�ڵ�����
#define OUT 0       //�ڵ�����
//��ÿ��һ�����ʵ����ƴ�ӡ������
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




