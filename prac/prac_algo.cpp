#include <algorithm>
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

  // 逆の順番に並び替える
  //reverse( nums.begin(), nums.end() );

  // ランダムにシャッフル
  random_shuffle( nums.begin(), nums.end() );

  /*for( i = 0; i < 10; ++i )
  {
    cout << nums[i] << endl;
  }
  */

  vector<int>::iterator it = nums.begin();
  while( it != nums.end() )
  {
    cout << *it << endl;
    ++it;
  }
  return 0;
}
