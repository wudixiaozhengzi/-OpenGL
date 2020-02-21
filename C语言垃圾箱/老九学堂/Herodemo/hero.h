#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED

typedef struct _mytime
{
    int year;   int month;  int day;
}MyTime;
typedef struct _hero
{
  char *name;
  char sex;
  char *job;
  int life;         //英雄生命值
  double speed;     //攻击速度
  char *ability; //英雄特殊能力
  MyTime pubTime;   //英雄上线时间
}Hero;

void show() ;   //显示英雄结构
void avglife(); //计算平均生命值

void Input();   //动态录入
#endif // HERO_H_INCLUDED
