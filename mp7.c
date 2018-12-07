#include <stdio.h>
#include <mpi.h>

int main(int argc,char *argv[])
{
    int rank,size;
    char smsg[4],rmsg;
    int sndcnt,rcvcnt;
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);

    if(rank==0) {char smsg[10]="hell";}

    MPI_Scatter(&smsg,1,MPI_CHAR,&rmsg,1,MPI_CHAR,0,MPI_COMM_WORLD);

    printf("rank %d has %c \n",rank,rmsg);
    MPI_Finalize();


}