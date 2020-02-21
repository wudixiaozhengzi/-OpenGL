#include <stdio.h>
#include <time.h>
/*我们书写一个猜商品的小游戏
1.我们设定一个商品的价格，让用户去猜
2.用户输入猜测的价格后，系统给出大小的提示
3.如果在5轮内就猜到正确的价格，给与奖励提示*/





int main()
{
    int price;  //让用户猜的价格
    int guessprice;  //用户猜测的价格
    int tem1=100;         //用户猜测的价格临时记录
    int tem2=1;
    int tem=0;
    int count = 0;   //用来记录猜的次数
    srand(time(NULL));
    price = rand() % 100 + 1;
    printf("商品价格为1-100");
    for(;;)
    {
        printf("请输入猜测的商品价格：");
        scanf("%d",&guessprice);
        if(guessprice < price)
        {
            tem=guessprice;
            printf("%d~%d",guessprice,tem1);
        }

        else if(guessprice > price)
        {
            tem=guessprice;
            printf("%d~%d",tem2,guessprice);
        }
        else
        {
            printf("恭喜，猜对了");
            break;
        }
        count++;
    }
    printf("一共猜了%d",count);

    return 0;
}




