#include "hero.h"
#include <stdio.h>


Hero heros[100] ={
{"Ӱ��֮����",'m',"�̿�",579,0,"�¶�",{2018,7,12}},
{"��ɪ��Ů",'f',"��ʦ",69,0,"�¶�",{2018,7,12}},
{"Ӱ��֮����",'m',"�̿�",59,0," �¶�",{2018,7,12}}
};
int count=3;
void show()
{
    //���֪���ṹ����Ĵ�С
    //int len=sizeof(heros)/sizeof(Hero);
    //����Ԫ��ʹ��ָ��ʱ����̬��ֵ��Ҫ���ȷ����ڴ�
    //printf("���������ƣ�");
    //heros[0].name = (char *)malloc(50);     //char name[50];
    //scanf("%s",heros[0].name);
    printf("����Ӣ�۸�����%d\n",count) ;
    int i;
    for(i = 0; i<count;i++)
    {
        printf("%s\t%d\t%d-%d-%d\n",(heros+i)->name,heros[i].life,heros[i].pubTime.year,heros[i].pubTime.month,heros[i].pubTime.day);
    }
}

void Input()
{
   //����¼������
   //��һ��¼�����֮��ѯ���Ƿ����¼��
   char answer = 'y';
   int c;
   do{
     if(count == 100)
     {
         printf("Ӣ����λ����");
         break;
     }
     printf("��ǰ¼���%dλӢ�۵���Ϣ��\n",count+1);
     printf("hero name:");
     heros[count].name = (char *)malloc(50);
     scanf("%s",heros[count].name);

     printf("hero sex(m/f):");
     fflush(stdin);

     heros[count].sex=getchar();



     printf("hero job:");
     heros[count].job = (char *)malloc(50);
     scanf("%s",heros[count].job);

     heros[count].speed=6.7;
     heros[count].life=1000;

     heros[count].ability="�������";
     heros[count].pubTime.year=2018;
     heros[count].pubTime.month=1;
     heros[count].pubTime.day=2;

     count++;               //¼����Ϻ�Ӣ������++
     printf("�Ƿ�Ҫ����¼��y/n");
     answer = getch();      //�û����¼������������������䣬���������û��ûس���

   }while(answer=='y'||answer=='Y');

}

void avglife()
{
    int i,lifeofsum;
    double avgL;
    lifeofsum=0;
    avgL=0.0;
    for(i=0;i<count;i++)
    {
       lifeofsum += heros[i].life;
         avgL = (lifeofsum*1.0)/count;
    }
    printf("Ӣ�۵�ƽ������ֵ��%lf\n",avgL);
}










