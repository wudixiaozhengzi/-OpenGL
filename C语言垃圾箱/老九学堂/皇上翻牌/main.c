#include <stdio.h>
#include <stdlib.h>
#include<string.h>  //֧���ַ�������
#define MAX 6    //����max��ʾϵͳҪ��������������

#include<windows.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")*/
int main()
{
    int i,j,temp;
    int searchIndex =-1;     //������Ų��ҵ�Ԫ�ص��±�
    int count = 5;          //��ǰΪ������յ���������
    //�ַ������ʾ�ַ���
    char emperorName[50];   //�ʵ۵�����
    int choice;     //�ʵ۵�ѡ��
    char names[MAX][10] = {"����","����","��֪����","��ʩ","��˿��"};
    //�����ļ���
    char levelnames[5][10] = {"����","����","����","�ʹ���","�ʺ�"};
    //�������ÿλ���ӵļ���ÿ������Ԫ�ض�Ӧÿ�����ӵĵ�ǰ����
    int levels[MAX] = {1,2,0,0,4,-1};
    //loves�����е�ÿ��Ԫ�ض�Ӧÿ�����ӵĺøжȣ���ʼ�����ÿ���˵ĺøж�100
    int loves[MAX] = {100,100,100,100,100,-1};
    char tempname[20];  //���������ʱ�ַ������ַ�����
    printf("************************************************\n");
    printf("�鿴��ǰ������״̬\n");
    printf("%-12s����\t����\t�øж�\n","����");
    printf("************************************************\n");
    for(i = 0; i < count; i++)
    {
        printf("%-12s%s\t%d\n",names[i],levelnames[levels[i]],loves[i]);     //levelnames[levels]��������
    }
 PlaySound(TEXT("sounds\\��������.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
    printf("�����뵱ǰ�ǻ��ʵ۵�����:\n");
    scanf("%s",emperorName);        //¼���ַ���
    printf("�ʵ�(%s),��������������\n",emperorName);
    printf("1.�ʵ���ּѡ����\t\t(���ӹ���)\n");//����һ����ֵ
    printf("2.���Ƴ��ң�\t\t\t(�޸�״̬����)\n");
    printf("3.�����乬��\t\t\t(ɾ������)\n");
    printf("4.�����ټ�����ȥС������������\n");
    printf("������ѡ��");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        //1.��������Ԫ�أ�names��loves��levels��
        //2.����ǰ��Ҫ�ж����黹��û�пռ�
        if(count < MAX) //�����ǰ��������С��ϵͳ���ֵ
        {
            //ִ����Ӳ���
            printf("��������������䣺");
            scanf("%s",names[count]);
            levels[count] = 0;
            loves[count] = 100;
            count++;
        }
        else
        {
            printf("���£�Ҫע�����尡����������Ϊ��\n");
        }
        break;
    case 2:
        //1.�ҵ�Ҫ�������ӵ��±�
        //2.�޸�������ӵ�״̬   �øж�+10��������1���������߼��Ͳ�������
        //3.�޸��������ӵ�״̬   �������Ӻøж�-10
        //��Ҫ�����bug:Ϊ֧�����������ڵ����
        printf("�������������Ҫ������������䣺");
        scanf("%s",tempname);
        //�ַ����Ĳ���strcmp����Ҫ����<string.h>
        //strcmp(tempname,"abc")  0-�����ַ�����ȣ�1-ǰһ�����ں�һ����-1-ǰһ��С�ں�һ��
        for(i = 0; i < count; i++)
        {
             if(strcmp(tempname,names[i])==0)   //�������������պõ��������е�ĳ������
             {
                 loves[i] += 10;
                 levels[i] = levels[i] >= 4 ? 4 : levels[i] + 1;
             }
             else
             {
                 loves[i] -= 10;
             }
        }

        break;
    case 3:
        //1.����
        //2.����һ������ǰ��һ��Ԫ��
        //3.����--
        //4.�޸��������ӵĺøж�
        printf("������Ҫ�����乬����������䣺");
        scanf("%s",tempname);
        //ѭ������
        for(i = 0; i < count; i++)
        {
            if(strcmp(tempname,names[i])==0)
            {
                searchIndex = i;
                break;
            }
        }
        if(-1 == searchIndex)   //û�ҵ�
        {
            printf("�龪һ�������˴����乬\n");
        }
        else
        {
            for(i = searchIndex; i < count-1; i++)
            {
                //names[i] = name[i+1];�ַ�����c���Բ�֧�������ֱ�Ӹ�ֵ
                //������Ҫʹ��strcpy����ʵ������ĸ�ֵ
                strcpy(names[i],names[i+1]);
                loves[i]  = loves[i+1];
                levels[i] = levels[i+1];
            }
        count--;
        }
        break;
    case 4:
        //1.����
        //2.���Ӻøж�
        //3.����ʹ���������ʫ�裬ʹ��������ֵķ�ʽ�����ֻʵ۵��Ĳ�
        printf("4.�����ټ�����ȥС������������\n");
        break;
    defualt:
        printf("����Ϸ�ԣ��������ѡ");
    }
    //����ӡ�������ӵ�״̬ǰ���Լ����������
    for(i = 0; i< count-1; i++)
    {
        for(j = 0; j < count-1-i; j++)
        {
            if(levels[j] < levels[j+1])
            {
                temp = levels[j];
                levels[j] = levels[j+1];
                levels[j+1] = temp;

                temp = loves[j];
                loves[j] = loves[j+1];
                loves[j+1] = temp;

                strcpy(tempname,names[j]);
                strcpy(names[j],names[j+1]);
                strcpy(names[j+1],tempname);
            }
        }
    }


    printf("************************************************\n");
    printf("�鿴��ǰ������״̬\n");
    printf("%-12s����\t�øж�\n","����");
    printf("************************************************\n");
    for(i = 0; i < count; i++)
    {
        printf("%-12s%s\t%d\n",names[i],levelnames[levels[i]],loves[i]);     //levelnames[levels]��������
    }


    printf("Hello world!\n");

    return 0;
}











