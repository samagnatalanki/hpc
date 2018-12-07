#include<stdio.h>
#include<stdlib.h>
#include <omp.h>

long long fac(int n)
{
    long out =1;
    for(int i=1; i<n+1; i++ ) out*= i;
    return out;
}

int main(int argc,char *argv[])
{
    int threads;
    if(argc>1)
    {
        threads=(int)argv[1];
    }
    if(omp_get_dynamic())
    {
        omp_set_dynamic(0);
        printf("set dyn to 0");
    }
    omp_set_num_threads(threads);

    long long *x;
    long long n=5;

    x=(long long *) malloc(n*sizeof(long));

    for(int i=0;i<n;i++) x[i]=fac(i);
    for(int i=0;i<n;i++) printf("%lld \n",x[i]);

    int j=0;

    #pragma omp parallel for firstprivate(x,j)
    for(int i=1;i<n;i++)
    {
        j+=1;
        x[i]=j*x[i-1];
    }

    for(int i=1;i<n+1;i++)
    printf("factorial of %d = %lld",i,x[i]);

    
}
