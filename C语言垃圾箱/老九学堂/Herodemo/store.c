#include "store.h"
#include <string.h>
Player *players;
Prop *props;
 int propscount=0,playerscount=0;

void Init()     //初始化数据
{
    static Prop propsArray[]={
        {1,"adsf","adfasdfasdf",12,100},
        {2,"aadsf","adfadsdfasdf",552,100},
        {3,"asf","adfadfasdf",524,100},
        {4,"asdff","adfadfasdf",522,100},
        {5,"awesf","adfadfasdf",582,100},
        {6,"aswetf","adfadfasdf",542,100},
        {7,"asfqwe","adfadfvcasdf",582,100},
        {8,"asfgf","adfaerdfasdf",2,100},
        {9,"adf","adfaerdfasdf",562,100},
        {10,"asf","adfaerdfasdf",592,100},
    };
    propscount=sizeof(propsArray)/sizeof(Prop);
    props = propsArray;
    static Player playerArray[]={
        {1,"sjfglak","123",{1,1,100,{{3,"asf","adfadfasdf",524,1}}},50000,0},
        {2,"sjffds","123",.gold=50000}
    };
    playerscount=sizeof(playerArray)/sizeof(Player);
    players = playerArray;
}

void showpropsArray()
{
     int i;
     if(props==NULL)    return;
     printf("商品名称\t商品价格\n");
     for(i=0;i<propscount;i++)
        printf("%s\t%lf\n",props[i].name,props[i].price);
}

void showplayerArray()
{
     int i;
     if(players==NULL)    return;
    printf("玩家姓名\t玩家金币\t背包总物品数\t物品名称\t物品数量\n");
     //应该双循环打印背包信息
     for(i=0;i<playerscount;i++)
        printf("%-5s\t%.2lf\t%d\t%s\t%d\n",
               players[i].name,players[i].gold,
               players[i].bag.count,players[i].bag.props[0].name,players[i].bag.props[0].stock);
}

void Trade(Player *player,int propId)
{
    int i;
    //需要判断：商品的库存、玩家余额、玩家背包空间
    Prop *tradeProp;    //要购买的商品指针
    for(i= 0;i<propscount;i++){
          if(propId == props[i].id){
             tradeProp=&props[i];   //tradeProp=props+i;
             break;
          }
    }
    if(tradeProp->stock <= 0){
        printf("地主家没有余粮了。\n");
        return;
    }
    if(player->gold <tradeProp->price){
        printf("你没钱\n");
        return;
    }
    if(player->bag.count>=player->bag.max){
        printf("背包已满交易失败\n");
        return;
    }
    //满足条件，执行交易业务
    //1.商品库存-1
    tradeProp->stock--;
    //2.玩家金币-商品单价
    player->gold-=tradeProp->price;
    //3.玩家背包道具增加
    //判断玩家背包中是否已有该商品
    //如果没有该商品，该商品添加到背包中
    //如果有，背包中该商品总数+1
    for(i=0;i<player->bag.count;i++){
        if(propId==player->bag.props[i].id){
            player->bag.props[i].stock++;
            break;
        }
    }
    if(i==player->bag.count){
        int newIndex=player->bag.count;
        player->bag.props[newIndex].id=tradeProp->id;
        player->bag.props[newIndex].stock=1;
        player->bag.props[newIndex].price=tradeProp->price;
        strcpy(player->bag.props[newIndex].name,tradeProp->name);
        strcpy(player->bag.props[newIndex].information,tradeProp->information);
    }player->bag.count++;
}






