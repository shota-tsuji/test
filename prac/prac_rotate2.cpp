#include <algorithm>
#include <list>
#include <iterator>
#include <iostream>

void print_list( std::list<int> ls )
{
  auto it = ls.begin();
  for( ; it != ls.end() ; ++it )
  {
    std::cout << *it << "," ;
  }
}

int main()
{
  using namespace std;

  list<int> nums;
  int i;

  for( i = 0; i < 10; ++i )
  {
    nums.push_back( i );
  }

  // 先頭から4番めの要素が先頭にくるように回転
  list<int>::iterator it = nums.begin();
  advance( it, 3);
  rotate( nums.begin(), it, nums.end() );

  it = nums.begin();
  while( it != nums.end() )
  {
    cout << *it << endl;
    ++it;
  }

}
