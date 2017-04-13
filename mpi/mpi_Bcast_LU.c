#include <stdio.h>
#include "mpi.h"
#include "matrix.c"

int main(int argc, char *argv[])
{
	MPI_Status status;
	int num, rank, size, tag, high, low, i, j, k;
	int offset, tmphigh, rows;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	rows = N / size; //N is the height of the matrices
	tag = 201;
	low = rank*rows;
	high = low+rows;
	int len=N;
	double dx = 0.2;
	double dt = 0.01;
	double k_coef = 1;
	const double r = k_coef*dt/(dx*dx);
	double T0 = 0, Tw = 100;
	const int loop = 15;
	
	double T[N] = {0, 0, 0, 0, 100};
	double T1[N];
	double A[N][N] = {
	 {1, 0, 0, 0, 0},
	 {-r, 1+2*r, -r, 0, 0},
	 {0, -r, 1+2*r, -r, 0},
	 {0, 0, -r, 1+2*r, -r},
	 {0, 0, 0, 0, 1}
	};


	if (rank == 0){
		printf("dx=%f\ndt=%f\nk_coef=%f\nr=%f\n", dx, dt, k_coef, r);
		printMatrix(A, N);
		//fillMatrix((int *)a, N);
		//fillMatrix((int *)b, N);
		//printMatrix(a, N);
		// LU decomp
	  for( i=0; i<N; ++i){
	    for( j=0; j<=i; ++j){
	      double lu = A[i][j];
	      for( k=0; k<j; ++k){
	        lu -= A[i][k]*A[k][j]; // l_ik * u_kj
	      }
	      A[i][j] = lu;
	    }
	
	    for( j=i+1; j<N; ++j){
	      double lu = A[i][j];
	      for( k=0; k<i; ++k){
	        lu -= A[i][k]*A[k][j]; // l_ik * u_kj
	      }
	      A[i][j] = lu/A[i][i];
	    }
	  }
		printMatrix(A, N);
	}

	//MPI_Bcast(&A[0][0], N*N, MPI_INT, 0, MPI_COMM_WORLD);
	if(rank==0){
		for(i=1; i<size; ++i){
			offset = i * rows;
			MPI_Send(&a[offset][0], rows*N, MPI_INT, i, tag, MPI_COMM_WORLD);
		}
	}
	else{
		MPI_Recv(&a[low][0], rows*N, MPI_INT, 0, tag, MPI_COMM_WORLD, &status);
	}
	
	//printf("%d: printMatrix\n", rank);
	//printMatrix(A, N);
	
	MPI_Finalize();
	return 0;
}
