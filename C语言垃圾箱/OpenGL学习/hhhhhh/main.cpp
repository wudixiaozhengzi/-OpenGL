#include <iostream>


#include <math.h>
#include<string.h>
 #include<ctype.h>
 #include<stdio.h> /* EOF(=^Z��F6),NULL */
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
 	ElemType *elem; /*����ռ��ַ*/
 	int length; /*��ǰ����*/
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
 //����һ���յ�˳���L
 Status InitList(SqList *L)
 {
 	L->elem=new ElemType[MAXSIZE];
	 if(!L->elem) return 0;
	 L->length=0;
	 return OK;
 }
 //˳����ȡֵ
 Status GetElem(SqList L,int i,ElemType *e)
 {
 	if (i<1 || i>L.length) return ERROR;
 	e=&L.elem[i-1];
 	return OK;
  }
 //����Ԫ��
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

 //����Ԫ��
Status ListInsert(SqList *L, int i , ElemType e)
{
    int j;
    if(i<1 || i>L->length+1) return ERROR;     //iֵ���Ϸ�
    if(L->length==MAXSIZE) return ERROR; //�洢�ռ�����
    if (i<=L->length)        /* ����������λ�ò��ڱ�β */
    {
        for(j=L->length-1;j>=i-1;j--)
        L->elem[j+1]=L->elem[j]; //�����һ��Ԫ�ؿ�ʼ���ƣ�ֱ����i��Ԫ�غ���
    }
    L->elem[i-1]=e; //����Ԫ��e�����i��λ��
    ++L->length;             //����1
	return OK;
}
 //ɾ��Ԫ��
 Status ListDelete(SqList &L,int i, int j)
{
   if((i<1)||(i>L.length)) return ERROR;     //iֵ���Ϸ�
  //e=L.elem[i-1]; //����ɾ����Ԫ�ر�����e��
  for (j=i;j<=L.length-1;j++)
        L.elem[j-1]=L.elem[j];//��ɾ��Ԫ��֮���Ԫ�غ���   --L.length;      //����1
  return OK;
}
   //���˳��������е�����Ԫ��
 Status printElem(SqList L)
{
	cout << " ˳����е�Ԫ�����£�" << endl;
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
//    cout<<"���˳���"<<endl;
 //   for(int j=0;j<=L.length-1;j++)
 //       cout<<L.elem[j]<<" ";
 //       cout<<endl;
//}

//void DestroyList(SqList &L){
//    if(L.elem) delete []L.elem;//�ͷŴ洢�ռ�
//}
int main()
{
	SqList L;
	int e,n,number;
	while (1)
	{
		cout << "    1��������Ϣ��" << endl;
		cout << "    2������Ԫ��" << endl;
		cout << "    3����ѯԪ��" << endl;
		cout << "    4��ɾ��Ԫ��" << endl;
		cout << "    5���˳�����" << endl;
		cout << "    ��ѡ����Ҫִ�еĲ���:";
		cin >> n;
		switch (n)
		{
		case 1:
			InitList(&L);

			printElem(L);
			break;
		case 2:
			cout << "����������λ�ú�Ԫ��:";
			cin >> number >> e;
			while (e != 0)
			{
				ListInsert(&L, number, e);
				printElem(L);
				cout << "����������λ�ú�Ԫ��:";
				cin >> number >> e;

			}
			break;
		case 3:
			cout << "��������ҵ�Ԫ��:";
			cin >> e;
			while (e!=0)
			{
				int x;
				x=LocateElem(L, e);
                cout << "��Ԫ��"<< e <<"����˳����λ��λ���ǣ�" << x << endl;
			}
			break;
		case 4:
			cout << "������Ҫɾ����λ�� :";
			cin >> number;
			ListDelete(L, number, e);
			printElem(L);
			break;//�������
		case 5:
			exit(1);
			break;//�������
		default:
			cout << "�����������������!!!!!" << endl;
			continue;
		}
	}
	return 0;
}
