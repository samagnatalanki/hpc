#include <stdio.h>
#include <omp.h>

int main(int argc,char *argv[])
{
    int RA=3,CA=3,CB=3;
    int i,j,k,tid,chunk=2;

    float a[RA][CA],b[CA][CB],c[RA][CB];

    #pragma omp parallel shared(a,b,c,chunk) private(i,j,k,tid)
    {
        tid=omp_get_thread_num();
        printf("thread %d running......\n",tid);

        #pragma omp for schedule(static,chunk)
        for(i=0;i<RA;i++)
            for(j=0;j<CA;j++)
                a[i][j]=i+j;
             


        #pragma omp for schedule(static,chunk)
        for(i=0;i<CA;i++)
            for(j=0;j<CB;j++)
                b[i][j]=i+j;

        #pragma omp for schedule(static,chunk)
        for(i=0;i<RA;i++)
            for(j=0;j<CB;j++)
                c[i][j]=0;
        
        #pragma omp for schedule(static,chunk)
        for(i=0;i<RA;i++)
        {
            printf("\n thread %d doinf %d row \n",tid,i);
            for(j=0;j<CB;j++)
                for(k=0;k<CA;k++)
                    c[i][j] += a[i][k]*b[k][j];        
        }
         
    }
printf("******************************************************\n");
for (i=0; i<RA; i++)
{
for (j=0; j<CA; j++)
printf("%6.2f ", a[i][j]);
printf("\n");
}

for (i=0; i<CA; i++)
{
for (j=0; j<CB; j++)
printf("%6.2f ", b[i][j]);
printf("\n");
}
printf("Result Matrix:\n");
for (i=0; i<RA; i++)
{
for (j=0; j<CB; j++)
printf("%6.2f ", c[i][j]);
printf("\n");
}
printf("******************************************************\n");
printf ("Done.\n");
    

    
}