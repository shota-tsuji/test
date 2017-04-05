#include <iostream>
#include <vector>
#include <algorithm> // copy
#include <iterator> // back_inserter
#include <fstream> // output file
using namespace std;

#define N 5

void print_T(double const * T, int n)
{
  int i=0;
  for(i=0; i<n-1; ++i){
    cout << T[i] << " ";
  }
  cout << T[i] << "\n";
}

void output_file_T(ofstream& outfile, double const * T, int n)
{
  int i=0;
  for(i=0; i<n-1; ++i){
    outfile << T[i] << ",";
  }
  outfile << T[i] << "\n";
}

int main()
{
  double dx = 0.2;
  double dt = 0.01;
  double k = 1;
  double r = k*dt/(dx*dx);
  double T0 = 0, Tw = 100;
  const int loop = 15;

  double T[N] = {0, 0, 0, 0, 100};
  double T1[N];
  double A[N][N] = {
   {1, 0, 0, 0, 0},
   {-r, 1+2*r, -r, 0, 0},
   {0, -r, 1+2*r, -r, 0},
   {0, 0, -r, 1+2*r, -r},
   {0, 0, 0, 0, 1}   };

  ofstream outfile;
  outfile.open("result2.csv");
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


  for(int step=0; step<loop; ++step){

    // 前進代入
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

    for(int i=0; i<N; ++i){
      T[i] = T1[i];
    }
    print_T(T, N);
    output_file_T(outfile, T, N);
  }

  return 0;
}
