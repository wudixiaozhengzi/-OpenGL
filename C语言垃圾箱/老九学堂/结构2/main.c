#include <stdio.h>
#include <stdlib.h>

//����
struct Martial
{
    int id;     //����id
    char name[50];  //��������
    int count;      //���ɵ�����
    int type;       //���ɵ�����-1���ɣ�2������3а��
};

struct  Player
{
    int id;
    char name[50];  //�������
    char pass[50];  //��ҵ�������
    char sex;       //����Ա�
    struct Martial martial; //�����������
};

int main()
{
    //���player
    //�����������
    struct Player player = {1,"����ϴͷ��Ʈ��","123456",'f',{1,"�����˹",500,3}};
    struct Player player1 = {2,"�޵���","123456",'f',{1,"�����˹",500,3}};
    struct Player *ptr_player1 = &player1;

    printf("%s\t%s\n",(*ptr_player1).name,(*ptr_player1).martial.name);
printf("%s\t%s\n",ptr_player1->name,ptr_player1->martial.name);
    printf("���ID��%d\n���ƣ�%s\n������룺%s\n����Ա�%c\n������ɣ�%s\n���ɳ�Ա��%d\n�������ͣ�%d",
           player.id,
           player.name,
           player.pass,
           player.sex,
           player.martial.name,
           player.martial.count,
           player.martial.type);
    return 0;
}
