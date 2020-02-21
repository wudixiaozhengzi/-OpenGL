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
    printf("交易\n");
    Trade(&players[0],3);
    showpropsArray();
    showplayerArray();
     return 0;
}
    /*printf("%s\n",heros[0].name);
    Input();
    show();
    avglife();


    Account account={"建设银行","Jason",30000,28000};
    double result = GetRepayment(&account);
    printf("应还款：%.2lf\n默认银行是银行：%s",result,account.blankName);
     */

