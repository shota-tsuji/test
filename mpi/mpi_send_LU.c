#include <stdio.h>
#include <math.h>
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
	int dest_rank = (rank+1)%size; // 一つ先におくる
	int src_rank = (rank-1+size)%size; // 1つ前からもらってくる
	//int pC = 
	int M=size; // とりあえず5で固定
	int level = 4;
	int N_t = pow(size, level-1)+1;
	double T[N] = {0, 0, 0, 0, 100};
	double T1[N], T_tmp[N];


	rows = N / size; //N is the height of the matrices
	tag = 201;
	low = rank*rows;
	high = low+rows;
	double dx = 0.2;
	double dt = 0.01;
	double k_coef = 1;
	const double r = k_coef*dt/(dx*dx);
	double T0 = 0, Tw = 100;
	const int g_loop = 16;
	const int l_loop = g_loop / size;
	int step = 0;
	
	// 各レベルにおいて，行列Aを作成できるような関数をつくる
	double A[N][N] = {
	 {1, 0, 0, 0, 0},
	 {-r, 1+2*r, -r, 0, 0},
	 {0, -r, 1+2*r, -r, 0},
	 {0, 0, -r, 1+2*r, -r},
	 {0, 0, 0, 0, 1}
	};


	if (rank == 0){
		printf("dx=%f\ndt=%f\nk_coef=%f\nr=%f\n", dx, dt, k_coef, r);
		//printMatrix(A, N);
		// LU decomp
		LU_decomp(A, N);

	// Send A[][] to all nodes.
	if(rank==0){
		for(i=1; i<size; ++i){
			MPI_Send(&A[0][0], N*N, MPI_DOUBLE, i, tag, MPI_COMM_WORLD);
		}
	}
	else {
		MPI_Recv(&A[0][0], N*N, MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &status);
	}
	
  for( step=0; step<g_loop; ++step){
		LU_solve(A, T, T1, N);
		//printArray(T, N, rank);
  }
	printArray(T, N, rank);

	//printf("%d: printMatrix\n", rank);
	//printMatrix(A, N);

	// Non-Blocking communication is needed.
	MPI_Sendrecv(&T[0], N, MPI_DOUBLE, dest_rank, tag,
							&T_tmp[0], N, MPI_DOUBLE, src_rank, tag, MPI_COMM_WORLD, &status);
	if(rank!=0 && rank!=size-1){
    for( i=0; i<N; ++i){
      T[i] = T_tmp[i];
    }
	}
	//printArray(T, N, rank);
	
	MPI_Finalize();
	return 0; }
