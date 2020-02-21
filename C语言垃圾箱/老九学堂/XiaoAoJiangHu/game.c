
#include <stdio.h>
#include <unistd.h>
#include "Game.h"
#include "GameLib.h"

/* ��ǰ����Ϸ״̬ */
enum GameStatus CurrGameStatus = GameSplashScreen;

char Maps[8][8][10] = {
    {"��ɽ",   "¥��",   "����ɽ",  "Ұ����",   "ˮ����",  "��϶�",  "�ڷ�կ",   "����"},
    {"�Թ�",   "������",  "��ԯ��", "��ɽ",     "��ɽ",    "�Ͻ���",  "�����",   "������"},
    {"����",   "��«��",  "����",   "����ɽ",   "ʯ��",    "��ջ",    "��ʶ�",   "���ߵ�"},
    {"������", "Ħ����",  "����ׯ", "��ɽ",     "�䵱ɽ",  "���⸮",  "��ʮ����", "�����ɾ�"},
    {"�޹�ɽ", "��üɽ",  "������", "�廢��",   "������",  "������",  "�򽭸�",   "�һ���"},
    {"���˹�", "����",    "�ٻ���", "��ȸɽׯ", "��Ը�",  "������",  "ǧ���ɲ", "������"},
    {"��żׯ", "��ľ��",  "������", "������",   "������",  "�ص���",  "����ׯ",   "���깬"},
    {"ʯ��",   "������",  "�����", "ͨ�Ե�",   "ͨ���",  "��ϼͤ",  "������",   "���͵�"}
};
/* �������� */
Martial martials[] ={
    {1, "������",   "����", .hqCoord.X=1, .hqCoord.Y=4, 1, "�л���ѧ��̩������ĩ�������ڶ���˲��У�����պͼ��������Ϊһ�ȡ����У���ճ���Ϊɮ���������׼ҵ��ӡ���ʱ�����˳�����˫��������������ɮ�������ϵĴ����²μ��˽����غ��������ܵ�ս�����ڸ�·Ӧļ�����б��ֵ���Ϊ���¡���������֮�£�Ҳʹ�����е��ڶ����ɲ�����ì�ܣ������������ֺ�������̡���ա����������ȴ��콭��ͬ�ʹ��Ϲ�������������������̺�Ѫ�����ɽ�Ϊͬ�ˣ����ο�а���и������ƣ����Լ���Χ��δ�����գ��ڰ���������ʧ����"},
    {2, "�䵱��",   "����", .hqCoord.X=3, .hqCoord.Y=4, 1, "�䵱�ڽ������������������С��������֡��������䵱��֮˵�� �䵱��һ�������������һλǫǫ���ӣ�һ�������������������Ǵ���ˬ�ʵ�Ц�ݣ��������ĳ�ж����ܲ������������ټ������Ӻ������˴�ʮ�������𽭺�������С��ʮ��ս�������δ�ܹ�һ�Ρ�����һ����������ܵ������¾���ʧ�ܺʹ��� "},
    {3, "ؤ��",     "����", .hqCoord.X=2, .hqCoord.Y=6, 1, "ؤ������ԭ������������Ϊ�ڶ��һ�����ɣ�Ҳ�����µ�һ����ɣ��Ա鲼������ؤ����ؤ��ɣ���Ϊ���°�;��°ؤ�����˴�඼������λ�Ƚϵ͵��ˣ������Ǹ�����Ӳ�ǣ�Ʒ����У����ٳ��ֱ���֮�ˡ�ؤ����һ���ڶ���������Ϊ�ף������������������塢��ǿ������������ΪΪ������������ֵ���"},
    {4, "ȫ���",   "����", .hqCoord.X=2, .hqCoord.Y=3, 1, "ȫ�����ڵ��̵ķ�֧֮һ���ֽ�ȫ���������Ȩ��������һ������СС���ˣ�����һ˫���䵭��������Զ������ʲô�仯���۾����������·��ǻ�ɫ�ġ���������һ���ǳ��������ˣ���ϲ����ɫ��ϲ��������˻������ƣ�ϲ�����ܡ���ÿһ�����������ǳ������ޣ�����ÿһ���¶��������ܼƻ��������϶��˷�һ��������Ҳ������һ������������ȫ�溣�š�"},
    {5, "��������", "����", .hqCoord.X=1, .hqCoord.Y=3, 1, "̩ɽ�ɣ���ɽ�ɣ���ɽ�ɣ���ɽ�ɣ���ɽ�ɽ�Ϊͬ��֦���ĵ��������ɣ��ڽ���������������������һ������Ĳ��ͣ��������ɵ�ʽ΢��������������֣����������ڲ�ì�ܼ��������ںĵĽ�����ڲ��Ĺ��Ķ�����Ȼ�����Կ���Ϊ��ڳ��֣�ʵ����Ϊ������������ɱ��Ȩ��"},
    {6, "�Ĵ�����", "����", .hqCoord.X=2, .hqCoord.Y=2, 1, "�����ڽ������԰������������Դ����ŵ�����̫̫�������Ƽұ�һ�ȼҵ����䣬��֮����Ϊ�ư����������������ʹ�����������ٶȵĺƽ٣�����һ�겻��������Σ�ѵ�ʱ�����ų�����һȺ������������磡���ն����ȱ�������������������������������˿︴������������ģ������ڽ������������壬��������ŵ�������ʹ���ų�Ϊ�˽����ϵ��������ɡ�"},
    {7, "�������", "����", .hqCoord.X=5, .hqCoord.Y=1, 1, "��������˶��ڶ࣬�������ơ�������һλ���ｭ������Ů��������ѩ������ѩ���������㣬��ɫ��𪣬��΢������������ȥ��������ȴ�������书������ô����书�ĵá�"},
    {8, "��ɽ��",   "����", .hqCoord.X=0, .hqCoord.Y=0, 1, "��ɽ�����������ɣ�Ҳ��Ŀǰ��������Ϊ�Ž��һ�����ɡ���ɽ��Ҳ�ǽ�����Ů������Ϊ�ڶ��һ�����ɣ��Ҹ����书���費������ò���㡣"},
    {9, "��Ĺ��",   "����", .hqCoord.X=3, .hqCoord.Y=3, 1, "��Ĺ����һ���Ĵ���������������һŮ�ӣ�������������������浾������࿡������ֹƮ�ݣ���������ȴ����ʦ��С��Ů��������һ������ķ���书��Ϊ��ɲ⣬ͬ��ϲ�����¡������Ṧ׿Խ��������ȭ���鶯���������ȫ��̵Ŀ��ǡ���Ĺ���˵Ĵ���ԭ���ǡ��²��ؼ����߸߹��𡱣������������������ӣ������������ð���˹�Ĺ���ˣ�����һ�������úܲҡ�"},
    {10, "������",  "����", .hqCoord.X=1, .hqCoord.Y=1, 1, "������������ٸ���������Ҳ�����ڽ����ϴ������õ����ָ��֡�������һ��һ���˲�����һλ�ºŽС����������ģ����˴Ӳ�������Ŀ���ˣ�������Ļ��߻�һЩ���顣"},
    {11, "�������","а��", .hqCoord.X=6, .hqCoord.Y=1, 1, "���ڸý̸����ڶ࣬���˴˻�����������Խ�����ӡ����е��Ӷ�Ϊа��֮ͽ��ר�������������ԣ�ɱ�����࣬������ã��ʱ���������֮�˱�Ϊħ�̡�"},
    {12, "Ȩ����",  "а��", .hqCoord.X=4, .hqCoord.Y=0, 1, "а��֮һ��Ŀǰ�����������Ϊһ�а��ɵ������ˡ����ɣ�һ���������쳣��㨵��ˡ�û�����佻���ֵ����ָ��֣��޷������������������������������ô���Ǳ�����������������������֧����Ȩ����ĵ��ӵġ�"},
    {13, "�嶾��",  "а��", .hqCoord.X=2, .hqCoord.Y=0, 1, "һ����ʹ��Ϊר�������ɣ������˸��������ö����֡����ɸ����˳����ʣ�����ʹ�����뻯��������������ĥ������ͬ������Ī���Ƶ����С�����Ʒ��ʱ��ʱ����������׿��������ɳա�"},
    {14, "������",  "а��", .hqCoord.X=2, .hqCoord.Y=7, 1, "�������ǽ���а�ɣ����ڽ�ַԶ����ԭ�����Բ����Ԥ��ԭ���ֵ�Ѫ��ɱ¾��Ŀǰ����������λ����һΪ���񣬴����书����Ī�⣬�Ը��Ƨ�������ϲ���˽ӽ�����Ϊ�������书��ǿ��Ƣ�����꣬����û�����ԡ�"},
    {15, "������",  "а��", .hqCoord.X=5, .hqCoord.Y=6, 1, "�����������������һ��������֯���������·�ʮ���ã��ֱ�����Ϊ���š�"},
    {16, "�һ���",  "������а", .hqCoord.X=4, .hqCoord.Y=7, 1, "�ԴӶ�а��ҩʦ���������ڴ˺����Ĵ��˾����������Ӳ����������һ������������ɵ��ܶ档�һ�����ҩʦ�Ĺ��ŵ��ӳ�Ӣһ��δ�ޣ��ڵ������˼���ͽ�ܣ��һ������书��˵õ������ͷ��"},
    {17, "������",  "������а", .hqCoord.X=1, .hqCoord.Y=5, 1, "���ڽ��������˲żüã����������񣬴���Ұ�Ĳ�������������һ�������չ����ųƵ�ǹ���룬�书ʵ����ɲ⡣����Ϊ�˻��ǣ���ͨ�������б�ʱ�ܽ�ǧ��������ʹ����ͬ��ʮ�������ʮ�㡣"},
    {18, "Ѫ����",  "������а", .hqCoord.X=5, .hqCoord.Y=0, 1, "�Դ�Ѫ���ɵ�����һ������������ƮȻ��ȥ��Ѫ��������˥�䡣Ѫ���ɻ�ķ�ΧҲԽ��Խ�٣�������ֻ��������ʯ�ߡ��������ϵľŴ������Ѿ���Ѫ������Ϊаħ��������Ѵ���Ӣ���ֻҪ�Ŵ����ɵ���������Ѫ���ɵ��ˣ�һ�ɸ�ɱ���ۡ��ڽ������Ѿ�û��ʲôѪ���ɵ��������ߡ������޺ޣ�û����֪�������Ժη�������ֻ֪��������Ѫ���ɡ�û����֪�������书�ж�ߣ���Ϊ�������Ľ����˶��Ѿ�......�޺��������е�һ���գ�����������ɽ���ഫ��Ϊ��һ����������Ů�ӡ��ഫѪ�ӵ��ӻ���ȱ������޺��洫�����޺����ӽ����ڼ����Ѫ�ӵ�һ�а������񡣻���ȱΪ��������ϣ��ڽ�������Ե���ã�����Ѫ���������������þ���������"},
    {19, "ͨͨ��",  "������а", .hqCoord.X=7, .hqCoord.Y=3, 1, "������һ�����ص����ɣ���ʼ�ˣ��书���顣�ܶ�����ͨ�Ե�����������������Ժ��������ֶ��Ͽᣬ�������ˡ�ƽ��������̤����ԭ���֣�Ǳ�������书��"},
    {20, "��żɽׯ","������а", .hqCoord.X=0, .hqCoord.Y=6, 1, "������һ�����ص����ɣ���ʼ�ˣ��书���顣�ܶ������żɽׯ������������������⡣��żɽׯ�����ڶ࣬���󶼾���������ֻ�����⾭�������˼����������������ã������������˲�֪����ôһ�����ɴ��ڡ�"}
};
/* ��Ϸ�еĹ��� */
Monster monsters[] = {
    {1, "����", 1, 100, 5, 5, 1, 3, 10, 1, .mCoord.X=0, .mCoord.Y=0},
    {1, "����", 1, 100, 5, 5, 1, 3, 10, 1, .mCoord.X=0, .mCoord.Y=1},
    {1, "����", 1, 100, 5, 5, 1, 3, 10, 1, .mCoord.X=0, .mCoord.Y=2},
    {1, "����", 1, 100, 5, 5, 1, 3, 10, 1, .mCoord.X=0, .mCoord.Y=3},
    {1, "����", 1, 100, 5, 5, 1, 3, 10, 1, .mCoord.X=0, .mCoord.Y=4},
    {1, "����", 1, 100, 5, 5, 1, 3, 10, 1, .mCoord.X=0, .mCoord.Y=5},
    {1, "����", 1, 100, 5, 5, 1, 3, 10, 1, .mCoord.X=0, .mCoord.Y=6},
    {1, "����", 1, 100, 5, 5, 1, 3, 10, 1, .mCoord.X=0, .mCoord.Y=7},
    {2, "����", 2, 200, 8, 12, 1, 8, 11, 1, .mCoord.X=0, .mCoord.Y=0},
    {2, "����", 2, 200, 8, 12, 1, 8, 11, 1, .mCoord.X=0, .mCoord.Y=1},
    {2, "����", 2, 200, 8, 12, 1, 8, 11, 1, .mCoord.X=0, .mCoord.Y=2},
    {2, "����", 2, 200, 8, 12, 1, 8, 11, 1, .mCoord.X=0, .mCoord.Y=3},
    {2, "����", 2, 200, 8, 12, 1, 8, 11, 1, .mCoord.X=0, .mCoord.Y=4},
    {2, "����", 2, 200, 8, 12, 1, 8, 11, 1, .mCoord.X=0, .mCoord.Y=5},
    {2, "����", 2, 200, 8, 12, 1, 8, 11, 1, .mCoord.X=0, .mCoord.Y=6},
    {2, "����", 2, 200, 8, 12, 1, 8, 11, 1, .mCoord.X=0, .mCoord.Y=7},
    {3, "����", 3, 300, 10, 10, 3, 8, 20, 1, .mCoord.X=0, .mCoord.Y=0},
    {3, "����", 3, 300, 10, 10, 3, 8, 20, 1, .mCoord.X=0, .mCoord.Y=1},
    {3, "����", 3, 300, 10, 10, 3, 8, 20, 1, .mCoord.X=0, .mCoord.Y=2},
    {3, "����", 3, 300, 10, 10, 3, 8, 20, 1, .mCoord.X=0, .mCoord.Y=3},
    {3, "����", 3, 300, 10, 10, 3, 8, 20, 1, .mCoord.X=0, .mCoord.Y=4},
    {3, "����", 3, 300, 10, 10, 3, 8, 20, 1, .mCoord.X=0, .mCoord.Y=5},
    {3, "����", 3, 300, 10, 10, 3, 8, 20, 1, .mCoord.X=0, .mCoord.Y=6},
    {3, "����", 5, 300, 10, 10, 3, 8, 20, 1, .mCoord.X=0, .mCoord.Y=6},
    {3, "����", 6, 300, 10, 10, 3, 8, 20, 1, .mCoord.X=0, .mCoord.Y=6},
    {3, "����", 7, 300, 10, 10, 3, 8, 20, 1, .mCoord.X=0, .mCoord.Y=6},
    {3, "����", 8, 300, 10, 10, 3, 8, 20, 1, .mCoord.X=0, .mCoord.Y=6},
    {3, "����", 9, 300, 10, 10, 3, 8, 20, 1, .mCoord.X=0, .mCoord.Y=6},
    {3, "����", 9, 300, 10, 10, 3, 8, 20, 1, .mCoord.X=0, .mCoord.Y=6},
    {3, "����", 9, 300, 10, 10, 3, 8, 20, 1, .mCoord.X=0, .mCoord.Y=6},
    {3, "����", 9, 30000, 10, 10, 3, 8, 20, 1, .mCoord.X=0, .mCoord.Y=6}
};
/* ��Ϸ���� */
Prop props[] ={
    {1, "һ�ֳ��߽�", 1, Weapon, 50, .attack=5, 1000, "�����������������������"},
    {2, "������ˮ��", 2, Weapon, 10, .attack=10, 2000, "�߶ȵ�����ԣ������ޱȣ�"},
    {3, "���溣���", 3, Weapon, 10, .attack=15, 3000, "�ش�ʮ���ǧ��������"},
    {4, "�ķ�������", 4, Weapon, 10, .attack=20, 4000, "����������������Ϊ��ԭ���ֵ�һ���ɺͷ��Ź�صĳ�ߵ�λ��"},
    {5, "�廢����", 5, Weapon, 10, .attack=25, 5000, "Ψ������Ԫ�ع�ͨ���˿��Ի�����������������"},
    {6, "����ӭ��ǹ", 6, Weapon, 10, .attack=30, 6000, "��������������ڶ�����һ��С������ķɵ���"},
    {7, "����ն��ì", 7, Weapon, 10, .attack=40, 7000, "ì������������ţ�����н��ŷ�ɥ����������"},
    {8, "���Խ�����", 8, Weapon, 10, .attack=50, 8000, "�������ϣ��·��ǻ�Ӱ���������ձ��죡"},
    {9, "��תǬ��Ȧ", 9, Weapon, 10, .attack=90, 10000, "��ɫ���ӣ��ɷ�����������Ǭ����"},
    {100, "��аϬ", 1, Armor, 10, .defense=5, 1000, "һ���ܽ����°ٶ���͸������"},
    {101, "�ڲ�ȹ", 2, Armor, 10, .defense=15, 2000, "������ͣ���ǹ���룬ˮ���֣�"},
    {102, "Ӣ�˴�", 3, Armor, 10, .defense=20, 3000, "��������������ɷ����̬Ӣ�����磡"},
    {103, "���ָ", 4, Armor, 10, .defense=25, 4000, "Ʈ����������������������������"},
    {104, "������", 5, Armor, 10, .defense=30, 5000, "����Ƥ�Ƴɣ�װ�������ˮ�º�����"},
    {105, "������", 6, Armor, 10, .defense=40, 6000, "��׫���Ϲ��ϻ���ȸ֮��,�����֣�"},
    {106, "������", 7, Armor, 10, .defense=45, 7000, "װ�����������֮�Ӹ���ȫ����������"},
    {107, "������", 8, Armor, 10, .defense=60, 8000, "�������֡��Ӽұر���"},
    {108, "��⬼�", 9, Armor, 10, .defense=70, 10000, "��ǹ���뻹�ɱ�ů���������ϣ���������һ�������֮����"},
    {201, "�ظ���ƿ(��)", 1, Consumables, 50, .power=500, 2000, "һ���Իظ�500������ֵ��"}
};

