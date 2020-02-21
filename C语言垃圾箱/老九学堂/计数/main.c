#include <stdio.h>
#define IN 1        //在单词内
#define OUT 0       //在单词外
#define NONBLANK 'a'

main()
{
    int c;
    int nc;            //nc是字符计数
    int nl;           //nl是行计数
    int nb;             //空格符的数量
    int nt;             //制表符的数量
    int letters;        //记录英文符号
    int others;         //计数其他字符
    int words;           //计数单词
    int state;           //单词位置
    int lastc;

    nl = 0;
    nc = 0;
    nt = 0;
    nb = 0;
    letters = 0;
    others = 0;
    words = 0;

    printf("请输入：");
    while((c =getchar()) != EOF)
    {
        ++nc;
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
            letters++;                              //当输入的是英文字母时变量letters加1
        else if(c == '\n')
        nl++;
        else if(c == ' ')
        ++nb;
        else if(c == '\t')
        ++nt;

        else
            others++;                           //当输入的即不是英文字母又不是空格或数字是变量others加1
    }

    //    for(nc=0; getchar()!=EOF; nc++)      //++nc会算回车的字符

    printf("字符数为%d\n行数为%d\n空格符号为%d\n制表符为%d\n英文字符%d\n其他字符%d\n",nc,nl,nb,nt,letters,others);


}



/*
main()
{
    char c;                                     //定义c为字符型
    int letters = 0, space = 0, digit = 0, others = 0;    //定义letters、space、digit、others、四个变量为基本整型
    printf("please input some characters\n");
    while ((c = getchar()) != '\n')                      //当输入的不是回车时执行while循环体部分
    {
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
            letters++;                              //当输入的是英文字母时变量letters加1
        else
            if (c == ' ')
                space++;                            //当输入的是空格时变量space加1
        else
            if (c >= '0' && c <= '9')
                digit++;                            //当输入的是数字时变量digit加1
        else
            others++;                           //当输入的即不是英文字母又不是空格或数字是变量others加1
    }
    printf("char=%d space=%d digit=%d others=%d\n",letters,space,digit,others);    //将最终统计结果输出
}
*/
