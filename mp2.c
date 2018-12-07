#include <stdio.h>
#include "mpi.h"

int main (int argc, char *argv[])
{ 
	 int rank;
     char i[11];

 	  MPI_Init (&argc, &argv);

   MPI_Comm_rank (MPI_COMM_WORLD, &rank);


   if (rank == 0){ char i[11] = "hello msrit";}

   MPI_Bcast ((void *)&i, 11, MPI_CHAR, 0, MPI_COMM_WORLD);

   printf ("[%d] i = %s\n", rank, i);

   // Wait for every process to reach this code


   MPI_Barrier (MPI_COMM_WORLD);

   MPI_Finalize();


   return 0;


}