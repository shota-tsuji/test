#include <iostream>
#include <vector>
#include <algorithm> // copy
#include <iterator> // back_inserter
#include <fstream> // output file
using namespace std;

#define N 5

int main()
{
  //vector<double> T(N);
  vector<double> T{0, 100, 0, 0, 100};
  vector<double> T1(N);
  double dx = 0.2;
  double dt = 0.01;
  double k = 1;
  const int loop = 25;

  T1[0] = T[0];
  T1[N-1] = T[N-1];

  ofstream outfile;
  outfile.open("result.csv");
  for(int step=0; step<loop; ++step){
    cout << T[0] << " ";
    outfile << T[0];
    for(auto it=T.begin()+1; it!=T.end(); ++it){
      cout << *it << " ";
      outfile << "," << *it;
    }
    cout << endl;
    outfile << endl;

    for(int i=1; i<N-1; ++i){
      T1[i] = T[i] + k*dt/(dx*dx) * (T[i-1] -2.0*T[i] + T[i+1]);
    }
    T.clear();
    copy(T1.begin(), T1.end(), back_inserter(T));

  }

  return 0;
}
