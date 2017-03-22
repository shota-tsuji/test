#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  cout << "Enter an initial guess: ";
  double x;
  cin >> x;

  double tol = 1e-12;
  double error = tol + 1;
  int it = 0;
  int max_it = 100;

  double x1;
  while(error > tol && it < max_it){
    x1 = x - (x*x-1) / (2*x);
    error = fabs(x1 - x);
    x = x1;
    it++;
    cout << error << endl;
  }

  if(error <= tol){
    cout << "The root is " << x << endl;
  }
  else{
    cout << "Error, no converge." << endl;
  }

  cin.get();
  cin.get();
  return 0;
}
