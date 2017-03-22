#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void saveArray( vector< vector<double> > &u, int nx, int nt, double dx, double dt, int c );

int main()
{
  int nx = 20;
  int nt = 50;
  double dx = double(2)/(nx-1);
  double dt = 0.01;
  int c = 5;

  vector< vector<double> > u(nx, vector<double> (nt));
  vector< vector<double> > un(nx, vector<double> (nt));
  // Initial condition:
  for( int i=0; i <= nx-1; i++){
    if(i*dx >= 0.5 && i*dx <= 1){
      u[i][0] = 2;
    }
    else {
      u[i][0] = 1;
    }
  }

  // Finite-difference loop:
  for(int it=1; it<=nt-1; it++){
    for(int k=0; k<nx-1; k++){
      un[k][it-1] = u[k][it-1];
    }
    for(int i=1; i<=nx-1; i++){
      u[0][it] = un[1][it-1];
      u[i][it] = un[i][it-1] - c*dt/dx*(un[i][it-1]-un[i-1][it-1]);
    }
  }

  saveArray(u, nx, nt, dx, dt, c);
  return 0;
}


void saveArray( vector< vector<double> > &u, int nx, int nt, double dx, double dt, int c )
{
  ofstream myfile;
  myfile.open("1d_convection02.dat");
  myfile << "%\t" << "nx = " << nx << "\tnt = " << nt << "\tdt = " << dt << "\tc = " << endl;

  for(int i=0; i<=nx-1; i++){
    myfile << i*dx << "\t\t";
    for(int j=0; j<=nt-1; j++){
      myfile << u[i][j] << "\t\t";
    }
    myfile << endl;
  }
}
