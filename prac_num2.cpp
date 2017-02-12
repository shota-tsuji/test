#include <numeric>
#include <vector>
#include <iostream>

int main()
{
  using namespace std;
  vector<int> nums1, nums2, nums3;

  for(int i = 0; i < 10; ++i )
  {
    nums1.push_back( i );
  }

  // 部分和を計算
  partial_sum( nums1.begin(), nums1.end(), back_inserter( nums2 ) );

  // 結果の各要素がどれだけ離れているか
  adjacent_difference( nums2.begin(), nums2.end(), back_inserter( nums3 ) );

  // 結果を出力
  vector<int>::iterator it = nums3.begin();
  while( it != nums3.end() )
  {
    cout << *it << endl;
    ++it;
  }
  return 0;
}