Player players[] = {
    {9526, "gm1", "gm1", 5, 1, 1, 10000, 30000, 1000, 10000, .currCoord.X=0, .currCoord.Y=0},
    {9527, "����", "an.hua", 5, 8, 1, 1000000, 300000, 99999, 1000000, .currCoord.X=2, .currCoord.Y=2}
};
Player *currPlayer;
//������ڵ�ͼ���꣨X-�У�Y-�У����������������෴
int X = 1, Y = 4;

void Show()
{
    //�趨��ɫ
    //system("cls");
    switch(CurrGameStatus)
    {
    case GameMainMenu:
        ShowMenu();break;
    case GameSplashScreen:
        ShowSplash();break;
    }
}
void ShowMenu()
{
    printf("��ʾ��Ϸ���˵�\n");
}
void ShowSplash()
{
    printf("��ʾ��Ϸ��ӭ����\n");
}
void InitializeGame()
{

    //��ʼ���������
    //��ʼ����������
    players[0].martial = martials[1];
    players[0].weapon = props[0];
    players[0].armor = props[9];
    players[1].martial = martials[3];
    players[1].weapon = props[8];
    players[1].armor = props[14];

    Bag bag = {9527, 0, 8};
    currPlayer = &players[1];
    currPlayer->bag = bag;
}

