#include <stdio.h>
#include <stdlib.h>

#define NUM 100000

double rnd( void );

int main( void )
{
  double x, y, pai;
  int i, in=0;

  for( i = 0; i<NUM; i++ ) {
    x = rnd();
    y = rnd();
    // x^2 + y^2 = 1 で定義された円の内部（境界含む）にプロットされた回数をカウント
    if ( x * x + y * y <= 1 ) { in++; }
  }
  pai = (double) 4 * in / NUM;
  printf( "The value of pai = %f\n", pai );

  return 0;
}

double rnd( void )
{
  // 0~1 の乱数
  return (double) rand() / ( RAND_MAX + 0.1 );
}
