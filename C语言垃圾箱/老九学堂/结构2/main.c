#include <stdio.h>
#include <stdlib.h>

//门派
struct Martial
{
    int id;     //门派id
    char name[50];  //门派名称
    int count;      //门派的人数
    int type;       //门派的类型-1正派，2中立，3邪派
};

struct  Player
{
    int id;
    char name[50];  //玩家名称
    char pass[50];  //玩家登入密码
    char sex;       //玩家性别
    struct Martial martial; //玩家所属门派
};

int main()
{
    //玩家player
    //玩家所属门派
    struct Player player = {1,"和尚洗头用飘柔","123456",'f',{1,"洛克萨斯",500,3}};
    struct Player player1 = {2,"无敌呢","123456",'f',{1,"洛克萨斯",500,3}};
    struct Player *ptr_player1 = &player1;

    printf("%s\t%s\n",(*ptr_player1).name,(*ptr_player1).martial.name);
printf("%s\t%s\n",ptr_player1->name,ptr_player1->martial.name);
    printf("玩家ID：%d\n名称：%s\n玩家密码：%s\n玩家性别：%c\n玩家门派：%s\n帮派成员：%d\n帮派类型：%d",
           player.id,
           player.name,
           player.pass,
           player.sex,
           player.martial.name,
           player.martial.count,
           player.martial.type);
    return 0;
}
