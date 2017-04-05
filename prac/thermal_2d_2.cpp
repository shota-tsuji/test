#include <iostream>
#include <vector>
#include <algorithm> // copy
#include <iterator> // back_inserter
#include <fstream> // output file
using namespace std;

#define N 4

void print_T_1d(const double * T, int n)
{
	cout << "------------------------------------" << "\n";
  for(int i=0; i<n; ++i){
	  int j=0;
	  for(j=0; j<n-1; ++j){
		  cout << T[i] << " ";
	  }
	  cout << T[i] << "\n";
  }
}

void print_T_2d(const double A[][N], int n)
{
	cout << "------------------------------------" << "\n";
  for(int i=0; i<n; ++i){
	  int j=0;
	  for(j=0; j<n-1; ++j){
		  cout << A[i][j] << " ";
	  }
	  cout << A[i][j] << "\n";
  }
}

void output_file_T(ofstream& outfile, double const * T, int n)
{
  int i=0;
	for(int i=0; i<n; ++i){
	  int j=0;
	  for(j=0; j<n-1; ++j){
		  outfile << T[i] << ",";
	  }
	  outfile << T[i] << "\n";
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

  double T[N*N] = {0, 0, 100, 0, 0, 100, 0, 0, 100};
  double T1[N];
  double A[N][N];

  for(int i=0; i<N; ++i){
	  for(int j=0; j<N; ++j){
		  A[i][j] = 0.0;
	  }
	  A[i][i] = 1.0;
  }

  for(int i=N+1; i<N*(N-1); i+=3){
	  int index=i;
	  for(int index=i; index<)
	  // j-N and j+N are strid.
	  for(int j=index-N; j<=index+N; ++j){
		  cout << "index-"<< index << "-> " << i << ": " << j << "\n";
		  if( j==index-N || j==index-1 || j==index+1 || j==index+N){
			  A[index][j] = -r;
		  }
		  else if(j==index){
			  A[index][j] = 1+4*r;
		  }
		  ++i;
	  }
  }

  print_T_2d(A, N);
  return 0;

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
		}
	}
    for(int i=1; i<N-1; ++i){
		for(int j=1; j<N-1; ++j){
			T[i] = T1[i];
		}
    }
    print_T_1d(T, N);
    output_file_T(outfile, T, N);
  }

  return 0;
}
