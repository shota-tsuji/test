#include <iostream>
#include <cmath>
using namespace std;

double f( double x)
{
  return ( 1.0 / (x+1) );
}

void print_status( double n, double dx, double low, double high )
{
  cout << "dx = " << dx << ", Num of Seguments = " << n << "\n";
  cout << "low = " << low << ", high = " << high << endl;
  return;
}

int main()
{
  cout.precision(4);
  cout.setf(ios::fixed);
  const int n = 20;
  //const int i = 10;
  const double low = 2.0, high = 3.0;
  double mid, sum = 0, integral, h;
  double x[n+1], y[n+1];
  h = ( high - low ) / n;
  print_status(n, h, low, high);

  for(int i=0; i<n+1; i++){
    x[i] = low + h * i;
    y[i] = f( x[i] );
  }
  for(int i=1; i<n; i+=2){
    sum += 4.0 * y[i]; // Odds
  }
  for(int i=2; i<n; i+=2){
    sum += 2.0 * y[i]; // Evens
  }
  integral = h / 3.0 * (y[0] + sum + y[n] );
  cout << "-------integral(Simpsons' Rule)----------" << "\n";
  cout << "Result =" << integral << endl;
  return 0;
}
