#include <iostream>
#include <vector>
using namespace std;

void print_vv( vector< vector<double> >& vv);

#define N 4

int main()
{
  const int n = 4; // n*n matrix
  vector< vector<double> > A = {{1, 2, 3, 4},
                                {2, 6, 7, 10},
                                {2, 2, 8, 7},
                                {0, -4, 7, 1}};
  vector< vector<double> > L, U;
  L.resize( n, vector<double>(n, 0) );
  U.resize( n, vector<double>(n, 0) );
  /*
  for(int i = 0; i<N; i++){
    U[0][i] = A[0][i];
  }
  for(int i = 0; i<N; i++){
    L[i][i] = 1;
  }
  for(int i = 0; i<N; i++){
  //    for(int k = 1; k<j; ){}
      L[j][0] = A[0][j] / U[0][0];
    for(int j = 0; j!=i; j++){
    }
  }
  */
  for(int i = 0; i < n; ++i){
    // L_ij
    for(int j = 0; j<=i; ++j){
      double lu = A[i][j];
      for(int k = 0; k < j; ++k){
        lu -= A[i][k]*A[k][j]; // L_ik * U_kj . Modify L
      }
      A[i][j] = lu;
    }

    // U_ij
    for(int j = i+1; j < n; ++j){
      double lu = A[i][j];
      for(int k = 0; k < i; ++k){
        lu -= A[i][k]*A[k][j]; // L_ik * U_kj
      }
      A[i][j] = lu/A[i][i];
    }
  }


  //print_vv( L );
  //print_vv( U );
  print_vv(A);

  return 0;
}

void print_vv( vector< vector<double> >& vv)
{
  for( auto p = vv.begin(); p != vv.end(); ++p){
    for( auto q = p->begin(); q != p->end(); ++q){
      cout << *q << " ";
    }
    cout << endl;
  }
}
