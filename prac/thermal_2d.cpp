#include <iostream>
#include <vector>
#include <algorithm> // copy
#include <iterator> // back_inserter
#include <fstream> // output file
using namespace std;

#define N 10

void print_T(const double T[][N], int n)
{
	cout << "------------------------------------" << "\n";
  for(int i=0; i<n; ++i){
	  int j=0;
	  for(j=0; j<n-1; ++j){
		  cout << T[i][j] << " ";
	  }
	  cout << T[i][j] << "\n";
  }
}

void output_file_T(ofstream& outfile, double const T[][N], int n)
{
  int i=0;
	for(int i=0; i<n; ++i){
	  int j=0;
	  for(j=0; j<n-1; ++j){
		  outfile << T[i][j] << ",";
	  }
	  outfile << T[i][j] << "\n";
  }
}


int main()
{
  double h = 0.2; // dx = dy = h.
  double dt = 0.01;
  double k = 1;
  double r = k*dt/(h*h);
  double T0 = 0, Tw = 100;
  const int loop = 30;

  double T[N][N] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 100},
	  				{0, 0, 0, 0, 0, 0, 0, 0, 0, 100},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 100},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 100},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 100},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 100},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 100},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 100},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 100},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 100}};
  double T1[N][N];
  double A[N][N] = {
   {1, 0, 0, 0, 0},
   {-r, 1+2*r, -r, 0, 0},
   {0, -r, 1+2*r, -r, 0},
   {0, 0, -r, 1+2*r, -r},
   {0, 0, 0, 0, 1}   };

  ofstream outfile;
  outfile.open("result2.csv");
  /*
  for(int i=0; i<N; ++i){
    for(int j=0; j<=i; ++j){
      double lu = A[i][j];
      for(int k=0; k<j; ++k){
        lu -= A[i][k]*A[k][j]; // l_ik * u_kj
      }
      A[i][j] = lu;
    }

    for(int j=i+1; j<N; ++j){
      double lu = A[i][j];
      for(int k=0; k<i; ++k){
        lu -= A[i][k]*A[k][j]; // l_ik * u_kj
      }
      A[i][j] = lu/A[i][i];
    }
  }
  */


  for(int step=0; step<loop; ++step){

    // 前進代入
	/*
    for(int i=0; i<N; ++i){
      double bly = T[i];
      for(int j=0; j<i; ++j){
        bly -= A[i][j]*T1[j];
      }
      T1[i] = bly/A[i][i];
    }

    // 後退代入
    // T1[]は，未知ベクトル, 上のT[]が既知ベクトル
    for(int i=N-1; i>=0; --i){
      double yux = T1[i];
      for(int j=i+1; j<N; ++j){
        yux -= A[i][j]*T1[j];
      }
      T1[i] = yux;
    }
	*/

	for(int i=1; i<N-1; ++i){
		for(int j=1; j<N-1; ++j){
			T1[i][j] = T[i][j] + k*dt/(h*h) * (T[i-1][j]+T[i][j-1]-4*T[i][j]+T[i][j+1]+T[i+1][j]);
		}
	}
    for(int i=1; i<N-1; ++i){
		for(int j=1; j<N-1; ++j){
			T[i][j] = T1[i][j];
		}
    }
    print_T(T, N);
    output_file_T(outfile, T, N);
  }

  return 0;
}
