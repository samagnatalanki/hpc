#include<stdio.h>
#include<mpi.h>

int main(int argc ,char * argv[])
{
    int rank,size;
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    int sum=0,value;
    int s,st,d,dt;
    MPI_Status status;

    if(rank == 0)
    {
        //printf("hello  \n");
    
        for(int i=1;i<size;i++)
        {
            s=i;
            st=0;
            MPI_Recv(&value,1,MPI_INT,s,st,MPI_COMM_WORLD,&status);
            sum+=value;
        }
        printf("sum is %d",sum);
    }
    

    else
    {
        //printf("\n hii");
       d=0;dt=0;
       MPI_Send(&rank,1,MPI_INT,d,dt,MPI_COMM_WORLD);
    }

    MPI_Finalize();
}