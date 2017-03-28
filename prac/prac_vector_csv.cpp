#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
  vector<int> v;
  for(int i=0; i<20; ++i){
    //v[i] = i;
    v.push_back(i);
  }

  ofstream outfile;
  outfile.open("./result.csv");
  outfile << v[0];
  for(auto it=v.begin()+1; it!=v.end(); ++it){
    outfile << "," << *it;
  }
  outfile << endl;

  return 0;
}
