#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
/** \brief
 *�ļ�����game.h
 *��  ��������������Ϸ��һЩ���Ľṹ�ͺ���
 *ʱ  �䣺2019/1/5
 *�����ˣ�֣Զ��
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
//���赱ǰ�û�������
int X =3,Y =2;

/********************** ��Ϸ�Ľṹ���Ͷ���***********/
//��ҡ���ͼ��װ��������
/**********************       ��������       ***********/

/*
typedef struct _martial{
    int id;     //���ɱ��
    char name[20];      //��������
    Martialtype type;   //��������
    COORD hqCoord;      //��������
    int isOpen;     //�Ƿ񿪷�
    char desc[500];          //���ɽ���
}Martial;               */

/**********************       ��Ϸ����       ***********/
typedef enum _proptpye{     /*��Ϸ��������ö��*/
    Weapon, Armor, Book, Consumables, Fragment
}PropType;

typedef struct _prop{       /*��Ϸ���� - ���������ߡ�����Ʒ����Ƭ*/
    int id;         //���߱��
    char name[50];  //��������
    int level;      //���ߵļ���
    PropType type;  //���ߵ�����
    int stock;      //���ߵĿ�����ұ����еĵ�������
    union{//���ϡ���ѡһ
        int minAttack; //������������Ͷ�Ӧ������
        int minDefence;    //������ߣ��Ͷ�Ӧ������
        int minPower;      //���������Ʒ���Ͷ�Ӧ������Ч��
    };
    union{//���ϡ���ѡһ
        int maxAttack; //������������Ͷ�Ӧ������
        int maxDefence;    //������ߣ��Ͷ�Ӧ������
        int maxPower;      //���������Ʒ���Ͷ�Ӧ������Ч��
    };
    double price;   //���ߵĵ���
    char desc[200]; //���ߵĹ�������
}Prop;

/**********************        ���        ***********/
typedef struct _bag{
    int playerId;       //������ұ��
    int propCount;      //��ǰ���ߵ�����
    int propMax;        //��������������
    Prop props[8];      //�����еĵ������飬Ĭ��8�����߲��(8�������óɳ���)
}Bag;

typedef struct _player{
    int id;
    char name[50];  //�������
    char pass[50];  //��ҵ�½����
    int life;       //�����������Ĭ��100����������һ�μ���ǰ���������ֵ
    int level;      //��Ҽ���-���͵ȼ�=LOG2(��Ҿ���)��ȡ��+1��������������65����ô���͵ȼ�=LOG2 65��ȡ��+1=6+1=7��
    int exp;        //��Ҿ���ֵ
    int hp;         //��ҵ�ǰѪ��
    int mp;         //�������ֵ-����ֵΪ0���������
    int mpMax;      //��ҵ�ǰ������������-��������=30��15��*����
    int gold;       //��ҽ����

    Prop weapon;    //��װ��������
    Prop armor;     //��װ���ķ���
    COORD currCoord;//��ҵ�ǰ���꣨X-�У�Y-�У����������������෴
    Bag bag;
}Player;

/**********************        ��ͼ        ***********/
typedef struct _map{    /*��Ϸ��ͼ�ṹ-��š����ơ����ܡ���ҽ���ȼ�*/
    double id;         //��ͼ���
    char name[50];  //��ͼ����
    int minLevel;   //��ҽ������͵ȼ�
    //����ṹ
    COORD coord;    //��ͼ����
    char desc[500];
}Map;

/**********************       ����ϵͳ       ***********/
typedef struct _monster{
    int id;
    char name[50];  //��������
    int level;      //���Ｖ��
    int hp;         //��������ֵ
    int att;        //���﹥����
    int deff;       //���������
    int minMoney;   //��������Сֵ
    int maxMoney;   //���������ֵ
    int exp;        //ɱ����������þ���ֵ
    int state;      //����״̬��1-���棬0-����
    COORD mCoord;   //�������ڵ�ͼ���꣨X-�У�Y-�У����������������෴
}Monster;



void Init();                        //��ʼ������

void ShowProp();                    //��ʾ����
void ShowPlayer(int i);             //��ʾ�����Ϣ
void ShowWelcome();                     //��ӭ����
void ShowMap();
void ShowInformation();
void ShowMainMenu();




#endif // GAME_H_INCLUDED
