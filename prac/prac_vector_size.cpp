#include <iostream>
#include <vector>

int main()
{
  const int n = 5;
  std::vector<int> myints(99, 2);
  std::cout << "size: " << myints.size() << '\n';
  std::vector< std::vector<double> > vv;
  /*
  for(auto it=vv.begin(),   int i=0; it!=vv.end(); ++it, ++i){
  }
  */
  int k = 0;
  for(int i=0; i<n; ++i){
    for(int j=0; j<n; ++j){
      vv[i][j] = k;
      k++;
    }
  }
  for(int i=0; i<vv.size(); ++i){
    std::cout << vv[i].size() << std::endl;
  }
  return 0;
}
