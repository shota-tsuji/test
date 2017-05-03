#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

void fill_matrix_sequence(double **matrix, int n)
{
	int i, j, val = 0;
	for(i=0; i<n; ++i){
		for(j=0; j<n; ++j){
			matrix[i][j] = val;
			val++;
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
	double t_s=0.0, t_w=0.0, t_e=0.0;
	double **A, **B, **C;

	A = (double**)malloc(sizeof(double*) *n);
	B = (double**)malloc(sizeof(double*) *n);
	C = (double**)malloc(sizeof(double*) *n);
	inner_malloc(A, n);
	inner_malloc(B, n);
	inner_malloc(C, n);
	
	srand(time(NULL));
	fill_matrix(A, n);
	fill_matrix(B, n);
	
	double t_before, t_after, t_subtract=0.0;
	int ibl = n / 2;
	//	int n_rows = n / 2, n_clums = n / 2;
	int ib, jb, kb;
	int cnt = 0;
	t_s = omp_get_wtime();
	while(1){
		t_before = omp_get_wtime();
		fill_zero_matrix(C, n);
		t_after = omp_get_wtime();
		t_subtract += t_after - t_before;
		
		for(ib=0; ib<n; ib+=ibl){
			for(jb=0; jb<n; jb+=ibl){
				for(kb=0; kb<n; kb+=ibl){
					for(i=ib; i<ib+ibl; ++i){
						for(j=jb; j<jb+ibl; ++j){
							for(k=kb; k<kb+ibl; ++k){
								C[i][j] += A[i][k] * B[k][j];
							}
						}
					}
				}
			}
		}

		cnt++;
		if(omp_get_wtime() - t_s > 1.0) break;
	}
	t_e = omp_get_wtime();
	t_w = t_e - t_s - t_subtract;
	double t_ave = t_w / cnt;

//	fill_zero_matrix(C, n);
//	for(i=0; i<n; ++i){
//		for(j=0; j<n; ++j){
//			for(k=0; k<n; ++k){
//				C[i][j] += A[i][k] * B[k][j];
//			}
//		}
//	}
//	print_matrix(C, n);
//	return 0;

	// 足し算は，ひとつの箱に足し入れているので，(N-1)の-1はなくなる
	double num_cluc = 2.0 * pow(n, 3);
	double gflops = num_cluc  * cnt / ( pow(10.0, 9) *  t_w);
	printf("%d,%f,%f\n", n, t_ave, gflops);

	iner_free(A, n);
	free(A);
	iner_free(B, n);
	free(B);
	iner_free(C, n);
	free(C);

	return 0;
}
