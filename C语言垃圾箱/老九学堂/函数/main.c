#include <stdio.h>
#include <ctype.h>

int main()
{
    /*
    //常用内置函数        0表示假，非0表示真
    printf("%d\n",isupper('a'));        //是否为大写
    printf("%d\n",islower('a'));        //是否为小写

    printf("%d\n",isalpha('a'));        //返回的字符是否为字母
    printf("%d\n",isalpha(97));

    //如果传入的数字，表示的是ASCII码
    printf("%d\n",isdigit(9));        //放回的字符是否为数字
    printf("%d\n",isdigit('9'));

    //转换大小写
    printf("大写%c\n",toupper('a'));


    */
    //思考题：如何将哟农户输入的小写数字转换成中文大写？
    //1234  -   一千两百三十四元整
    int money,count=0;
    int i = 0;
    int moneys[6];
    char unit[10][4] = {"零","壹","贰","叁","肆","伍","陆","柒","捌","玖"};
    printf("请输入金额：");
    scanf("%d",&money);
    while(money != 0)
    {
        moneys[i] = money % 10;
        money /= 10;         //去掉最后一位
        i++;
        count++;
    }
    printf("用户输入的数字一共有%d位！\n",count);
    printf("数组中的内容： \n");
    for(i = 0; i < count; i++)
    {
        printf("%d - %s\n",moneys[i],unit[moneys[i]]);
    }



    /*
    int i;
    for(i = 0; i < 127; i++)
    {
        printf("%c,",i);
    }
*/

    printf("Hello world!\n");
    return 0;
}
