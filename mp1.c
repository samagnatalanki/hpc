#include <stdio.h>
#include <mpi.h>

int main(int argc,char *argv[])
{
    int rank,size;
    double para[6],mine;
    int sndcnt,rcvcnt;
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);

    //printf("%d",size);
    sndcnt=1;
    mine=5.0+rank;
    
    if(rank==3) rcvcnt=1;

    MPI_Gather(&mine,sndcnt,MPI_DOUBLE,para,rcvcnt,MPI_DOUBLE,3,MPI_COMM_WORLD);

    if(rank==3)
        for(int i=0;i<size;i++)
            printf("PE : %d para[%d]= %f \n",rank,i,para[i]);

    MPI_Finalize();


}