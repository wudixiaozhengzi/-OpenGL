/*
my count.c
用来存放计算函数调用次数的函数原型及实现
*/
//引用外部变量
extern int whileCount;

void counter(int);//用来计算本函数被调用多少次

void counter(int i)
{
    static int subTotal = 0;//静态存储，第一次执行会分配空间，以后就不会再分配空间了，本句只会执行一次

    subTotal++;
    printf("counter函数被调用了%d次\n",subTotal);
    printf("当前是while的第%d轮！\n",whileCount);
    return subTotal;
}











