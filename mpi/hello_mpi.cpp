#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <mpi.h>

using namespace std;

int main( int argc, char *argv[] );
void timestamp();

int main( int argc, char *argv[] )
{
  int id;
  int ierr;
  int p;
  double wtime;

  ierr = MPI_Init( &argc, &argv );
  ierr = MPI_Comm_size( MPI_COMM_WORLD, &p );
  ierr = MPI_Comm_rank( MPI_COMM_WORLD, &id );
  // Process 0 prints an initroductory message.
  if( id == 0 ){
    timestamp();
    cout << "\n";
    cout << "HELLO_MPI - Master process:\n";
    cout << "  The number of process is " << p << "\n ";
  }

  // Every process prints a hello.
  if( id == 0 ){
    wtime = MPI_Wtime();
  }
  cout << "  Process " << id << " says 'Hello, world!'\n ";

  if( id == 0 ){
    wtime = MPI_Wtime() - wtime;
    cout << "  Elapsed wall clock time = " << wtime << " seconds.\n ";
  }

  MPI_Finalize();
  return 0;
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
