// NOT RUNNING ON DIFFERENT THREADS

#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main(int argc,char *argv[])
{
    int i,tid,nth;
    float a[10],b[10],c[10],d[10];

    for (i=0;i<10;i++)
    {
        a[i]=i*2.0;
        b[i]=i+1.0;
        c[i]=d[i]=0;
    }

    #pragma omp parallel shared(b,c,nth,d,a) private(tid,i)
    {
        tid=omp_get_thread_num();
        printf("thread %d starting.... \n",tid);
        #pragma omp sections nowait
        {
            #pragma omp section
            {
                printf("thread doing 1 - %d \n",tid);
                for(i=0;i<10;i++)
                {
                    c[i]=a[i]+b[i];
                    printf("thread %d : %f + %f = %f \n",tid,a[i],b[i],c[i]);
                }
            }
            #pragma omp section
            {
                printf("thread doing 2 - %d \n",tid);
                for(i=0;i<10;i++)
                {
                    d[i]=a[i]-b[i];
                    printf("thread %d : %f + %f = %f \n",tid,a[i],b[i],d[i]);
                }
            }
        }
    }
}