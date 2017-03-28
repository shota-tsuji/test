// Array incriment
#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"
//#define N 100000
#define N 16


int main(int argc, char *argv[])
{
  int i;
  int *rootBuf;
  int *localBuf;

  int nproc;
  int myrank;
  char hostName[MPI_MAX_PROCESSOR_NAME];
  int nameLength;
  int length;

  // MPI Setup
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &nproc);
  MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

  MPI_Get_processor_name(hostName, &nameLength);
  //fprintf(stdout, ": myrank=0, nproc=0\n", hostName, myrank, nproc);
  fflush(stdout);

  // Only root initialize Array
  if( myrank==0 ){
    rootBuf = (int *) malloc( N * sizeof(int) );
    for( i=0; i<N; i++){
      rootBuf[i] = i;
    }
  }

  // local Buf
  length = N / nproc;
  localBuf = (int *) malloc (  length * sizeof(int) );

  // bunpai
  MPI_Scatter(rootBuf, length, MPI_INT, localBuf, length, MPI_INT, 0, MPI_COMM_WORLD);

  // Incriment
  for( i=0; i<length; i++){
    localBuf[i] = localBuf[i] + 1;
  }

  // syuyaku
  MPI_Gather(localBuf, length, MPI_INT, rootBuf, length, MPI_INT, 0, MPI_COMM_WORLD);

  if(myrank==0){
    printf("\n");
    for(i=0; i<N; i++){
      printf("rootBuf[%d] = %d\n", i, rootBuf[i]);
    }
  }

  free(localBuf);
  if(myrank==0){
    free( rootBuf );
  }

  MPI_Finalize();
  return 0;
}
