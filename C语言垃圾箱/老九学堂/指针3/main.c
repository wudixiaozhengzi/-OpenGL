#include <stdio.h>
#include <stdlib.h>

int main()
{
      int arry[] = {15,25,30,45,65};
      int i;
      int * ptr_arry = arry;
      for(i = 0; i < 5; i++)
      {
           printf("��%d��Ԫ�ص�ֵΪ%d\t��ַΪ��%p\n"
                  ,i+1, *ptr_arry ++,ptr_arry);
           /*printf("��%d��Ԫ�ص�ֵΪ%d\t��ַΪ��%p\n"
                  ,i+1, *(ptr_arry + i),ptr_arry+1);
          /*printf("��%d��Ԫ�ص�ֵΪ%d\t��ַΪ��%p\n"
                   ,i+1, ptr_arry[i],&ptr_arry[i]);*/
      }
    printf("Hello world!\n");
    return 0;
}
