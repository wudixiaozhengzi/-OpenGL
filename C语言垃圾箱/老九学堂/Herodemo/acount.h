#ifndef ACOUNT_H_INCLUDED
#define ACOUNT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct _account
{
    char *blankName;
    char *userName;
    double limit;   //�˻��Ķ��
    double billAmount;  //�����˵����
}Account;
//���ݽṹ����ʱ���Ǹ��������ṹ������ֵ��������-Ч�ʵ�
//double GetRepayment(Account account);   //��ȡ�����˵�
double GetRepayment(Account *account);

#endif // ACOUNT_H_INCLUDED
