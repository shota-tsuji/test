// Trapezoidal Method for the evaluation of Define Integrals
#include <iostream>
#include <cmath>
using namespace std;

double f( double x )
{
  //return (double) sin( x );
  return (double) cos( x );
}

int main()
{
  int n, i; // n is for subintervals and i if for loop.
  double a, b, h, sum = 0, integral;

  cout << "Enter the limits of integration,\nInitial limit, a=";
  cin >> a;
  cout << "Final limit, b=";
  cin >> b;
  cout << "Enter the no. of subintervals, n=";
  cin >> n;

  double x[n+1], y[n+1];
  h = ( b - a ) / n; // get the width of the subintervals.
  for( i=0; i<=n; i++ ){
    x[i] = a + i*h;
    y[i] = f( x[i] );
  }
  for( i=1; i<n; i++ ){ // loop to evaluate h*(y1+...+yn-1)
    sum = sum + h*y[i];
  }
  integral = h / 2.0 * (y[0] + y[n]) + sum;
  cout << "The definite integral is " << integral << endl;
  return 0;
}
