#include <numeric>
#include <vector>
#include <iostream>

int main()
{
  using namespace std;

  vector<int> nums;

  for(int i = 0; i < 10; ++i )
  {
    nums.push_back( i );
  }

  // 合計を求める
  int sum = accumulate( nums.begin(), nums.end(), 0);

  // 各要素を乗算した結果を計算する
  int sum2 = inner_product( nums.begin(), nums.end(), nums.begin(), 0 );

  // 結果を出力
  //cout << sum << endl;
  cout << sum2 << endl;
  return 0;
}
