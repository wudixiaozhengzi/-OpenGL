#include <stdio.h>
#include <stdlib.h>
#define USER_NAME "admin"
#define PASSWORD "admin"
int login(char [],char []);

int main()
{
    char userName[25],password[25];
    printf("�û�����\t");
    gets(userName);
    printf("����:\t");
    gets(password);
    if(login(userName,password)==1)
    {
        //���óɹ���ִ�еĺ���
        printf("����ɹ���\n");
    }
    else
    {
        printf("����ʧ��\n");
    }

    printf("Hello world!\n");
    return 0;
}
int login(char userName[],char password[])
    {
        int result = 0;

        if(strcmp(userName,USER_NAME)== 0 && strcmp(password,PASSWORD)== 0)
        {
            return 1;//�û��������벻ƥ��ͷ���ֵ
        }
    }
