#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//���ش����ַ����ĳ���
int GetStrLength(char[]);

//��װfgets�����������ַ������ַ�����
void GetString(char [],int count);

void GetString(char str[],int count)
{
    //ʹ��fgets���������ַ�����ʹ��\0�ַ��������һλ\n
    fgets(str,count,stdin);
    //����\n
    char * find = strchr(str,'\n');
    if(find)//����ҵ���
        *find = '\0';   //�����ҵ���ָ�룬�޸�ָ���Ԫ��Ϊ\0

}

int GetStrLength(char str[])
{
    int count = 0; //�ַ����е��ַ�����
    int i;
    while(str[count]!='\0')
    {   /*
        if(str[count] == '\n')
        {
            str[count] = '\0';
            break;
        }
        */
        count++;
    }
    return count;
}


int main()
{
    char names1[50];
    //fgets(names1,5,stdin);
    GetString(names1,20);
    int len = GetStrLength(names1);
    printf("�ַ����ĳ���Ϊ��%d\n",len);


    /*
    int i;
    //�����ַ����ļ��ַ�ʽ
    //�ַ������ַ�������������һλ�Ƿ���ַ�
    char names[] = {'4','a','4','f','d'};   //�ַ�����

    char names1[] = {'j','a','c','k','\0'}; //�ַ���

    char names2[] = "jack";

    //printf("����ռ�ռ�Ĵ�С��%d\n",sizeof(names1));
    //printf("����ռ�ռ�Ĵ�С��%d\n",sizeof(names2));
    printf("�����������ƣ�");

    //gets�������Խ����ַ�����buffer���б߽��⣬�����Խ�磬�Ӷ�����bug
    //����ʹ��fgets(words1,20,stdin);����gets��20��ʾ������20-1���ַ�
    //gets(names2);    //scanf("%s",names2);
    //put(names2);    //printf("%s\n",names2);
    //fgets��Ĭ�ϸ����һ��Ԫ������Ϊ\n
       fgets(names2,10,stdin); //�ӱ�׼���������ܶ�ȡ10���ֽڵ�����names2��
    printf("����names2�е����ݣ�\n");
    for(i = 0; i < 50; i++)
    {
        printf("%c\n",names2[i]);
    }*/
    return 0;
}
