#include "hero.h"
Hero heros[5];
Job jobs[] = {
{1,"法师","专家"},
{2,"刺客","千年杀专家"},
{3,"战士","我的肉特别厚"},
{4,"坦克","靠机甲吃饭"},
{5,"法坦","专家"}
};

void InputHero()
{
    //动态录入
    int i,j;
    int jobChoice;

    for(i = 0; i < 1; i++)
    {
        printf("请输入第%d个英雄的信息：\n",i+1);
        heros[i].id = i+1;

        printf("名称：");
        heros[i].name = (char*)malloc(50);
        scanf("%s",heros[i].name);

        printf("性别：1.男      2.女\n");
        scanf("%s",&heros[i].sex);
        fflush(stdin);      //录入字符后记得清空缓冲区
        //良好的用户体验，设定一个职业数组，让用户选择
        printf("\n");
        for(j = 0; j < 5; j++)
        {
            printf("%d、%s\n",j+1,jobs[j].name);
        }

        printf("请选择职业，1-5之间的整数");
        scanf("%d",&jobChoice);
        heros[i].job = jobs[jobChoice - 1];
        printf("%s当前的职业：（%s）\n",heros[i].name,heros[i].name);
    }
}

void ShowHero()
{

}




