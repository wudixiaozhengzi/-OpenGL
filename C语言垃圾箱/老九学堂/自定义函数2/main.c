#include <stdio.h>
#include <stdlib.h>
/*��д����ʵ������Ԫ�صĲ��ң�Ҫ�󷵻��ҵ���Ԫ���±�
��д����ʵ��ð�����򲢷�������������
��д����Ҫ���û��������루6λ���������������룩�����ز���ӡ�û��������ȷ����*/


//��д����ʵ������Ԫ�صĲ��ң�Ҫ�󷵻��ҵ���Ԫ���±�
int search();
//��д����ʵ��ð�����򲢷�������������
//double[] sort();
//��д����Ҫ���û��������루6λ���������������룩�����ز���ӡ�û��������ȷ����
//char * password();


int main()
{
     int index=search();
     printf("�ҵ���Ԫ���±�Ϊ%d\n",index);
    printf("Hello world!\n");
    return 0;
}

int search()
{
    int nums[] = {45,35,84,46,21};
    int i;
    //Ҫ���ҵ����֣����������ֵ��±꣬û�ҵ�indexΪ-1
    int searchNum,searchIndex = -1;

    printf("������Ҫ���ҵ��������֣�");
    scanf("%d",&searchNum);
    //��ٷ�
    for(i = 0; i < 5; i++)
    {
        if(searchNum == *(nums + i))
        {
            searchIndex = i;//��¼�²��Ҵ��±�
            break;
        }
    }
    return searchIndex;
}
















