#include <stdio.h>
#define IN 1        //�ڵ�����
#define OUT 0       //�ڵ�����
#define NONBLANK 'a'

main()
{
    int c;
    int nc;            //nc���ַ�����
    int nl;           //nl���м���
    int nb;             //�ո��������
    int nt;             //�Ʊ��������
    int letters;        //��¼Ӣ�ķ���
    int others;         //���������ַ�
    int words;           //��������
    int state;           //����λ��
    int lastc;

    nl = 0;
    nc = 0;
    nt = 0;
    nb = 0;
    letters = 0;
    others = 0;
    words = 0;

    printf("�����룺");
    while((c =getchar()) != EOF)
    {
        ++nc;
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
            letters++;                              //���������Ӣ����ĸʱ����letters��1
        else if(c == '\n')
        nl++;
        else if(c == ' ')
        ++nb;
        else if(c == '\t')
        ++nt;

        else
            others++;                           //������ļ�����Ӣ����ĸ�ֲ��ǿո�������Ǳ���others��1
    }

    //    for(nc=0; getchar()!=EOF; nc++)      //++nc����س����ַ�

    printf("�ַ���Ϊ%d\n����Ϊ%d\n�ո����Ϊ%d\n�Ʊ��Ϊ%d\nӢ���ַ�%d\n�����ַ�%d\n",nc,nl,nb,nt,letters,others);


}



/*
main()
{
    char c;                                     //����cΪ�ַ���
    int letters = 0, space = 0, digit = 0, others = 0;    //����letters��space��digit��others���ĸ�����Ϊ��������
    printf("please input some characters\n");
    while ((c = getchar()) != '\n')                      //������Ĳ��ǻس�ʱִ��whileѭ���岿��
    {
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
            letters++;                              //���������Ӣ����ĸʱ����letters��1
        else
            if (c == ' ')
                space++;                            //��������ǿո�ʱ����space��1
        else
            if (c >= '0' && c <= '9')
                digit++;                            //�������������ʱ����digit��1
        else
            others++;                           //������ļ�����Ӣ����ĸ�ֲ��ǿո�������Ǳ���others��1
    }
    printf("char=%d space=%d digit=%d others=%d\n",letters,space,digit,others);    //������ͳ�ƽ�����
}
*/
