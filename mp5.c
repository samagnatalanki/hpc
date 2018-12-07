#include<stdio.h>
#include "mpi.h"

int main(int argc,char * argv[])
{
    int size,rank;
    int val;
    MPI_Status status;

    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);

    if (rank==3){
        MPI_Send(&rank,1,MPI_INT,0,0,MPI_COMM_WORLD);
        MPI_Send(&rank,1,MPI_INT,1,0,MPI_COMM_WORLD);
        MPI_Send(&rank,1,MPI_INT,2,0,MPI_COMM_WORLD);
    } //printf("hii");
    else{
        MPI_Recv(&val,1,MPI_INT,3,0,MPI_COMM_WORLD,&status);
        printf("at %d val is %d",rank,val);
    }

    MPI_Finalize();
}