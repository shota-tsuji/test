#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <omp.h>

void fill_matrix(double **matrix, int n)
{
	// srand(time());
	int i, j, val = 1;
	for(i=0; i<n; ++i){
		for(j=0; j<n; ++j){
			matrix[i][j] = (double)rand() / RAND_MAX*2.0 -1.0;
		}
	}
}

void fill_zero_matrix(double **matrix, int n)
{
	int i, j;
	for(i=0; i<n; ++i){
		for(j=0; j<n; ++j){
			matrix[i][j] = 0.0;
		}
	}
}

void print_matrix(double **matrix, int n)
{
	int i, j;
	for(i=0; i<n; ++i){
		for(j=0; j<n; ++j){
			printf("%f ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}



int main(int argc, char*argv[])
{
	
	int n = atoi(argv[1]);
	int i, j, k;
	int cnt=0;
	double before=0.0, whole_time=0.0, after=0.0;
	double **A, **B, **C;

	A = (double**)malloc(sizeof(double*) *n);
	B = (double**)malloc(sizeof(double*) *n);
	C = (double**)malloc(sizeof(double*) *n);
	for(i=0; i<n; ++i){
		A[i] = (double*)malloc(sizeof(double) *n);
		B[i] = (double*)malloc(sizeof(double) *n);
		C[i] = (double*)malloc(sizeof(double) *n);
	}
	
	srand(time(NULL));
	fill_matrix(A, n);
	fill_matrix(B, n);
	
	before = omp_get_wtime();
	while(1){
		fill_zero_matrix(C, n);
		for(k=0; k<n; ++k){
			for(j=0; j<n; ++j){
				for(i=0; i<n; ++i){
					C[i][j] += A[i][k] * B[k][j];
				}
			}
		}

		cnt++;
		after = omp_get_wtime();	
		if(after - before >= 1.0){
			whole_time = after - before;
			break;
		}

	}

	double num_cluc = 2.0 * n * n * n;
	double gflops = num_cluc * cnt / 1e+9 / whole_time;
	printf("%d,%f\n", n, gflops);

	for(i=0; i<n; ++i){
		free(A[i]);
		free(B[i]);
		free(C[i]);
	}
	free(A);
	free(B);
	free(C);

	return 0;
}
