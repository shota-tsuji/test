#include <iostream> // for cout
#include <math.h> // for fabs()
#include <stdio.h> // for printf()

#define f(x) (x * x * x - x + 1 )
// f(x) の1階微分
#define g(x) (3 * x * x - 1 )

using namespace std;

// 計算クラス
class Calc
{
  //constexpr static const double eps = 1e-08; // 打ち切り誤差（制度）
  static constexpr double eps = 1e-08; // 打ち切り誤差（制度）
  static const int limit = 50; // 打ち切り回数

  // 変数
  double x, dx;
  int k;

public:
  // 非線形方程式を解く（ニュートン法）
  void calcNonlinearEquation();
};

void Calc::calcNonlinearEquation()
{
  // x initialization
  x = -2.0;

  // うち基地回数 or 打ち切り誤差になるまでloop
  for( k = 1; k <= limit; k++)
  {
    dx = x;
    x = x - f(x) / g(x);
    printf("x=%f\n", x);
    if( fabs(x - dx) / fabs(dx) < eps ){
      printf("x=%f\n", x);
      break;
    }
  }

  // 収束しなかった場合
  if( k > limit ){
    cout << "Failed to converge" << endl;
  }
}


int main()
{
  try
  {
    // 計算クラスインスタンス化
    Calc objCalc;

    // 非線形方程式を解く
    objCalc.calcNonlinearEquation();
  }
  catch (...) {
    cout << "Exception happened." << endl;
    return -1;
  }

  return 0;
}
