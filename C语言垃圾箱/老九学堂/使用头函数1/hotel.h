#ifndef HOTEL_H_INCLUDED
#define HOTEL_H_INCLUDED

#define HOTEL1 872.0    //���ҾƵ��Ĭ�Ϸ���
#define HOTEL2 1838.0
#define HOTEL3 789.0
#define HOTEL4 1658.0
#define DISCOUNT 0.95   //�ۿ���

//�˵���������ʾ�˵�ѡ����ղ������û�������
int menu(void);
//�����û�Ԥ��������
int getNights(void);
//������ס��������ʾ������Ҫ��֧���Ľ��
void showPrice(int days,double price);


#endif // HOTEL_H_INCLUDED
