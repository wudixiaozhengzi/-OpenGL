#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Hero
{
    int id;     //
    char name[50];  //Ӣ�۵ĵȼ�
    int level;  //Ӣ�۵ĵȼ�
    int HP;     //Ӣ�۵�Ѫ��
    int MP;     //Ӣ�۵�ħ��ֵ
    char skill[50];//Ӣ�۵ļ���
};

struct Hero1
{
    int id;     //
    char *name;  //Ӣ�۵ĵȼ�
    int level;  //Ӣ�۵ĵȼ�
    int HP;     //Ӣ�۵�Ѫ��
    int MP;     //Ӣ�۵�ħ��ֵ
    char skill[50];//Ӣ�۵ļ���
};

//�ṹ��һ�� �����������ͣ���������������϶���
int main()
{
    //ʹ�ýṹ��
    struct Hero1 hero1 = {2,"����ɩ",10,1000,200,"����"};
    /*hero1.id = 1;
    strcpy(hero1.name,"��������֮��");
    hero1.HP = 500;
    hero1.MP = 100;
    strcpy(hero1.skill,"�󱣽�");*/
    printf("������Ӣ�۵����ƣ�");
    hero1.name = (char*)malloc(50);
    scanf("%s",hero1.name);

    printf("%d\t%s\t%d\t%d\t%d\t%s\t",hero1.id,hero1.name,
            hero1.level,hero1.HP,hero1.MP,hero1.skill);
    return 0;
}






