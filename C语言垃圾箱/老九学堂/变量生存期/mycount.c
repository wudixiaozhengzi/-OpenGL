/*
my count.c
������ż��㺯�����ô����ĺ���ԭ�ͼ�ʵ��
*/
//�����ⲿ����
extern int whileCount;

void counter(int);//�������㱾���������ö��ٴ�

void counter(int i)
{
    static int subTotal = 0;//��̬�洢����һ��ִ�л����ռ䣬�Ժ�Ͳ����ٷ���ռ��ˣ�����ֻ��ִ��һ��

    subTotal++;
    printf("counter������������%d��\n",subTotal);
    printf("��ǰ��while�ĵ�%d�֣�\n",whileCount);
    return subTotal;
}











