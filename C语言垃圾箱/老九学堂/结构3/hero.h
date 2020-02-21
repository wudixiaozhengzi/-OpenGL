#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

//结构体：英雄，职业，英雄能力，时间
typedef struct _job
{
    int id;
    char * name;    //职业名称
    char * desc;    //职业的描述
}Job;

typedef struct _ability
{
    int id;
    char * name;    //特色能力名称
    char * intro;   //特色能力的说明
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

//用来输入英雄的值
void InputHero();

//用来输入英雄的值
void ShowHero();

#endif // HERO_H_INCLUDED










