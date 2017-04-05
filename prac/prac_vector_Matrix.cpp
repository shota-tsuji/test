#include <iostream>
#include <vector>
using namespace std;

int main()
{
  // creat many vectors of vectors
  typedef vector< vector<int> > IntMatrix;
  IntMatrix m;

  // Create a 3 by 5 "matrix".
  // First, create a vector with 5 elements
  vector<int> v2(5, 99);

  // Now create a vector of 3 elements.
  // Each element is a copy of v2
  vector< vector<int> > v2d2(3, v2);

  for(int i=0; i<v2d2.size(); i++){
    for(int j=0; j<v2d2[i].size(); j++){
      cout << v2d2[i][j] << " ";
    }
    cout << endl;
  }
}
