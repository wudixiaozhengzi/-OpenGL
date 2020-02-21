#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <windows.h>

#define MARGIN_X 15  //��߾�
enum GameStatus{
    GameMainMenu = 1, GameRunning = 2, GameFighting = 3, GameSplashScreen = 4, GameExit = 5
};
/************************** ���� *****************************/
typedef struct _martial{
    int id;         //���ɱ��
    char name[21];  //��������
    char type[11];  //�������ͣ����ɡ�а�ɡ�������а
    COORD hqCoord;  //�ܲ����꣨X-�У�Y-�У����������������෴
    int isOpen;     //�Ƿ񿪷�
    char description[1000];//��������
}Martial;
//��Ϸ��������ö�٣���Ӧ ���������ߡ��ķ�������Ʒ����Ƭ
typedef enum _propType{
    Weapon, Armor, Book, Consumables, Fragment
} PropType;
/************************* ��Ϸ���� *************************/
typedef struct _prop{
    int id;
    char name[50];
    int level;
    PropType type;
    int stock;          //��ǰ���ߵ�����
    union{
        int attack;     //������������Ͷ�Ӧ������
        int defense;    //����Ƿ��ߣ��Ͷ�Ӧ������
        int power;      //�����Ѫƿ������Ʒ����Ӧ���ӵ�����ֵ
    };

    double price;
    char desc[200];     //��Ϸ��������
}Prop;
/************************ ��ұ��� *************************/
typedef struct _bag{
    int playerId;       //������ұ��
    int propCount;      //��ǰ���ߵ�����
    int propMax;        //��������������
    Prop props[8];      //�����еĵ������飬Ĭ��8�����߲��(8�������óɳ���)
}Bag;
/************************* ��ҽṹ *************************/
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
    Martial martial;//��������
    Prop weapon;    //��װ��������
    Prop armor;     //��װ���ķ���
    COORD currCoord;//��ҵ�ǰ���꣨X-�У�Y-�У����������������෴
    Bag bag;
}Player;
/**************************** ���� ****************************/
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
void InitializeGame();  //��ʼ����Ϸ����
void StartNewGame();    //��������Ϸ
void EndGame();         //������Ϸ

void ProcessMenu();
void ProcessSplash();
void ProcessGame();
void ProcessExit();
/* ��Ϸҵ������ */
void Process(char key);

void ShowInfo();
void ShowPlayer();
void ShowMap();
void ShowMonster(); //��ʾ����
void ShowFight(Player *player, Monster *monster);
void ShowSplash();
void ShowMenu();
void ShowGame();
void ShowExit();
void show();
void ShowHQ();//���ܲ�
void ShowTrade();//����װ��
/* ���ؽ����Ƿ�ɹ� */
int Trade(Player *player, int propId);


#endif // GAME_H_INCLUDED

