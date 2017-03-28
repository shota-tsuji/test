#include <iostream>
#include <vector>
#include <algorithm> // copy
#include <iterator> // back_inserter
#include <fstream> // output file
using namespace std;

#define N 5

// return: success 1, fail 0.
int LUDecomp(vector< vector<double> > &A, int n)
{
  if(n <= 0) return 0;

  for(int i=0; i<n; ++i){
    for(int j=0; j<=i; ++j){
      double lu = A[i][j];
      for(int k=0; k<j; ++k){
        lu -=A[i][k]*A[k][j]; // l_ik * u_kj
      }
      A[i][j] = lu;
    }

    // u_ij (i < j)
    for(int j=i+1; j<n; ++j){
      double lu = A[i][j];
      for(int k=0; k<i; ++k){
        lu -= A[i][k]*A[k][j]; // l_ik * u_kj
      }
      A[i][j] = lu/A[i][j];
    }
  }

  return 1;
}

int LUSolver(const vector< vector<double> > &A, const vector<double> &b, vector<double> &x, int n)
{
  if(n <= 0) return 0;

  // calculate Y from LY=b. Forward substitution
  for(int i=0; i<n; ++i){
    double bly = b[i];
    for(int j=0; j<i; ++j){
      bly -= A[i][j]*x[j];
    }
    x[i] = bly/A[i][i];
  }

  // calculate X form UX=Y. Back substitution
  for(int i=n-1; i>=0; --i){
    double yux = x[i];
    for(int j=i+1; j<n; ++j){
      yux -= A[i][j]*x[j];
    }
    x[i] = yux;
  }

  return 1;
}

int GaussElimination(vector< vector<double> > &A, int n)
{
  // Forward elimination. Upper trigonal matrix.
  for(int k=0; k<n-1; ++k){
    double akk = A[k][k];
    for(int i=k+1; i<n; ++i){
      double aik = A[i][k];
      for(int j=k; j<n+1; ++j){
        A[i][j] = A[i][j]-aik*(A[k][j]/akk);
      }
    }
  }

  // Back substitution
  A[n-1][n] = A[n-1][n]/A[n-1][n-1];
  for(int i=n-2; i>=0; --i){
    double ax = 0.0;
    for(int j=i+1; j<n; ++j){
      ax += A[i][j]*A[j][n];
    }
    A[i][n] = (A[i][n]-ax)/A[i][i];
  }

  return 1;
}

int main()
{
  double dx = 0.2;
  double dt = 0.01;
  double k = 1;
  double r = k*dt/(dx*dx);
  double T0 = 0, Tw = 100;
  //vector<double> T(N);
  vector<double> T{0, 0, 0};
  vector< vector<double> > B{{1+2*r, -r, 0},
                             {-r, 1+2*r, -r},
                             {0, 0, -r, 1+2*r}};
  vector<double> T1(N-2);
  const int loop = 25;

  T1[0] = T[0];
  T1[N-1] = T[N-1];

  ofstream outfile;
  outfile.open("result2.csv");
  //LUDecomp(B, N-2);
  //LUSolver(B, T, T1, N-2);
  for(int step=0; step<loop; ++step){
    //cout << T[0] << " ";
    cout << T0 << " ";
    outfile << T0;
    /*
    for(auto it=T.begin(); it!=T.end(); ++it){
      cout << *it << " ";
      outfile << "," << *it;
    }
    */
    cout << " " << Tw << endl;
    outfile << "," << Tw << endl;

    /*
    for(int i=1; i<N-1; ++i){
      T1[i] = T[i] + k*dt/(dx*dx) * (T[i-1] -2.0*T[i] + T[i+1]);
    }
    */
    //LUSolver(B, T, T1, N-2);
    for(auto it=T.begin(); it!=T.end(); ++it){
      cout << *it << " ";
    }
    T.clear();
    copy(T1.begin(), T1.end(), back_inserter(T));

  }

  return 0;
}
