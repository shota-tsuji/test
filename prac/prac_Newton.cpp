#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
  char zzz;
  const char filepath[] = "./output.txt";
  const char ErrorMessage[] = "Can't open file ";
  fstream OutStream(filepath, ios::out);
  int i;
  double x, x1; //user input value
  double f, dfdx; // function and its derivative
  const double epsilon = 0.0000001;
  const int n = 15; // max number of steps

  if( OutStream.fail() ){
    cerr << ErrorMessage << filepath;
    cin >> zzz;
    exit(-1);
  }
  cout << "Current Function: x^3 - 10x^2 + 22x + 6" << "\n";
  cout << "Enter starting value x: ";
  cin >> x1;
  cout << 1 << " " << x1 << "\n";
  OutStream << "1" << "," << x1;

  for(i=2; i<=n; i++){
    x = x1;
    f = ( (x*x*x)-(10*x*x) + (22*x) +6 );
    dfdx = ( (3*x*x)-(20*x)+22 );
    x1 = x - f/dfdx;
    cout << i << " " << x1 << "\n";
    OutStream << i << ", " << x1 << ", ";

  // Checks for convergence and ends loop if conditions met.
    while( abs(x-x1) < epsilon){
      cout << "\n" << "The root is " << x1 << ".";
      return 0;
    }
  }
  cerr << "The value did not converge.";
  return 0;
}
