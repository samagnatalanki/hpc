#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
    int N=12,found;
    int *a;
    int i;
    a=(int *)malloc(N*sizeof(int));
    
    for(i=0;i<N+1;i++) a[i]=1;
    //for(int i=0;i<N+1;i++) printf("%d",a[i]);
    
    int k=2;
    #pragma omp parallel firstprivate(k) private(i,found)
    while(k*k < N)
    {
        #pragma omp for
        for(i=k*k;i<=N;i+=k) a[i]=0;

        found=0;
        
        for(i=k+1;!found;i++)
        {
            if( a[i])
            {
                k=i;
                found=1;
            }
        }       

    }

    for(int i=0;i<N+1;i++) printf("%d",a[i]);

}