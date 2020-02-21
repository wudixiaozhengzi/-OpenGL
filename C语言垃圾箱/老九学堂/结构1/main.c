#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Hero
{
    int id;     //
    char name[50];  //英雄的等级
    int level;  //英雄的等级
    int HP;     //英雄的血量
    int MP;     //英雄的魔法值
    char skill[50];//英雄的技能
};

struct Hero1
{
    int id;     //
    char *name;  //英雄的等级
    int level;  //英雄的等级
    int HP;     //英雄的血量
    int MP;     //英雄的魔法值
    char skill[50];//英雄的技能
};

//结构是一种 构造数据类型，有若干数据项组合而成
int main()
{
    //使用结构体
    struct Hero1 hero1 = {2,"祥林嫂",10,1000,200,"嘲讽"};
    /*hero1.id = 1;
    strcpy(hero1.name,"德玛西亚之力");
    hero1.HP = 500;
    hero1.MP = 100;
    strcpy(hero1.skill,"大保剑");*/
    printf("请输入英雄的名称：");
    hero1.name = (char*)malloc(50);
    scanf("%s",hero1.name);

    printf("%d\t%s\t%d\t%d\t%d\t%s\t",hero1.id,hero1.name,
            hero1.level,hero1.HP,hero1.MP,hero1.skill);
    return 0;
}






