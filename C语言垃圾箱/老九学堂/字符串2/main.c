#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//�����յ��ַ�����
char * MyFgets(char [],int);

int main()
{
    char word1[50] = "Helloworld";
    char word2[] = {'H','e','l','l','o','w','o','r','l','d','\0'};
    char word3[] = "��ã��Ͼ�ѧ�ã�";
    printf("word1�ĳ���Ϊ��%d\n",strlen(word1));
    printf("word2�ĳ���Ϊ��%d\n",strlen(word2));
    printf("word3�ĳ���Ϊ��%d\n",strlen(word3));

    char word4[20];

    printf("�������ַ�����");
    MyFgets(word4,50);
    //ʹ�����ú�������word2�е����ݸ��Ƶ�word1������
    strcpy(word1,word2);
    printf("%s\t%s\t",word1,word2);

    return 0;

}

char * MyFgets(char *str,int maxLen)
{
    fgets(str,maxLen,stdin);
    //ȥ�����һλ�ո�
    //�ҵ����һλ
    //��ѧ�߿��ܱȽ�ϲ����ѭ����ʽ
    int count = 0;
    while(str[count] != '\n')
    {
        if(str[count] != '\n')
            break;
        count++;
    }
    return count;
}






