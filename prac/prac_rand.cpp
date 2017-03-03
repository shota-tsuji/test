#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Random
{
public:
  // コンストラクタ
  Random()
  {
    srand( static_cast<unsigned int>( time(NULL) ) );
  }

  // 関数オブジェクト
  unsigned int operator()(unsigned int max)
  {
    double tmp = static_cast<double>( rand() ) / static_cast<double>( RAND_MAX );
    return static_cast<unsigned int>(tmp * max );
  }
};

int main()
{
  using namespace std;

  vector<int> nums;
  int i;

  for( i = 0; i < 10; ++i )
  {
    nums.push_back( i );
  }

  Random r;
  // ランダムシャッフル
  random_shuffle( nums.begin(), nums.end(), r );

  vector<int>::iterator it = nums.begin();
  while( it != nums.end() )
  {
    cout << *it << endl;
    ++it;
  }

  return 0;
}
