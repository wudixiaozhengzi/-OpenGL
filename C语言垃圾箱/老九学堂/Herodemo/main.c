#include <stdio.h>
#include <stdlib.h>
//#include "hero.h"
//#include "acount.h"
#include "store.h"
//extern Hero heros[100];
//extern Prop propsArray[1000];
//extern Player playerArray[1000];

int main()
{
    Init();
    showpropsArray();
    showplayerArray();
    printf("����\n");
    Trade(&players[0],3);
    showpropsArray();
    showplayerArray();
     return 0;
}
    /*printf("%s\n",heros[0].name);
    Input();
    show();
    avglife();


    Account account={"��������","Jason",30000,28000};
    double result = GetRepayment(&account);
    printf("Ӧ���%.2lf\nĬ�����������У�%s",result,account.blankName);
     */

