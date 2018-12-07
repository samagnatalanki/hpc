#include<stdio.h>
#include<omp.h>

int a,b,tid;
float x;

#pragma omp threadprivate(a,x)
int main()
{
    omp_set_dynamic(0);
    #pragma omp parallel private(b,tid)
    {
        tid=omp_get_thread_num();
        a=tid;
        b=tid;
        x=1.1*tid +1.0;
        printf("thread : %d - %d %d %f \n",tid,a,b,x);
    }

    printf("\n");
    #pragma omp parallel
    {
          tid=omp_get_thread_num();
        printf("thread : %d - %d %d %f \n",tid,a,b,x);   
    }

}