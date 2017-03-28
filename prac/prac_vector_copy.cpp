#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
int main()
{
  vector<int> v1, v2;
  for(int i=0; i<4; i++){
    v1.push_back(i);
  }
  copy(v1.begin(), v1.end(), back_inserter(v2));

  for(auto it=v2.begin(); it!=v2.end(); ++it){
    cout << *it << ", ";
  }
  cout << endl;
  return 0;
}
