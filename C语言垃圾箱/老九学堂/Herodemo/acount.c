#include "acount.h"
/*
double GetRepayment(Account account)
{
    account.blankName = "��������";
    return account.limit-account.billAmount;
}
*/

double GetRepayment(Account *account)
{
    account->blankName = "��������";
    return account->limit-account->billAmount;
}



