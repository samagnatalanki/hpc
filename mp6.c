#include <stdio.h>
#include <mpi.h>

int main(int argc,char *argv[])
{
    int rank,size;
    char para[6],mine;
    int sndcnt,rcvcnt;
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);

    //printf("%d",size);
    sndcnt=1;
    mine='s';
    
    if(rank==3) rcvcnt=1;

    MPI_Gather(&mine,sndcnt,MPI_CHAR,para,rcvcnt,MPI_CHAR,3,MPI_COMM_WORLD);

    if(rank==3)
        for(int i=0;i<size;i++)
            printf("PE : %d para[%d]= %s \n",rank,i,para[i]);

    MPI_Finalize();


}