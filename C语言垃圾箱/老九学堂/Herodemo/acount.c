#include "acount.h"
/*
double GetRepayment(Account account)
{
    account.blankName = "招商银行";
    return account.limit-account.billAmount;
}
*/

double GetRepayment(Account *account)
{
    account->blankName = "招商银行";
    return account->limit-account->billAmount;
}



