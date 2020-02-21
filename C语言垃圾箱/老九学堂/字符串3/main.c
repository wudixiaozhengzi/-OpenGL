#include <stdio.h>
#include <stdlib.h>
#define USER_NAME "admin"
#define PASSWORD "admin"
int login(char [],char []);

int main()
{
    char userName[25],password[25];
    printf("用户名：\t");
    gets(userName);
    printf("密码:\t");
    gets(password);
    if(login(userName,password)==1)
    {
        //调用成功后执行的函数
        printf("登入成功！\n");
    }
    else
    {
        printf("登入失败\n");
    }

    printf("Hello world!\n");
    return 0;
}
int login(char userName[],char password[])
    {
        int result = 0;

        if(strcmp(userName,USER_NAME)== 0 && strcmp(password,PASSWORD)== 0)
        {
            return 1;//用户名或密码不匹配就返回值
        }
    }
