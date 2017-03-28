// Array incriment
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
//#define N 100000
#define N 16


int main(int argc, char *argv[])
{
  int i;
  int *rootBuf;
  int num_of_threads;

  if(argc!=2){
    printf("usage: a.out <number of threads>\n");
    return 1;
  }

  num_of_threads = atoi(argv[1]);
  omp_set_num_threads(num_of_threads);
  rootBuf = (int *) malloc( N * sizeof(int) );

  for( i=0; i<N; i++){
    rootBuf[i] = i;
  }

#pragma omp parallel
  //printf("Exec by thread 0 (total 0 threads)\n", omp_get_thread_num(), omp_get_num_threads() );
  printf("Exec by thread %d (total %d threads)\n", omp_get_thread_num(), omp_get_num_threads() );
#pragma omp for
  for(i=0; i<N; i++){
    rootBuf[i] = rootBuf[i] + 1;
  }

  printf("\n");
  for(i=0; i<N; i++){
    printf("rootBuf[%d] = %d\n", i, rootBuf[i]);
  }

  free( rootBuf );
  return 0;
}
