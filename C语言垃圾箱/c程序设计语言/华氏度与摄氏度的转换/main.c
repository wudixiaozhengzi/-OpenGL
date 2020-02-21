#include <stdio.h>
#include <stdlib.h>

/*当fathr = 0,20，.......，300时，
    分别打印华氏度与摄氏度的对照变*/
#define LOWER 0
#define UPPER 300
#define STEP 20
//逆序
main()
{
    float fahr,celsius;
    for(celsius = LOWER; celsius <= UPPER; celsius = celsius + STEP)
    {
        fahr = (9.0*celsius) / 5.0 + 32.0;
        printf("%3f\t\t%-6.1f\n",celsius,fahr);
    }
}



/*
main()
{
    int fahr;
    printf("华氏度     \t摄氏度\n");
    for(fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%-3d\t\t%-6.1f\n",fahr,(5.0/9.0)*(fahr-32));

}
    /*
int main()
{
    float fahr,celsius;
    int lower,upper,step;

    lower = 0;          //温度表下限
    upper = 300;        //温度表的上限
    step = 20;

    fahr = lower;
    while(fahr <= upper)
    {
        celsius = (5.0/9.0) * (fahr-32);
        printf("%3.0f\t%6.1f\n",fahr,celsius);
        fahr = fahr + step;
    }


    printf("Hello world!\n");
    return 0;
}
*/
