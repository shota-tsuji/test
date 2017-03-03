#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
/*void print_vector(vector<int> v)
{
  auto itr = v.begin();
  for( ; itr != v.end() - 1; ++itr)
  {
    cout << *itr << ",";
  }
  cout << *itr << endl;
}
*/

template<class T>
void print_T(T v)
{
  auto it = v.begin();
  for( ; it != v.end() -1; ++it )
  {
    cout << *it << "," ;
  }
  cout << *it << endl;
}

int main()
{
  using namespace std;

  vector<int> nums;
  int i;

  for( i = 0; i < 10; ++i )
  {
    nums.push_back( i );
  }

  //print_vector(nums);
  print_T(nums);
  // 先頭から4番めの要素が先頭にくるように回転
  rotate( nums.begin(), nums.begin() + 3, nums.end() );

  /*vector<int>::iterator it = nums.begin();
  while( it != nums.end() )
  {
    cout << *it << " ";
    ++it;
  }
  */
  //print_vector(nums);
  print_T(nums);

  return 0;
}
