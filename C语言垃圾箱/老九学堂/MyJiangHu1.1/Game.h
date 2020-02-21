#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
/** \brief
 *文件名：game.h
 *描  述：用来定义游戏的一些核心结构和函数
 *时  间：2019/1/5
 *创建人：郑远环
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
//假设当前用户的坐标
int X =3,Y =2;

/********************** 游戏的结构类型定义***********/
//玩家、地图、装备、怪物
/**********************       江湖门派       ***********/

/*
typedef struct _martial{
    int id;     //门派编号
    char name[20];      //门派名称
    Martialtype type;   //门派类型
    COORD hqCoord;      //门派坐标
    int isOpen;     //是否开放
    char desc[500];          //门派介绍
}Martial;               */

/**********************       游戏道具       ***********/
typedef enum _proptpye{     /*游戏道具类型枚举*/
    Weapon, Armor, Book, Consumables, Fragment
}PropType;

typedef struct _prop{       /*游戏道具 - 武器、防具、消耗品、卡片*/
    int id;         //道具编号
    char name[50];  //道具名称
    int level;      //道具的级别
    PropType type;  //道具的类型
    int stock;      //道具的库存或玩家背包中的叠加数量
    union{//联合—多选一
        int minAttack; //如果是武器，就对应攻击力
        int minDefence;    //如果防具，就对应防御力
        int minPower;      //如果是消耗品，就对应增加其效果
    };
    union{//联合—多选一
        int maxAttack; //如果是武器，就对应攻击力
        int maxDefence;    //如果防具，就对应防御力
        int maxPower;      //如果是消耗品，就对应增加其效果
    };
    double price;   //道具的单价
    char desc[200]; //道具的功能描述
}Prop;

/**********************        玩家        ***********/
typedef struct _bag{
    int playerId;       //所属玩家编号
    int propCount;      //当前道具的总数
    int propMax;        //背包中最大道具数
    Prop props[8];      //背包中的道具数组，默认8个道具插槽(8可以设置成常量)
}Bag;

typedef struct _player{
    int id;
    char name[50];  //玩家名称
    char pass[50];  //玩家登陆密码
    int life;       //玩家生命数，默认100条命，死亡一次减当前级别点生命值
    int level;      //玩家级别-侠客等级=LOG2(玩家经验)的取整+1（举例：经验是65，那么侠客等级=LOG2 65的取整+1=6+1=7）
    int exp;        //玩家经验值
    int hp;         //玩家当前血量
    int mp;         //玩家内力值-内力值为0，玩家死亡
    int mpMax;      //玩家当前级别内力上限-内力上限=30万＋15万*级别
    int gold;       //玩家金币数

    Prop weapon;    //所装备的武器
    Prop armor;     //所装备的防具
    COORD currCoord;//玩家当前坐标（X-行，Y-列），与正常坐标轴相反
    Bag bag;
}Player;

/**********************        地图        ***********/
typedef struct _map{    /*游戏地图结构-编号、名称、介绍、玩家进入等级*/
    double id;         //地图编号
    char name[50];  //地图名称
    int minLevel;   //玩家进入的最低等级
    //坐标结构
    COORD coord;    //地图坐标
    char desc[500];
}Map;

/**********************       怪物系统       ***********/
typedef struct _monster{
    int id;
    char name[50];  //怪物名称
    int level;      //怪物级别
    int hp;         //怪物生命值
    int att;        //怪物攻击力
    int deff;       //怪物防御力
    int minMoney;   //掉落金币最小值
    int maxMoney;   //掉落金币最大值
    int exp;        //杀死后玩家所得经验值
    int state;      //怪物状态，1-生存，0-死亡
    COORD mCoord;   //怪物坐在地图坐标（X-行，Y-列），与正常坐标轴相反
}Monster;



void Init();                        //初始化数据

void ShowProp();                    //显示道具
void ShowPlayer(int i);             //显示玩家信息
void ShowWelcome();                     //欢迎界面
void ShowMap();
void ShowInformation();
void ShowMainMenu();




#endif // GAME_H_INCLUDED
