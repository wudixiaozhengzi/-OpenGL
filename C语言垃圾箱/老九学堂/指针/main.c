#include <stdio.h>
#include <stdlib.h>
//ָ����һ��ֵΪ�ڴ��ַ�ı���
int main()
{
    int num = 0;
    int *ptr_num = &num;
    //ͷ�۵㣺ָ��ĵ�ַ
    int *ptr_num2 = &ptr_num;
    //%pָ��ռλ����%x  16����ռλ��
    printf("num�����ĵ�ַ�ǣ�%p\n%x\n",ptr_num,&num);

    printf("\nָ��ptr_num�ĵ�ַ�ǣ�%p\n%x\n",ptr_num2,&num);

    //ʹ��ָ���޸ı���ֵ
    /*
    *ptr_num = 9999;
    printf("*ptr_num��Ӧ��ֵΪ��%d\n",*ptr_num);
    printf("*ptr_num��Ӧ��ֵΪ��%d\n",num);*/
    return 0;
}
