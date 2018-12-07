#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#define MAX 1000

int main(int argc,char *argv[])
{
    int n;
    omp_lock_t lock;

    printf("Eneter no.of elements");
    scanf("%d",&n);

    int a[n],curmax;

    a[n]=(int*) malloc(n*sizeof(int));

    //srand(MAX);

    for(int i=0;i<10;i++)
    {
        a[i]=rand();
    }

    printf("the array is :\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

    printf("In serial \n");
    curmax=a[0];

    for(int i=0;i<n;i++)
    {
        if(a[i]>curmax)
            curmax=a[i];
    }
    printf("max in serial is %d \n",curmax);

    int maxval=0;
    printf("In parallel \n");

    omp_init_lock(&lock);

    #pragma omp parallel for
        for(int i=0;i<n;i++)
        {
            if(a[i]>maxval)
            omp_set_lock(&lock);
            if(a[i]>maxval)
                maxval=a[i];
            omp_unset_lock(&lock);
        }
    
    printf("max in parallel is %d \n",maxval);

 


}