#include "hero.h"
Hero heros[5];
Job jobs[] = {
{1,"��ʦ","ר��"},
{2,"�̿�","ǧ��ɱר��"},
{3,"սʿ","�ҵ����ر��"},
{4,"̹��","�����׳Է�"},
{5,"��̹","ר��"}
};

void InputHero()
{
    //��̬¼��
    int i,j;
    int jobChoice;

    for(i = 0; i < 1; i++)
    {
        printf("�������%d��Ӣ�۵���Ϣ��\n",i+1);
        heros[i].id = i+1;

        printf("���ƣ�");
        heros[i].name = (char*)malloc(50);
        scanf("%s",heros[i].name);

        printf("�Ա�1.��      2.Ů\n");
        scanf("%s",&heros[i].sex);
        fflush(stdin);      //¼���ַ���ǵ���ջ�����
        //���õ��û����飬�趨һ��ְҵ���飬���û�ѡ��
        printf("\n");
        for(j = 0; j < 5; j++)
        {
            printf("%d��%s\n",j+1,jobs[j].name);
        }

        printf("��ѡ��ְҵ��1-5֮�������");
        scanf("%d",&jobChoice);
        heros[i].job = jobs[jobChoice - 1];
        printf("%s��ǰ��ְҵ����%s��\n",heros[i].name,heros[i].name);
    }
}

void ShowHero()
{

}




