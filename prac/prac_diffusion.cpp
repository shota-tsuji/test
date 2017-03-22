#include <iostream>
using namespace std;

double f( double x )
{
  return 1.0 + x/1.0 + x*x/2.0 + x*x*x/3.0 + x*x*x*x/4.0;
}

/*
double df_dx( double x )
{
  return 1.0 + x + x*x + x*x*x;
}
*/

double d2f_dx2( double x )
{
  return 1.0 + 2.0*x + 3.0*x*x;
}

int main()
{
  double x=2;
  double dx = 0.05;
  //cout << f( x );
  double result;
  //result = (f(x+dx) - f(x)) / dx;
  result = (f(x+dx) -2*f(x) + f(x-dx)) / (dx * dx);
  cout << d2f_dx2(x) << endl;
  cout << result << endl;
  return 0  ;
}
