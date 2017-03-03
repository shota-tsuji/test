#include <vector>
#include <iostream>

int main()
{
  using namespace std;

  vector<int> nums;
  int i;

  for( i = 0; i < 10; ++i )
  {
    nums.push_back( i );
  }

  // 逆イテレータ
  vector<int>::reverse_iterator rit = nums.rbegin();
  while( rit != nums.rend() )
  {
    cout << *rit << endl;
    ++rit;
  }
  return 0;
}
