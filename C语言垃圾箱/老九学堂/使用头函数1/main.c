#include <stdio.h>
#include <stdlib.h>
#include "hotel.h"
extern char HOTELNAMES[4][50];

int main()
{
    int choice; //�û���ѡ��
    int Days;   //�û���ס������
    double totalCost;   //�û�֧�����ܷ���
    double currCost;    //�û���ǰ��ס�Ƶ�ķ��ѵ���

    while((choice = menu()) != 5)
    {
        switch(choice)
        {
            case 1://�û���ס��һ�ҾƵ�
                currCost = HOTEL1;
                break;
            case 2://�û���ס�ڶ��ҾƵ�
                currCost = HOTEL2;
                break;
            case 3://�û���ס�����ҾƵ�
                currCost = HOTEL3;
                break;
            case 4://�û���ס���ļҾƵ�
                currCost = HOTEL4;
                break;
            default:
                currCost = 0;
        }
        Days = getNights();
        showPrice(Days,currCost);
    }
    printf("��лʹ�ñ�ϵͳ���ٻᣡ\n");






    return 0;
}
