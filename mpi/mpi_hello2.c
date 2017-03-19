#include <mpi.h>
#include <stdio.h>

int main( int argc, char** argv )
{
  MPI_Init( NULL, NULL );

  int world_size;
  MPI_Comm_size( MPI_COMM_WORLD, &world_size );

  
}
