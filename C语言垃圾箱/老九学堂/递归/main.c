#include <stdio.h>
#include <stdlib.h>

int factorial(int num)
{
    if(num == 1)        //ÍË³öÌõ¼ş
        return 1;
    else{
        num = num * factorial(num-1);
        return num;
    }
}

int main()
{
   int result = factorial(5);
   printf("%d",result);
}
