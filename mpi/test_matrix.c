#include <stdio.h>
#include "./matrix.c"
#define N 5

int main()
{
	double dx = 0.2;
	double dt = 0.01;
	double k_coef = 1;
	double A[N][N] = {0};

	create_A(k_coef, dt, dx, A);
	printMatrix(A, N);
	dt = 0.5;
	create_A(k_coef, dt, dx, A);
	printMatrix(A, N);


	return 0;
}
