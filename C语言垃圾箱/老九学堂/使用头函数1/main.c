#include <stdio.h>
#include <stdlib.h>
#include "hotel.h"
extern char HOTELNAMES[4][50];

int main()
{
    int choice; //用户的选择
    int Days;   //用户入住的天数
    double totalCost;   //用户支付的总房费
    double currCost;    //用户当前入住酒店的房费单价

    while((choice = menu()) != 5)
    {
        switch(choice)
        {
            case 1://用户入住第一家酒店
                currCost = HOTEL1;
                break;
            case 2://用户入住第二家酒店
                currCost = HOTEL2;
                break;
            case 3://用户入住第三家酒店
                currCost = HOTEL3;
                break;
            case 4://用户入住第四家酒店
                currCost = HOTEL4;
                break;
            default:
                currCost = 0;
        }
        Days = getNights();
        showPrice(Days,currCost);
    }
    printf("感谢使用本系统：再会！\n");






    return 0;
}
