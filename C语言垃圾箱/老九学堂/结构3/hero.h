#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

//�ṹ�壺Ӣ�ۣ�ְҵ��Ӣ��������ʱ��
typedef struct _job
{
    int id;
    char * name;    //ְҵ����
    char * desc;    //ְҵ������
}Job;

typedef struct _ability
{
    int id;
    char * name;    //��ɫ��������
    char * intro;   //��ɫ������˵��
}Ability;

typedef struct _pubTime
{
    int year;
    int month;
    int day;
}PubTime;

typedef struct _hero
{
    int id;
    char * name;
    char sex;
    Job job;
    double HP;
    double MP;
    double speed;
    Ability ability;
    PubTime pubTime;
}Hero;

//��������Ӣ�۵�ֵ
void InputHero();

//��������Ӣ�۵�ֵ
void ShowHero();

#endif // HERO_H_INCLUDED










