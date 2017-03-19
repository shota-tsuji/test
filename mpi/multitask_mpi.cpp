#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <mpi.h>

using namespace std;

int main( int argc, char *argv[] );
void p0_set_input( int *input1, int *input2 );
void p0_send_input( int input1, int input2 );
void p0_receive_output( int *output1, int *output2 );
int p1_receive_input();
int p1_compute_output( int input1 );
void p1_send_output( int output1 );
int p2_receive_input();
int p2_compute_output( int input2 );
void p2_send_output( int output2 );
void timestamp();

int main( int argc, char *argv[] )
{
  int id;
  int input1, input2;
  int output1, output2;
  int p;
  double wtime;

  ierr = MPI_Init( &argc, &argv );
  ierr = MPI_Comm_rank( MPI_COMM_WORLD, &id );
  ierr = MPI_Comm_size( MPI_COMM_WORLD, &p );

  if( p < 3 ){
    printf( "\n" );
    printf( "MPI_MULTITASK - Fatal error!\n" );
    MPI_Finalize();
    exit( 1 );
  }

  if( id == 0 ){
    timestamp();
    printf( "\nMPI_MULTITASK:\n");
    wtime = MPI_Wtime();
    p0_set_input( &input1, &input2 );
    p0_send_input( input1, input2 );
    p0_receive_output( &output1, &output2 );

    wtime = MPI_Wtime() - wtime;
    printf( "  Process 0 time = %g\n", wtime );

    MPI_Finalize();
    printf( "  Normal end of ececution.\n" );
    timestamp();
  }
  else if ( id == 1 ){
    wtime = MPI_Wtime();
    input1 = p1_receive_input();
    output1 = p1_compute_output( input1 );
    p1_send_output( output1 );
    wtime = MPI_Wtime() - wtime;
    printf( "  Process 1 time = %g\n", wtime );
    MPI_Finalize();
  }else if ( id == 2 ){
    wtime = MPI_Wtime();
    input2 = p2_receive_input();
    output2 = p2_compute_output( input2 );
    p2_send_output( output2 );
    wtime = MPI_Wtime() - wtime;
    printf( "  Process 2 time = %g\n", wtime );
    MPI_Finalize();
  }
  return 0;
}

void p0_set_input( int *input1, int *input2 )
{
  
}
