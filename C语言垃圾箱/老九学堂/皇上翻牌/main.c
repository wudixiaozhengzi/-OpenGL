#include <stdio.h>
#include <stdlib.h>
#include<string.h>  //支持字符串操作
#define MAX 6    //常量max表示系统要求的最大妃子数量

#include<windows.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")*/
int main()
{
    int i,j,temp;
    int searchIndex =-1;     //用来存放查找到元素的下标
    int count = 5;          //当前为打入冷空的嫔妃个数
    //字符数组表示字符串
    char emperorName[50];   //皇帝的名号
    int choice;     //皇帝的选择
    char names[MAX][10] = {"貂蝉","杨玉环","不知火舞","西施","亚丝娜"};
    //嫔妃的级别
    char levelnames[5][10] = {"贵人","嫔妃","贵妃","皇贵妃","皇后"};
    //用来存放每位妃子的级别，每个数组元素对应每个妃子的当前级别
    int levels[MAX] = {1,2,0,0,4,-1};
    //loves数组中的每个元素对应每个妃子的好感度，初始情况，每个人的好感度100
    int loves[MAX] = {100,100,100,100,100,-1};
    char tempname[20];  //用来存放临时字符串的字符数组
    printf("************************************************\n");
    printf("查看当前嫔妃的状态\n");
    printf("%-12s姓名\t级别\t好感度\n","姓名");
    printf("************************************************\n");
    for(i = 0; i < count; i++)
    {
        printf("%-12s%s\t%d\n",names[i],levelnames[levels[i]],loves[i]);     //levelnames[levels]数组套数
    }
 PlaySound(TEXT("sounds\\背景音乐.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
    printf("请输入当前登基皇帝的名号:\n");
    scanf("%s",emperorName);        //录入字符串
    printf("皇帝(%s),万岁万岁万万岁\n",emperorName);
    printf("1.皇帝下旨选妃：\t\t(增加功能)\n");//插入一个数值
    printf("2.翻牌宠幸：\t\t\t(修改状态功能)\n");
    printf("3.打入冷宫！\t\t\t(删除功能)\n");
    printf("4.单独召见爱妃去小树林批阅奏折\n");
    printf("陛下请选择：");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        //1.增加数组元素（names、loves、levels）
        //2.增加前需要判断数组还有没有空间
        if(count < MAX) //如果当前妃子数量小于系统最大值
        {
            //执行添加操作
            printf("请输入娘娘的名讳：");
            scanf("%s",names[count]);
            levels[count] = 0;
            loves[count] = 100;
            count++;
        }
        else
        {
            printf("陛下，要注意龙体啊，后宫已人满为患\n");
        }
        break;
    case 2:
        //1.找到要宠幸妃子的下标
        //2.修改这个妃子的状态   好感度+10，级别升1级，如果最高级就不再升级
        //3.修改其他妃子的状态   其他妃子好感度-10
        //需要解决的bug:为支持姓名不存在的情况
        printf("陛下请输入今天要翻牌娘娘的名讳：");
        scanf("%s",tempname);
        //字符串的查找strcmp，需要引入<string.h>
        //strcmp(tempname,"abc")  0-两个字符串相等；1-前一个大于后一个；-1-前一个小于后一个
        for(i = 0; i < count; i++)
        {
             if(strcmp(tempname,names[i])==0)   //如果输入的姓名刚好等于数组中的某个名字
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
        //1.查找
        //2.后面一个赋给前面一个元素
        //3.总数--
        //4.修改其他妃子的好感度
        printf("请输入要打入冷宫的娘娘的名讳：");
        scanf("%s",tempname);
        //循环查找
        for(i = 0; i < count; i++)
        {
            if(strcmp(tempname,names[i])==0)
            {
                searchIndex = i;
                break;
            }
        }
        if(-1 == searchIndex)   //没找到
        {
            printf("虚惊一场，无人打入冷宫\n");
        }
        else
        {
            for(i = searchIndex; i < count-1; i++)
            {
                //names[i] = name[i+1];字符数组c语言不支持数组的直接赋值
                //我们需要使用strcpy函数实现数组的赋值
                strcpy(names[i],names[i+1]);
                loves[i]  = loves[i+1];
                levels[i] = levels[i+1];
            }
        count--;
        }
        break;
    case 4:
        //1.查找
        //2.增加好感度
        //3.可以使用数组设计诗歌，使用随机数字的方式，表现皇帝的文采
        printf("4.单独召见爱妃去小树林批阅奏折\n");
        break;
    defualt:
        printf("君无戏言，请陛下再选");
    }
    //最后打印所有妃子的状态前，以级别进行排序
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
    printf("查看当前嫔妃的状态\n");
    printf("%-12s级别\t好感度\n","姓名");
    printf("************************************************\n");
    for(i = 0; i < count; i++)
    {
        printf("%-12s%s\t%d\n",names[i],levelnames[levels[i]],loves[i]);     //levelnames[levels]数组套数
    }


    printf("Hello world!\n");

    return 0;
}











