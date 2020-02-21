#include <stdio.h>
#include <stdlib.h>

void permutation(int k,int n,int a[])
{
    int i,temp;
    if(k==n-1){
        for(i=0;i<n;i++)
            printf(" %d",a[i]);
        printf("\n");
    }else{
        for(i=k;i<n;i++){
            temp=a[k];
            a[k]=a[i];
            a[i]=temp;
            permutation(k+1,n,a);
            temp=a[k];
            a[k]=a[i];
            a[i]=temp;
        }
    }
}

int main()
{
    int i,a[100],n;
    printf("Please enter an integer number that does not exceed 8, because factorial greater than 7 is too large.");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        a[i]=i+1;
    permutation(0,n,a);
    printf("Hello world!\n");
    return 0;
}
