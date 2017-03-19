#include <algorithm>
#include <vector>
#include <iostream>

bool even_number(int num);

int main()
{
  using namespace std;

  vector<int> nums;
  int i;

  for( i = 0; i < 10; ++i )
  {
    nums.push_back( i );
  }

  // 偶数の要素を先頭近くに移動させる
  partition( nums.begin(), nums.end(), even_number ); // 順序が崩れる
  //stable_partition( nums.begin(), nums.end(), even_number );

  vector<int>::iterator it = nums.begin();
  while( it != nums.end() )
  {
    cout << *it << endl;
    ++it;
  }

  return 0;
}

// 偶数かどうかを判定する
bool even_number(int num)
{
  return ( ~num & 1 );
}
