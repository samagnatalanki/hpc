#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#define MAX 1000

int main(int argc,char *argv[])
{
    int a[10],curmax;

    //srand(MAX);

    for(int i=0;i<10;i++)
    {
        a[i]=rand();
    }

    printf("the array is :\n");
    for(int i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }

    printf("In serial \n");
    curmax=a[0];

    for(int i=0;i<10;i++)
    {
        if(a[i]>curmax)
            curmax=a[i];
    }
    printf("max in serial is %d \n",curmax);

    int maxval=0;
    printf("In parallel \n");
    #pragma omp parallel for 
        for(int i=0;i<10;i++)
            if(a[i]>maxval)
                #pragma omp critical
                    if(a[i]>maxval)
                        maxval=a[i];

    printf("max in parallel is %d \n",maxval);




}