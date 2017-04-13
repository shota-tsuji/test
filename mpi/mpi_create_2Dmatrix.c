#include <stdio.h>
#include "mpi.h"
#include "matrix.c"

int main(int argc, char *argv[])
{
	MPI_Status status;
	int num, rank, size, tag, high, low, i;
	int offset, tmphigh, rows;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	rows = MAX / size; //MAX is the height of the matrices
	tag = 201;
	low = rank*rows;
	high = low+rows;

	if (rank == 0){
		printf("%d: filling matrices\n", rank);
		fillMatrix((int *)a, MAX);
		fillMatrix((int *)b, MAX);
		printMatrix(a, MAX);
	}

	MPI_Bcast(&b[0][0], MAX*MAX, MPI_INT, 0, MPI_COMM_WORLD);
	//printMatrix(b, MAX);
	if(rank==0){
		for(i=1; i<size; ++i){
			offset = i * rows;
			MPI_Send(&a[offset][0], rows*MAX, MPI_INT, i, tag, MPI_COMM_WORLD);
		}
	}
	else{
		MPI_Recv(&a[low][0], rows*MAX, MPI_INT, 0, tag, MPI_COMM_WORLD, &status);
	}
	
	printf("%d: printMatrix\n", rank);
	printMatrix(a, MAX);
	
	MPI_Finalize();
	return 0;
}
