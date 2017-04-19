#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <omp.h>

void fill_matrix_1d(double *matrix_1d, int n)
{
	int i, j, val = 1;
	for(i=0; i<n*n; ++i){
			matrix_1d[i] = (double)rand() / RAND_MAX*2.0 -1.0;
	}
	printf("SAFE\n");
}

void fill_zero_matrix_1d(double **matrix_1d, int n)
{
	int i, j;
	for(i=0; i<n; ++i){
		for(j=0; j<n; ++j){
			matrix_1d[i][j] = 0.0;
		}
	}
}

void print_matrix_1d(double *matrix_1d, int n)
{
	int i, j;
	for(i=0; i<n*n; ++i){
		if((i)%n==0) printf("\n");
		printf("%f ", matrix_1d[i]);
	}
	printf("\n");
}

void inner_malloc(double **matrix, int n)
{	
	int i=0;
	//matrix = (double**)malloc(sizeof(double*) *n);

	for(i=0; i<n; ++i){
		matrix[i] = (double*)malloc(sizeof(double) *n);
	}
}

void iner_free(double **matrix, int n)
{
	int i=0;
	for(i=0; i<n; ++i){
		free(matrix[i]);
	}
}


int main(int argc, char*argv[])
{
	
	int n = atoi(argv[1]);
	int i, j, k;
	double time_s=0.0, whole_time=0.0;
	double *A, *B, *C;

//	A = (double**)malloc(sizeof(double*) *n);
//	B = (double**)malloc(sizeof(double*) *n);
//	C = (double**)malloc(sizeof(double*) *n);
//	inner_malloc(A, n);
//	inner_malloc(B, n);
//	inner_malloc(C, n);
	A = (double*)malloc(sizeof(double*) *n*n);
	B = (double*)malloc(sizeof(double*) *n*n);
	C = (double*)malloc(sizeof(double*) *n*n);

	srand(time(NULL));
	fill_matrix_1d(A, n);
	fill_matrix_1d(B, n);
	
	time_s = omp_get_wtime();
	/*
	n=3;
	for(i=0; i<n; ++i){
		for(j=0; j<n; ++j){
			A[i*n+j] = i;
			B[i*n+j] = i;
			
		}
	}
	*/
	print_matrix_1d(A, n);
	print_matrix_1d(B, n);
	for(i=0; i<n; ++i){
		for(j=0; j<n; ++j){
			for(k=0; k<n; ++k){
				C[i*n+j] += A[i*n + k] * B[j+k*n];
			}
		}
	}
	whole_time = omp_get_wtime() - time_s;

	// 足し算は，ひとつの箱に足し入れているので，(N-1)の-1はなくなる
	double num_cluc = 2.0 * pow(n, 3);
	double gflops = num_cluc / ( pow(10.0, 9) *  whole_time);
	printf("%d,%f,%f\n", n, whole_time, gflops);

	//iner_free(A, n);
	free(A);
	//iner_free(B, n);
	free(B);
	//iner_free(C, n);
	free(C);

	return 0;
}
