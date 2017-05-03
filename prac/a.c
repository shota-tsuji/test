#include <stdio.h>
#include "mpi.h"

int main(int argc, char* argv[])
{
	const int n = 32;
	int numprocs, _rank;
	int ierr, rc;

	ierr = MPI_Init(&argc, &argv);
	ierr = MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	ierr = MPI_Comm_rank(MPI_COMM_WORLD, &_rank);
	int _row = n/numprocs, _id;
	
	double _A[_row][n], _b[n], b[n];
	double _v[_row];
	double v[n];
	int i, j, k;
	for(i=0; i < _row; ++i){
		for(j=0; j<n; ++j){
			_A[i][j] = _rank * 10 + j;	
			_v[i] = _rank;
			_b[i] = 0.0;
		}
	}

	/*
	printf("------------id:%d-----------\n", _rank);
	for(i=0; i < _row; ++i){
		for(j=0; j<n; ++j){
			printf(" %f", _a[i][j]);
		}
		printf("\n");
	}
	*/
	
	MPI_Barrier(MPI_COMM_WORLD);
	double Stime = MPI_Wtime();
// Gather parts or the column vector.
	ierr = MPI_Allgather(_v, _row, MPI_DOUBLE, v, _row, MPI_DOUBLE, MPI_COMM_WORLD);

	for(i=0; i<_row; ++i){
		for(k=0; k<n; ++k){
			_b[i] += _A[i][k]*v[k];
		}
	}
	ierr = MPI_Gather(_b, _row, MPI_DOUBLE, b, _row, MPI_DOUBLE, 0, MPI_COMM_WORLD);
	MPI_Barrier(MPI_COMM_WORLD);
	double Etime = MPI_Wtime();
	printf("%d\t%f\n", _rank, Etime-Stime);
	//printf("------------id:%d-----------\n", _rank);
	/*
	if(_rank == 0){
		for(i=0; i<n; ++i){
			printf(" %f", b[i]);
		}
	}
	printf("\n");
	*/

	rc = MPI_Finalize();
	return 0;
}
