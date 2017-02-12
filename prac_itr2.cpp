#include <vector>
#include <algorithm>
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

  vector<int>::iterator it1 = nums.begin();
  advance( it1, 5); // イテレータを5つ先に進める
  cout << *it1 << endl;

  vector<int>::iterator it2 = nums.end();
  advance( it2, -2 );
  cout << *it2 << endl;

  cout << distance( it1, it2 ) << endl; // 2つのイテレータの差を出力

  iter_swap( it1, it2 ); // 2つのイテレータが参照する値を交換する
  for( it1 = nums.begin(); it1 != nums.end(); ++it1 )
  {
    cout << *it1 << endl;
  }

  return 0;
}
