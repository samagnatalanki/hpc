#include<stdio.h>
#include<omp.h>

int main(int argc,char *argv[])
{
    int i;
    float a[1000],b[1000],sum;

    for(int i=0;i<1000;i++)
    {
        a[i]=b[i]=i*1.0;
    }

    sum=0.0;

    #pragma omp parallel for reduction(+:sum)
        for(i=0;i<1000;i++)        
            sum += a[i]*b[i];
        
    printf("%f",sum); 
}