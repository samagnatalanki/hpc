#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main(int argc,char *argv[])
{
    int i,tid,nth;

    #pragma omp parallel private(tid)
    {
        tid=omp_get_thread_num();
        if(tid==0)
        {
        printf("dynamic :%d \n",omp_get_dynamic());
        printf("threads :%d \n",omp_get_num_threads());
        printf("tid :%d \n",omp_get_thread_num());
        printf("nested :%d \n",omp_get_nested());
        printf("In parallel :%d \n",omp_in_parallel());
        printf("max t :%d \n",omp_get_max_threads());
        printf("procs :%d \n",omp_get_num_procs());
        //printf("threads :%d \n",omp_get_num_threads());
        }
    }

}