void ShowMap()
{
    Clear(MARGIN_X, 3);
    //��ͼ����ʼλ�ù̶�ΪMARGIN_X, 3
    int i = 0, j = 0;
    char * martialIntro = NULL;//���ɽ���
    for(; i < 8; i++)
    {
        SetPosition(MARGIN_X, 3 + i);
        printf("|  ");
        for(j = 0; j < 8; j++)
        {
            if(i == X && j == Y){
                SetColor(13, 15);
            }else{
                SetColor(10, 0);
            }
            printf("%-9s", Maps[i][j]);
            SetColor(10, 0);
        }
        printf(" |\n");
    }
    SetPosition(MARGIN_X, 11);
    printf("-----------------------------------------------------------------------------\n");
    //��ʾ������Ϣ-���ݵ�ǰ��ͼ���꣬��Ӧ����
    Martial *currMartial = NULL;
    for(i = 0; i < 20; i++)
    {
        if(X == martials[i].hqCoord.X && Y == martials[i].hqCoord.Y)//�����ܲ������뵱ǰ����������ʱ
        {
            currMartial = &martials[i];
            martialIntro = martials[i].description;
            break;
        }
    }
    if(martialIntro == NULL)
    {
        SetPosition(MARGIN_X, 12);
        printf("\t\t\t\t<%s>", Maps[X][Y]);
        SetPosition(MARGIN_X, 13);
        printf("\t\t\t�˵ع�ͺͺ�ģ��д����裡");
        return;
    }
    j = 0;
    SetPosition(MARGIN_X, 12);
    if(currMartial != NULL)
        printf("\t\t\t\t<%s>  �ܶ�", currMartial->name);
    else
    {
        SetPosition(MARGIN_X, 18) ;
        return;
    }
    int length = strlen(martialIntro);
    if(length > 500) length = 500;
    for(i = 0; i < length; i++)
    {
        if(i % 72 == 0)
        {
            SetPosition(MARGIN_X + 2, 13 + i / 72);
        }
        printf("%c", *(martialIntro + i));

    }

}
void ShowPlayer()
{
    //printf("����\t����\t����\t����\t����\n");
    //printf("%s\t%d\t%s\t%s\t%s\n", players[0].name, players[0].level, players[0].martial.name, players[0].weapon.name, players[0].armor.name);
    ClearMessage();
    //����궨λ����Ϣ��ʾ���Ŀ�ʼ
    SetPosition(MARGIN_X, 12);
    int SEP = 10;
    //printf("��Ϣ��ʾ��");
    SetPosition(MARGIN_X  + SEP, 12);
    //Player test = currPlayer;
    printf("���ĸ����������£�");
    SetPosition(MARGIN_X  + SEP, 13);
    printf("��ţ�%d\t������%s\t����%d\t\t����ֵ��%d", currPlayer->id, currPlayer->name, currPlayer->level, currPlayer->exp);
    SetPosition(MARGIN_X  + SEP, 14);
    printf("���ɣ�%s\tH  P��%d\t������%d\t��ң�%d", currPlayer->martial.name, currPlayer->hp, currPlayer->mp, currPlayer->gold);
    SetPosition(MARGIN_X  + SEP, 15);
    printf("������%s(%d��/����%d)\t", currPlayer->weapon.name, currPlayer->weapon.level, currPlayer->weapon.attack);
    printf("���ߣ�%s(%d��/����%d)\t", currPlayer->armor.name, currPlayer->armor.level, currPlayer->armor.defense);
    SetPosition(MARGIN_X  + SEP, 16);
    printf("������Ϣ��");
    SetPosition(MARGIN_X  + SEP, 17);
    if(currPlayer->bag.propCount == 0)
    {
        printf("��ǰ�����յ����ģ����߽���ҪС��Ŷ0^0");
        return;
    }
    int i;
    for(i = 0; i < currPlayer->bag.propCount; i++)
    {
        if(i != 0 && i % 4 == 0 )
        {
            SetPosition(MARGIN_X  + SEP, 17 + i / 4);
        }
        printf("%-12s(%-2d)", currPlayer->bag.props[i].name, currPlayer->bag.props[i].stock);
    }

}
void ShowMonster()
{
    int SEP = 10;
    int i;
    //��Ӧ9������ļ�����
    char * levelNames[9] = {"���δ��", "����é®", "��ͨƤë", "����ſ�", "����С��", "�������", "�������", "�����޵�", "���˺�һ"};
    ClearMessage();
    //����궨λ����Ϣ��ʾ���Ŀ�ʼ
    SetPosition(MARGIN_X, 12);
    printf("��ǰ��ͼ�Ĺ��");
    SetPosition(MARGIN_X, 14);
    //�����������飬�ҵ����и����������ͬ�Ĺ���
    int monsterCount = sizeof(monsters)/ sizeof(Monster);
    int monsterIndex[9];//���9������
    int currCount = 0;//��ǰ��ͼ�Ĺ�������
    for(i = 0; i < monsterCount; i++)
    {
        if(X == monsters[i].mCoord.X && Y == monsters[i].mCoord.Y && monsters[i].state != 0)
        {
            //��ʾ����
            printf("%d.%s(%s)\t\t", currCount + 1, monsters[i].name, levelNames[monsters[i].level - 1]);
            monsterIndex[currCount] = i;
            currCount++;
            if(currCount == 9) break;
            if(currCount % 3 == 0)
            {
                SetPosition(MARGIN_X, 14 + currCount / 3);
            }
        }
    }
    if(currCount == 0)
    {
        SetPosition(MARGIN_X + SEP, 14);
        printf("���Ǽ�����������ʺ�ĵط�������û�������ˣ����¸���ͼȥ�ɡ�");
        return;
    }

    int choice;
    do{
        SetPosition(MARGIN_X, 18);
        printf("��ѡ��Ҫ�����Ķ���(��0����):");
        scanf("%d", &choice);
        if(choice < 0 || choice > currCount){//�û��������ʱ��ձ���
            SetPosition(MARGIN_X, 18);
            printf("                                          ");
        }
    }while(choice < 0 || choice > currCount);
    if(choice == 0)
        return;
    SetPosition(MARGIN_X, 18);
    ShowFight(NULL, &monsters[monsterIndex[choice-1]]); //���ù�����������ʾս�����

}
void ShowFight(Player *player, Monster *monster)
{
    SetPosition(MARGIN_X, 18);
    printf("                                          ");
    SetPosition(MARGIN_X, 18);
    int count = 0;
    do
    {
        //���ÿ�ι�����Ҫ�ķ�10*������������ֵ
        monster->hp -= currPlayer->weapon.attack;
        currPlayer->hp -= monster->att;

        currPlayer->mp -= 10 * currPlayer->weapon.attack;
        if(currPlayer->mp <= 0)
        {
            SetPosition(MARGIN_X, 18);
            printf("                                                           ");
            SetPosition(MARGIN_X, 18);
            printf("��ǰ������͸֧����������Ҫ����");
            return;
        }
        SetPosition(MARGIN_X, 18);
        printf("                                          ");
        SetPosition(MARGIN_X, 18);
        printf("ս����%d�֣�%sHP-%d\t%sHP-%d",count + 1, currPlayer->name, currPlayer->hp, monster->name, monster->hp);
        count++;
        usleep(1000 * 50);//50����
    }while(currPlayer->hp > 0 && monster->hp > 0 && currPlayer->mp > 0);
    SetPosition(MARGIN_X, 18);
    printf("                                          ");
    SetPosition(MARGIN_X, 18);
    if(currPlayer->hp <= 0)
    {
        printf("������Ѷ��������%s�����롶%s����ս����׳��������(�����������)", currPlayer->name, monster->name);
        return;
    }
    currPlayer->exp += monster->exp;
    currPlayer->gold += monster->maxMoney;
    monster->state = 0;
    printf("��������ս����%s����ɱ�������%d���飬%d��ң�", monster->name, monster->exp, monster->maxMoney);
    system("pause");
    ShowMonster();
}
void ShowHQ()
{
    X = currPlayer->martial.hqCoord.X;
    Y = currPlayer->martial.hqCoord.Y;
    ShowMap();
}
void ShowTrade()
{
    ClearMessage();
    //����Ϣ����ӡ�̵����Ʒ
    int propCount = sizeof(props) / sizeof(Prop) >= 15 ? 15 : sizeof(props) / sizeof(Prop);
    int i;
    SetPosition(MARGIN_X, 12);
    printf("��ӭ���롶%s�����ߵ꣺", Maps[X][Y]);
    SetPosition(MARGIN_X + 4, 13);
    for(i = 0; i < propCount; i++)
    {
        if(i % 3 == 0)
        {
            SetPosition(MARGIN_X + 4, 13 + i / 3);
        }
        printf("%-3d.%-10s(%-2d)%-4c", props[i].id, props[i].name, props[i].stock, ' ');
    }
    //�û�ѡ����н���
    SetPosition(MARGIN_X, 18);
    printf("�����빺��ĵ��߱�ţ�(��0�˳�)");
    int tradeId;
    scanf("%d", &tradeId);
    if(tradeId == 0)
    {
        ShowMap();
        return;
    }
    //�����жϣ��۳���漰��ҽ�Ǯ
    //������ұ���
    SetPosition(MARGIN_X, 18);
    Trade(currPlayer, tradeId);
    ShowTrade();
}
void StartNewGame(){}    //��������Ϸ
void EndGame(){}        //������Ϸ

