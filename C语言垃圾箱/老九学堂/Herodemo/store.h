#ifndef STORE_H_INCLUDED
#define STORE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>



//��Ʒ�߱����ơ��۸񡢿�������
typedef struct _prop
{
    int id;
    char *name;    //��Ʒ����
    char *information;
    double price;
    int stock;  //���inventory
}Prop;

//�����ṹ
typedef struct _bag{
    int playerId;   //������ҵı��
    int count;      //��ǰ�����е�������
    int max;        //��ǰ�����Ĳ������
    Prop props[8];     //��ǰ�����еĵ�������
}Bag;

//��ҽṹ
typedef struct _player{
    int id;
    char *name;
    char *pass;     //����
    Bag bag;        //��ұ���
    double gold;    //��ҽ��-���Ի���ʾ�����Խ�1000��ͭ��ת��Ϊ����
    double sysee;   //Ԫ������
}Player;

Player *players;
Prop *props;

void Init();
 void showpropsArray();
 void showplayerArray();
 /** \brief ���׺���
  *
  * \param player Player* ���뽻�׵����ָ��
  * \param propId int    ���׵���Ʒ
  */
 void Trade(Player *player,int propId);


#endif // STORE_H_INCLUDED
