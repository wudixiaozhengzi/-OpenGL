#include <stdio.h>
#include <time.h>
/*������дһ������Ʒ��С��Ϸ
1.�����趨һ����Ʒ�ļ۸����û�ȥ��
2.�û�����²�ļ۸��ϵͳ������С����ʾ
3.�����5���ھͲµ���ȷ�ļ۸񣬸��뽱����ʾ*/





int main()
{
    int price;  //���û��µļ۸�
    int guessprice;  //�û��²�ļ۸�
    int tem1=100;         //�û��²�ļ۸���ʱ��¼
    int tem2=1;
    int tem=0;
    int count = 0;   //������¼�µĴ���
    srand(time(NULL));
    price = rand() % 100 + 1;
    printf("��Ʒ�۸�Ϊ1-100");
    for(;;)
    {
        printf("������²����Ʒ�۸�");
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
            printf("��ϲ���¶���");
            break;
        }
        count++;
    }
    printf("һ������%d",count);

    return 0;
}




