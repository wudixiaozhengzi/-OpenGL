#include <stdio.h>
#include <stdlib.h>
//ʵ���ַ����ļ��������
//���ܷ�ʽ�����ַ�����ÿ���ַ����������ַ����е�λ�ú�һ��ƫ����5
//����xuetang9�У���һ���ַ�x���ַ����е�λ��Ϊ0����ô�����ڵ�Ī����'m'+0+5
#define KEY 5   //ƫ����

char * encrpy(char []);
char * dencrpy(char []);
/*
 *���ܴ���� �ַ���
 *����1��Ҫ���ܵ��ַ���
 *����ֵ�����ؼ��ܺ���ַ���
 */
int main()
{
    char password[50] = "132";
    encrpy(password);
    printf("���ܺ���ַ���Ϊ��%s\n",password);
    dencrpy(password);
    printf("���ܺ���ַ���Ϊ��%s\n",password);
    return 0;
}

char *encrpy(char password[])
{
    int i = 0;
    int count = strlen(password);
    for(;i < count; i++)
    {
        //���ַ�����ÿ���ַ����������ַ����е�λ�ú�һ��ƫ����5
    password[i] = password[i] + i + KEY;

    }
    return password;
}
//����
char * dencrpy(char password[])
{
    int i = 0;
    int count = strlen(password);
    for(;i < count; i++)
    {
        //���ַ�����ÿ���ַ����������ַ����е�λ�ú�һ��ƫ����5
    password[i] = password[i] - i - KEY;

    }
    return password;
}