void Process(char key)
{
    switch(key)
    {
    case '1'://1����������
        ShowPlayer();
        break;
    case '2'://2��̽��(���)
        ShowMonster();
        break;
    case '3'://3�����ܲ�
        ShowHQ();
        break;
    case '4'://4������װ��
        ShowTrade();
        break;
    case '5'://5����Ŀ����(�����)
        break;
    case '6'://6������һ��(�����)
        break;
    }
}
int Trade(Player *player, int propId)
{
    int i;
    //��Ҫ�жϣ���Ʒ�Ŀ�棬�������������ұ����ռ乻����
    Prop *tradeProp = NULL;//Ҫ�������Ʒָ��
    int propCount = sizeof(props) / sizeof(Prop);
    for(i = 0; i < propCount; i++)
    {
        if(propId == props[i].id){
            tradeProp = &props[i];//tradeProp = props + i;
            break;
        }
    }

    if(i == propCount)
    {
        printf("��Ʒ�������������������룡");
        system("pause");
        return 0;
    }
    if(tradeProp->stock <= 0)
    {
        printf("�����Ҷ�û���������̵궼���������");
        system("pause");
        return 0;
    }
    if(player->gold < tradeProp->price)
    {
        printf("Ǯ�����Ǳ�ģ�������ǿ�Ǯ����ᣡ��");
        system("pause");
        return 0;
    }
    if(player->bag.propCount >= player->bag.propMax && player->bag.propCount != 0)
    {
        printf("��������������ʧ�ܣ�");
        system("pause");
        return 0;
    }
    //���㽻��������ִ�н��׵�ҵ�����
    //1����Ʒ���-1
    tradeProp->stock--;
    //2����ҽ��-��Ʒ����
    player->gold -= tradeProp->price;
    //*3����ұ�����������
    //�ж���ұ������Ƿ����и���Ʒ

    //����и���Ʒ�������еĸ���Ʒ����+1
    for(i = 0; i < player->bag.propCount; i++)
    {
        //���Ҫ�������Ʒid �� �����е�ĳ����Ʒid��ͬ
        if(propId == player->bag.props[i].id)
        {
            player->bag.props[i].stock++;
            break;
        }
    }
    if(i == player->bag.propCount)//���û�и���Ʒ������Ʒ��ӵ������м���
    {
        //�򱳰��д���һ����Ʒ-����һ��Ҫ���׵���Ʒ��Ϣ��������
        int newIndex = player->bag.propCount;
        player->bag.props[newIndex].id = tradeProp->id;
        player->bag.props[newIndex].price = tradeProp->price;
        player->bag.props[newIndex].stock = 1;
        strcpy(player->bag.props[newIndex].name, tradeProp->name);
        strcpy(player->bag.props[newIndex].desc, tradeProp->desc);
        player->bag.propCount++;
    }
    return 1;
}
void ProcessMenu(){}
void ProcessSplash(){}
void ProcessGame(){}
void ProcessExit(){}

void ShowGame(){}
void ShowExit(){}
