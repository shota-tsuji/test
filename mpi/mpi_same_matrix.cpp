// LU分解後の行列を，送る．各プロセスで行列ベクトル積をする．
#include <iostream>
#include <vector>
#include <mpi.h>
#include <stdlib.h>
using namespace std;

int **alloc_2d_int(int rows, int cols)
{
	int *data = (int *)malloc(rows*cols*sizeof(int));
	int **array = (int **)malloc(rows*sizeof(int));
	for(int i=0; i<rows; i++){
		array[i] = &(data[cols*i]);
	}
}
int main()
{
	int **A;
	int N, M;
	cin >> N >> M;

	A = alloc_2d_int(N, M);
	for(int i=0; i<N; ++i){
		for(int j=0; j<M; ++j){
			A[i][j] = i * 10 + j;
		}
	}
}
