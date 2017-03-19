#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <cmath>

using namespace std;

int main();
void u0( double a, double b, double t0, int n, double x[], double value[] );

int main()
{
  double *a, *b, *fvec;
  bool header;
  int i, info, j, job;
  double k;
  double *t;
  double t_delt;
  string t_file;
  double t_max, t_min;
  int t_num;
  double *u;
  string u_file;
  double w;
  double *x;
  double x_delt;
  string x_file;
  double x_max, x_min;
  int x_num;

  cout << "FD1D_HEAT_IMPLICIT\n";
  k = 5.0E-07;
  x_min = 0.0;
  x_max = 0.3;
  x_num = 11;
  x_delt = ( x_max - x_min ) / (double) ( x_num -1 );
  x = new double[x_num];
  for( i=0; i<x_num; i++ ){
    x[i] = ( (double)(x_num -i -1)*x_min
            +(double)(       i   )*x_max )
            /(double)(x_num    -1);
  }

  t_min = 0.0;
  t_max = 22000.0;
  t_num = 51;
  t_delt = (t_max - t_min) / (double)(t_num -1);
  t = new double[t_num];
  for( j=0; j<t_num; j++ ){
    t[i] = ( (double)(t_num -j -1)*t_min
            +(double)(       j   )*t_max )
            /(double)(t_num    -1);
  }

  // Set the initial data, for time t_min.
  u = new double[x_num * t_num];
  u0( x_min, x_max, t_min, x_num, x, u);

  w = k * t_delt / x_delt / x_delt;
  a = new double[3*x_num];
  a[0+0*3] = 0.0;
  a[1+0*3] = 1.0;
  a[0+1*3] = 0.0;
  for( i=1; i<x_num - 1; i++ ){
    a[2+(i-1)*3] = -w;
    a[1+ i   *3] = 1.0 + 2.0 * w;
    a[0+(i+1)*3] = -w;
  }
  a[2+(x_num-2)*3] = 0.0;
  a[1+(x_num-1)*3] = 1.0;
  a[2+(x_num-1)*3] = 0.0;
  
}


void u0( double a, double b, double t0, int n, double x[], double value[] )
{
  int i;
  for( i=0; i<n; i++ ){
    value[i] = 100.0;
  }
  return;
}
