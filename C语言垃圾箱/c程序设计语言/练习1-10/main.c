#include <stdio.h>


main()
{
int c,lastc;
//�����븴�Ƶ�����ĳ��򣬲������е�ָ�����滻Ϊ\t���ѻ��˷���Ϊ\b���ѷ�б���滻Ϊ\\��
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
