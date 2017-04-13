#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

void fill_matrix(double **matrix, int n)
{
	int i, j, val = 1;
	for(i=0; i<n; ++i){
		for(j=0; j<n; ++j){
			matrix[i][j] = val;
			val += 1;
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

	fill_matrix(A, n);
	fill_matrix(B, n);
	//print_matrix(A, n);
	//print_matrix(B, n);
	
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
	}while(whole_time < 1.0);

	// 足し算は，ひとつの箱に他仕入れているので，(N-1)の-1はなくなる
	double num_cluc = (2.0 * pow(n, 3)) - pow(n, 2);
	double gflop = num_cluc * count / ( pow(10.0, 9) *  whole_time);
	//printf("size, time, gflop\n");
	printf("%d,%f,%f\n", n, whole_time/count, gflop);
	//printf("size, total_time, count, gflop\n");
	//printf("%d, %f, %d, %f\n", n, whole_time/count, count, gflop);

	for(i=0; i<n; ++i){
		free(A[i]);
	}
	free(A);

	for(i=0; i<n; ++i){
		free(B[i]);
	}
	free(B);
	
	for(i=0; i<n; ++i){
		free(C[i]);
	}
	free(C);

	return 0;
}
