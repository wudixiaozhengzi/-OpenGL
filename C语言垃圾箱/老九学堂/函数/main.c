#include <stdio.h>
#include <ctype.h>

int main()
{
    /*
    //�������ú���        0��ʾ�٣���0��ʾ��
    printf("%d\n",isupper('a'));        //�Ƿ�Ϊ��д
    printf("%d\n",islower('a'));        //�Ƿ�ΪСд

    printf("%d\n",isalpha('a'));        //���ص��ַ��Ƿ�Ϊ��ĸ
    printf("%d\n",isalpha(97));

    //�����������֣���ʾ����ASCII��
    printf("%d\n",isdigit(9));        //�Żص��ַ��Ƿ�Ϊ����
    printf("%d\n",isdigit('9'));

    //ת����Сд
    printf("��д%c\n",toupper('a'));


    */
    //˼���⣺��ν�Ӵũ�������Сд����ת�������Ĵ�д��
    //1234  -   һǧ������ʮ��Ԫ��
    int money,count=0;
    int i = 0;
    int moneys[6];
    char unit[10][4] = {"��","Ҽ","��","��","��","��","½","��","��","��"};
    printf("�������");
    scanf("%d",&money);
    while(money != 0)
    {
        moneys[i] = money % 10;
        money /= 10;         //ȥ�����һλ
        i++;
        count++;
    }
    printf("�û����������һ����%dλ��\n",count);
    printf("�����е����ݣ� \n");
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
