# include <cmath>
# include <cstdlib>
# include <ctime>
# include <iomanip>
# include <iostream>
# include <mpi.h>

using namespace std;

int main ( int argc, char *argv[] );
double f( double x );
void timestamp();

int main ( int argc, char *argv[] )
{
  double end_time;
  double h;
  int i;
  int id;
  int ierr;
  int m;
  int n;
  int p;
  double pi = 3.141592653589793238462643;
  int process;
  double q_global;
  double q_local;
  int received;
  int source;
  double start_time;
  MPI_Status status;
  int tag;
  int target;
  double x;
  double xb[2];
  double x_max = 1.0;
  double x_min = 0.0;

  // Establish the MPI environment.
  ierr = MPI_Init( &argc, &argv );
  // Determine this processes's rank.
  ierr = MPI_Comm_rank( MPI_COMM_WORLD, &id );
  // Get the number of processses.
  ierr = MPI_Comm_size( MPI_COMM_WORLD, &p );

  if( id == 0 )
  {
    timestamp();
    cout << "\n";
    cout << "INTERVALS - Master process:\n";
    cout << "  The number of processes is " << p << "\n";

    start_time = MPI_Wtime();

    if( p <= 1 ){
      cout << "INTERVALS - Master process:\n";
      cout << "  Need at least 2 processes!\n";
      exit( 1 );
    }
  }

  cout << "\n";
  cout << "Process " << id << ": Active!\n";

  if( id == 0 ){
    for( process = 1; process <= p-1; process++ ){
      xb[0] = ( (double)( p -process    ) * x_min
              + (double)(    process -1 ) * x_max )
              / (double)( p          -1 );
      xb[1] = ( (double)( p -process -1 ) * x_min
              + (double)(    process    ) * x_max )
              / (double)( p          -1 );

      target = process;
      tag = 1;
      ierr = MPI_Send(xb, 2, MPI_DOUBLE, target, tag, MPI_COMM_WORLD);
    }
  }
  else{
    source = 0;
    tag = 1;
    ierr = MPI_Recv( xb, 2, MPI_DOUBLE, source, tag, MPI_COMM_WORLD, &status );
  }
// Wait here until everyone has gotten their assignment.
  MPI_Barrier( MPI_COMM_WORLD );

  if( id == 0 ){
    cout << "  Subintervals have been assigned.\n";
  }
  m = 100;
  source = 0;
  ierr = MPI_Bcast( &m, 1, MPI_INT, source, MPI_COMM_WORLD );

  if( id != 0 ){
    q_local = 0.0;
    for( i = 1; i <= m; i++ ){
      x = ( ( double ) ( 2 * m - 2 * i + 1 ) * xb[0]
          + ( double ) (         2 * i - 1 ) * xb[1] )
          / ( double ) ( 2 * m             );
      q_local = q_local + f( x );
    }

    q_local = q_local * (xb[1] - xb[0]) / (double)( m );
    target = 0;
    tag = 2;
    ierr = MPI_Send( &q_local, 1, MPI_DOUBLE, target, tag, MPI_COMM_WORLD );
  }
  // Process 0 expects to receive N-1 partial results.
  else {
    received = 0;
    q_global = 0.0;
    while( received < p-1 ){
      source = MPI_ANY_SOURCE;
      tag = 2;
      ierr = MPI_Recv( &q_local, 1, MPI_DOUBLE, source, tag, MPI_COMM_WORLD, &status );
      q_global = q_global + q_local;
      received = received + 1;
    }
  }

  if( id == 0 ){
    cout << "\n";
    cout << "  Estimate for PI is " << q_global << "\n";
    cout << "  Error is " << q_global - pi << "\n";

    end_time = MPI_Wtime();
    cout << "\n";
    cout << " Elapsed wall clock seconds = " << end_time - start_time << "\n";
  }

  // Terminate MPI.
  MPI_Finalize();
  // Terminate.
  if( id == 0 )
  {
    cout << "\n";
    cout << "INTERVALS - Master process:\n";
    cout << "  Normal end of execution.\n";
    cout << "\n";
  }
  return    0;
}

void timestamp()
{
#define TIME_SIZE 40
  static char time_buffer[TIME_SIZE];
  const struct std::tm *tm_ptr;
  size_t len;
  std::time_t now;

  now = std::time( NULL );
  tm_ptr = std::localtime( &now );

  len = std::strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm_ptr );
  std::cout << time_buffer;
  return;
#undef TIME_SIZE

}

double f( double x )
{
  double value;
  value = 4.0 / ( 1.0 + x * x );
  return value;
}
