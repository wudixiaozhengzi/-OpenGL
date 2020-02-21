#include <iostream>


#include <math.h>
#include<string.h>
 #include<ctype.h>
 #include<stdio.h> /* EOF(=^Z或F6),NULL */
#include<stdlib.h> /* atoi() */
 #include<io.h> /* eof() */
 #include<math.h> /* floor(),ceil(),abs() */
 #include<process.h> /* exit() */
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0
 #define INFEASIBLE -1

using namespace std;

 typedef int Boolean;
 typedef int Status;
 typedef int ElemType;
 #define MAXSIZE 100
  typedef struct
 {
 	ElemType *elem; /*储存空间基址*/
 	int length; /*当前长度*/
 } SqList;
 Status initList(SqList *L);
 Boolean isEmpty(SqList L);
 Status ListInsertLast(SqList *L,ElemType e);
 Status ListInsertFirst(SqList *L,ElemType e);
 Status ListInsert(SqList *L,int index,ElemType e);
 void showList(SqList L);
 Status GetElement(SqList L,int index,ElemType *e);
 Status Set(SqList *L,int index,ElemType e);
 int LocateElement(SqList *L,int index);
 Status DeleteElement(SqList *L,ElemType e);
 //*****************************************
 //构造一个空的顺序表L
 Status InitList(SqList *L)
 {
 	L->elem=new ElemType[MAXSIZE];
	 if(!L->elem) return 0;
	 L->length=0;
	 return OK;
 }
 //顺序表的取值
 Status GetElem(SqList L,int i,ElemType *e)
 {
 	if (i<1 || i>L.length) return ERROR;
 	e=&L.elem[i-1];
 	return OK;
  }
 //查找元素
 int LocateElem(SqList L,ElemType e)
{
   int i;
   if (L.length==0)
            return 0;
   for(i=0;i<L.length;i++){
        if (L.elem[i]==e)
            break;
    }
    if(i>=L.length)  return 0;
    return i+1;
}

 //插入元素
Status ListInsert(SqList *L, int i , ElemType e)
{
    int j;
    if(i<1 || i>L->length+1) return ERROR;     //i值不合法
    if(L->length==MAXSIZE) return ERROR; //存储空间已满
    if (i<=L->length)        /* 若插入数据位置不在表尾 */
    {
        for(j=L->length-1;j>=i-1;j--)
        L->elem[j+1]=L->elem[j]; //从最后一个元素开始后移，直到第i个元素后移
    }
    L->elem[i-1]=e; //将新元素e放入第i个位置
    ++L->length;             //表长增1
	return OK;
}
 //删除元素
 Status ListDelete(SqList &L,int i, int j)
{
   if((i<1)||(i>L.length)) return ERROR;     //i值不合法
  //e=L.elem[i-1]; //将欲删除的元素保留在e中
  for (j=i;j<=L.length-1;j++)
        L.elem[j-1]=L.elem[j];//被删除元素之后的元素后移   --L.length;      //表长减1
  return OK;
}
   //输出顺序表中现有的所有元素
 Status printElem(SqList L)
{
	cout << " 顺序表中的元素如下：" << endl;
	int i;
	for (i = 0; i< L.length; i++)
	{
		cout <<" "<< L.elem[i];
	}
	cout << endl;
	return 0;
}

 //void print(SqList L)
//{
//    cout<<"输出顺序表"<<endl;
 //   for(int j=0;j<=L.length-1;j++)
 //       cout<<L.elem[j]<<" ";
 //       cout<<endl;
//}

//void DestroyList(SqList &L){
//    if(L.elem) delete []L.elem;//释放存储空间
//}
int main()
{
	SqList L;
	int e,n,number;
	while (1)
	{
		cout << "    1、创建信息表" << endl;
		cout << "    2、插入元素" << endl;
		cout << "    3、查询元素" << endl;
		cout << "    4、删除元素" << endl;
		cout << "    5、退出程序" << endl;
		cout << "    请选择所要执行的操作:";
		cin >> n;
		switch (n)
		{
		case 1:
			InitList(&L);

			printElem(L);
			break;
		case 2:
			cout << "请输入插入的位置和元素:";
			cin >> number >> e;
			while (e != 0)
			{
				ListInsert(&L, number, e);
				printElem(L);
				cout << "请输入插入的位置和元素:";
				cin >> number >> e;

			}
			break;
		case 3:
			cout << "请输入查找的元素:";
			cin >> e;
			while (e!=0)
			{
				int x;
				x=LocateElem(L, e);
                cout << "该元素"<< e <<"所在顺序表的位置位置是：" << x << endl;
			}
			break;
		case 4:
			cout << "请输入要删除的位置 :";
			cin >> number;
			ListDelete(L, number, e);
			printElem(L);
			break;//程序结束
		case 5:
			exit(1);
			break;//程序结束
		default:
			cout << "输入错误，请重新输入!!!!!" << endl;
			continue;
		}
	}
	return 0;
}
