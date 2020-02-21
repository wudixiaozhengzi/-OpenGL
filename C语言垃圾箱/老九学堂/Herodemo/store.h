#ifndef STORE_H_INCLUDED
#define STORE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>



//商品具备名称、价格、库存等属性
typedef struct _prop
{
    int id;
    char *name;    //商品名称
    char *information;
    double price;
    int stock;  //库存inventory
}Prop;

//背包结构
typedef struct _bag{
    int playerId;   //所属玩家的编号
    int count;      //当前背包中道具数量
    int max;        //当前背包的插槽总数
    Prop props[8];     //当前背包中的道具数组
}Bag;

//玩家结构
typedef struct _player{
    int id;
    char *name;
    char *pass;     //密码
    Bag bag;        //玩家背包
    double gold;    //玩家金币-人性化显示：可以将1000个铜币转化为银币
    double sysee;   //元宝数量
}Player;

Player *players;
Prop *props;

void Init();
 void showpropsArray();
 void showplayerArray();
 /** \brief 交易函数
  *
  * \param player Player* 参与交易的玩家指针
  * \param propId int    交易的商品
  */
 void Trade(Player *player,int propId);


#endif // STORE_H_INCLUDED
