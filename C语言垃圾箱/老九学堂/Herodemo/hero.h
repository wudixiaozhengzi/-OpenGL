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
  int life;         //Ӣ������ֵ
  double speed;     //�����ٶ�
  char *ability; //Ӣ����������
  MyTime pubTime;   //Ӣ������ʱ��
}Hero;

void show() ;   //��ʾӢ�۽ṹ
void avglife(); //����ƽ������ֵ

void Input();   //��̬¼��
#endif // HERO_H_INCLUDED
