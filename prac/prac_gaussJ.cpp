#include <iostream>
#include <stdio.h>

// 方程式の元の数
#define N 3 // 4

using namespace std;

class Calc
{
  static double a[N][N + 1]; // 係数行列

  double p, d; // ピポット係数，ピポット行×係数
  int i, j, k;

public:
  Calc();
  void calcGaussJorden();
};

/*Calc::Calc()
{
  // 係数
  Calc::a[N][N + 1] = {
    { 2.0, -3.0, 1.0, 5.0},
    { 1.0, 1.0, -1.0, 2.0},
    { 3.0, 5.0, -7.0, 0.0},
  };

  cout << "Constracter finished." << endl;
}
*/

Calc::Calc() : a {
    { 2.0, -3.0, 1.0, 5.0},
    { 1.0, 1.0, -1.0, 2.0},
    { 3.0, 5.0, -7.0, 0.0},
  }
{
}

void Calc::calcGaussJorden()
{
  // 係数
  /*Calc::a[N][N + 1] = {
    { 2.0, -3.0, 1.0, 5.0},
    { 1.0, 1.0, -1.0, 2.0},
    { 3.0, 5.0, -7.0, 0.0},
  };
  */

  // 連立方程式を出力
  for (i = 0; i < N; ++i) {
    for( j = 0; j < N; ++j){
      printf( "%+fx%d ", a[i][j], j + 1);
    }
    printf( "= %+f\n", a[i][N]);
  }

  for( k = 0; k < N; ++k){
    // ピポット係数(kがピポット行)
    p = a[k][k];

    // ピポット行をpで除算
    for( j = k; j < N+1; j++) a[k][j] = a[k][j] / p;

    // ピポット列の掃き出し
    for( i = 0; i < N; i++){
      if( i != k){
        d = [i][k];
        for( j = k; j < N+1; j++) a[i][j] = a[i][j] - d * a[k][j];
      }
    }
  }

  // 結果出力
  for( k = 0; k < N; k++ ) printf("x%d = %f\n", k + 1, a[k][N]);
}

int main()
{
  try
  {
    // 計算クラスインスタンス化
    Calc objCalc;
    // 連立方程式を解く（ガウス・ジョルダン法）
    objCalc.calcGaussJorden();
  }
  catch (...) {
    cout << "Exception happened." << endl;
    return -1;
  }

  return 0;
}
