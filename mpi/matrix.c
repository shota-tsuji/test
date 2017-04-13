#include <stdio.h>
#define N 5
int a[N][N], b[N][N], c[N][N];
//double A[N][N] = {
// {1, 0, 0, 0, 0},
// {-r, 1+2*r, -r, 0, 0},
// {0, -r, 1+2*r, -r, 0},
// {0, 0, -r, 1+2*r, -r},
// {0, 0, 0, 0, 1}   };




void fillMatrix(int *matrix, int len)
{
	int i, j;

	for(i=0; i<len; ++i){
		int *row = &matrix[i * len];
		for(j=0; j<len; ++j){
			row[j] = j;
		}
	}
}

void printMatrix(double matrix[][N], int len)
{
	int i, j;
	for(i=0; i<len; ++i){
		for(j=0; j<len; ++j){
			printf(" %f", matrix[i][j]);
		}
		printf("\n");
	}
	printf("-------------------------------------\n");
}

void printArray(double *array, int len, int rank)
{
	printf("%d: printArray\n", rank);
	int i;
	for(i=0; i<len; ++i){
		printf(" %f", array[i]);
	}
	printf("\n");
}

void LU_decomp(double A[][N], int n)
{
	int i, j, k;
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

// arrayの中身を更新するところまでおこなう
void LU_solve(double A[][N], double *array, double *result,  int n)
{
	int i, j, k;
  // 前進代入
   for( i=0; i<N; ++i){
     double bly = array[i];
     for( j=0; j<i; ++j){
       bly -= A[i][j]*result[j];
     }
     result[i] = bly/A[i][i];
   }

   // 後退代入
   // result[]は未知ベクトル, 上のarray[]が既知ベクトル
   for( i=N-1; i>=0; --i){
     double yux = result[i];
     for( j=i+1; j<N; ++j){
       yux -= A[i][j]*result[j];
     }
     result[i] = yux;
   }

   for( i=0; i<N; ++i){
     array[i] = result[i];
   }
}

void create_A(double k_coef, double dt, double dx, double A[][N])
{
	int i, j;
	double r = k_coef*dt/(dx*dx);
	for(i=1; i<=N-2; ++i){
		A[i][i] = 1+2*r;
		A[i][i-1] = A[i][i+1] = -r;
	}
}
