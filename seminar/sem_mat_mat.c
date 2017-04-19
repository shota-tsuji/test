#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

void fill_matrix(double **matrix, int n)
{
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
	double time=0.0, whole_time=0.0;
	int count=0;
	double **A, **B, **C;

	A = (double**)malloc(sizeof(double*) *n);
	B = (double**)malloc(sizeof(double*) *n);
	C = (double**)malloc(sizeof(double*) *n);
	inner_malloc(A, n);
	inner_malloc(B, n);
	inner_malloc(C, n);
	
	srand(0);
	fill_matrix(A, n);
	fill_matrix(B, n);
	
	do{
		time = omp_get_wtime();
		for(i=0; i<n; ++i){
			for(j=0; j<n; ++j){
				for(k=0; k<n; ++k){
					C[i][j] += A[i][k] * B[k][j];
				}
			}
		}

		time = omp_get_wtime() - time;
		whole_time += time;
		count +=1;
		//printf("time: %f\n", time);
		fill_zero_matrix(C, n);
	}while(whole_time < 1.0);

	// 足し算は，ひとつの箱に足し入れているので，(N-1)の-1はなくなる
	//double num_cluc = (2.0 * pow(n, 3)) - pow(n, 2);
	double num_cluc = 2.0 * pow(n, 3);
	double gflops = num_cluc * count / ( pow(10.0, 9) *  whole_time);
	//printf("size, time, gflops\n");
	printf("%d,%f,%f\n", n, whole_time/count, gflops);
	//printf("size, total_time, count, gflops\n");
	//printf("%d, %f, %d, %f\n", n, whole_time/count, count, gflops);

	iner_free(A, n);
	free(A);
	iner_free(B, n);
	free(B);
	iner_free(C, n);
	free(C);

	return 0;
}
