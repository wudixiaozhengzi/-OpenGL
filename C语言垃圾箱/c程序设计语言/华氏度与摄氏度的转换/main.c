#include <stdio.h>
#include <stdlib.h>

/*��fathr = 0,20��.......��300ʱ��
    �ֱ��ӡ���϶������϶ȵĶ��ձ�*/
#define LOWER 0
#define UPPER 300
#define STEP 20
//����
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
    printf("���϶�     \t���϶�\n");
    for(fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%-3d\t\t%-6.1f\n",fahr,(5.0/9.0)*(fahr-32));

}
    /*
int main()
{
    float fahr,celsius;
    int lower,upper,step;

    lower = 0;          //�¶ȱ�����
    upper = 300;        //�¶ȱ������
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
