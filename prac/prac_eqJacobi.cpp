// Jacobi iterative method
/*
  @param[input] A n*nの係数行列とn*1の定数項bを併せたn*(n+1)の拡大行列．n+1列目に解が入る．
  @param[input] n  n元連立一次方程式
  @param[input] max_iter  最大反復数（反復終了後，実際の反復数を返す）
  @param[input] eps  許容誤差（反復終了後，実際の誤差を返す）
  @return 1:成功，0:失敗
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <fstream>
#include <sstream> // 文字ストリーム
using namespace std;

int JacobiIteration( vector< vector<double> > &A, int n, int &max_iter, double &eps );
void print_vv( vector< vector<double> >& vv );
void load_csv( string filename, vector< vector<double> >& vv );

int main( int argc, char* argv[] ){
  //string filename = "./data2.txt";
  string filename( argv[1] );
  int max_iter = stoi( argv[2] );
  double eps = 1.0e-06;
  int n;

  vector< vector<double> > A;
  load_csv(filename, A);
  print_vv( A );
  return 0;

  int status = JacobiIteration(A, n, max_iter, eps);

  if( status ) {
    for(int i = 0; i < n; ++i ){
      printf( "x%d = %f\n", i+1, A[i][n] );
    }
    printf( "number of repetition: %d\n", max_iter );
    printf( "error of answers: %f\n", eps );
  }
  else{
    printf( "Failed to solve this equation." );
  }

  return 0;
}


int JacobiIteration( vector< vector<double> > &A, int n, int &max_iter, double &eps )
{
  vector<double> x(n, 0.0); // 初期値はすべて0とする
  vector<double> y(n, 0.0);

  double e = 0.0;
  int k;
  for( k = 0; k < max_iter; ++k )
  {
    // 現在の値を代入して，次の解候補を計算
    for(int i = 0; i < n; ++i ){
      y[i] = A[i][n];
      for(int j = 0; j < n; ++j ){
        y[i] -= ( j != i ? A[i][j]*x[j] : 0.0);
      }
      y[i] /= A[i][i];
    }

    // 収束判定
    e = 0.0;
    for( int i = 0; i < n; ++i ){
      e += fabs( y[i] - x[i] ); // 絶対誤差の場合
      // e += fabs( (y[i] - x[i]) / y[i] ); // 相対誤差の場合
    }
    if( e <= eps ){ break; }

    swap(x, y);
  }

  max_iter = k;
  eps = e;

  for( int i = 0; i < n; ++i ){
    A[i][n] = y[i];
  }

  return 1;
}

void print_vv( vector< vector<double> >& vv )
{
  /*
  auto it = vv.begin();
  while( it != vv.end() ){
    auto it_in = ( *it ).begin();
    for( ; it_in != it_in.end() -1; ++it_in ){
      cout << *it_in << ',' ;
    }
    cout << *it_in << endl;
    ++it;
  }
  */

  for( auto p = vv.begin(); p != vv.end(); ++p ){
    for( auto q = p->begin(); q != p->end(); ++q ){
      cout << *q << " ";
    }
    cout << endl;
  }
}

void load_csv( string filename, vector< vector<double> >& vv )
{
  ifstream ifs( filename );
  string str;
  vector<double> one_row;

  while( getline( ifs, str) ){
    one_row.clear();
    string token;
    istringstream stream( str );

    // 1行のうち，文字列とコンマを分割する
    while( getline( stream, token, ',' ) ){
      one_row.push_back( stod( token ) );
    }
    vv.push_back( one_row );
  }
}

  /*
  getline(ifs, str);
  sscanf( str.data(), "%d", &n );
  vector< vector<double> > A;
  // csvファイルを1行ずつ読み込む
  for( int i = 0; i < n; ++i ){
    string token;
    istringstream stream(str);
    vector<double> one_row;

    // 1行のうち，文字列とコンマを分割する
    while( getline( stream, token, ',' ) ){
      double temp = stod( token );
      one_row.push_back( temp );
    }
    for( auto it = one_row.begin(); it != one_row.end(); ++it ){
      cout << *it << " ";
    }
    cout << endl;
  }
  */

  /*
  vector<double> one_row;
  while( getline( ifs, str) ){
    one_row.clear();
    string token;
    istringstream stream( str );

    // 1行のうち，文字列とコンマを分割する
    while( getline( stream, token, ',' ) ){
      //cout << stod( token ) << ",";
      one_row.push_back( stod( token ) );

    }
    for( auto it = one_row.begin(); it != one_row.end(); ++it ){
      cout << *it << ' ';
    }
    cout << endl;
    A.push_back( one_row );
  }
  */
