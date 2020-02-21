#include  <stdio.h>
#include <stdio.h>


int main()
{
    int i,j,k=0;
    int a[9]={3,7,3,2,1,1,8,7,3}   ;

    for(i=0;i<9;i++) {
        for(j=0;j<k && a[i]!=a[j];j++)
             ;
        if(j==k){
            if(k!=i)
            a[k]=a[i];
            k++;
        }
    }
    for(i=0;i<9;i++)
        printf("%d  ",a[i])  ;

    return 0;
}
