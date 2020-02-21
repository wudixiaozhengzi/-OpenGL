#ifndef ACOUNT_H_INCLUDED
#define ACOUNT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct _account
{
    char *blankName;
    char *userName;
    double limit;   //账户的额度
    double billAmount;  //当月账单金额
}Account;
//传递结构变量时，是复制整个结构变量的值到函数中-效率低
//double GetRepayment(Account account);   //获取当月账单
double GetRepayment(Account *account);

#endif // ACOUNT_H_INCLUDED
