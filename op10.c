#include<stdio.h>
#include <omp.h>
#include <stdlib.h>

int main(int argc,char * argv[])
{
    int tid,i,nthreads,chunk;
    chunk=5;
    float a[20],b[20],c[20];

    for(int i=0;i<20;i++)
    {
        a[i]=b[i]=i*1.0;    
    }
    #pragma omp parallel shared(a,b,c,chunk,nthreads) private(i,tid)
    {
        nthreads = omp_get_num_threads();
        tid= omp_get_thread_num();
        
        #pragma omp for schedule(guided,chunk) //static,dynamic,guided,auto
        for(i=0;i<20;i++)
        {
            c[i]=a[i]+b[i];
            printf("thread %d : %f + %f = %f \n",tid,a[i],b[i],c[i]);
        }
    }


}