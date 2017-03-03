#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

// 入れ子のコンテナの表示関数
void print_list( const vector< vector<int> >& v_list )
{
  for( vector< vector<int> >::const_iterator p = v_list.begin(); p != v_list.end(); ++p ){
    for( vector<int>::const_iterator q = p->begin(); q != p->end(); ++q ){
      cout << *q << " ";
    }
    cout << endl;
  }
}

// 和の比較関数
template<class T>
bool less_summation( const vector<T>& a, const vector<T>& b )
{
  return accumulate( a.begin(), a.end(), 0 ) < accumulate( b.begin(), b.end(), 0 );
}

// 積の比較関数
template<class T>
bool less_product( const vector<T>& a, const vector<T>& b )
{
  return accumulate( a.begin(), a.end(), 1, multiplies<T>() ) < accumulate( a.begin(), a.end(), 1, multiplies<T>() );
}

// 二乗の和の関数オブジェクト
template<class T>
class add_square : public binary_function<T, T, T> {
public:
  result_type operator()(first_argument_type a, second_argument_type b)
  {
    return a + b * b;
  }
};

// 二乗の和の比較関数
template<class T>
bool less_add_square( const vector<T>& a, const vector<T>& b )
{
  return accumulate( a.begin(), a.end(), 0, add_square<T>() ) < accumulate( b.begin(), b.end(), 0, add_square<T>() )
}

int main()
{
  vecotr<int> v;
  vector< vector<int> > v_list;

  // 10個の数値の入ったコンテナ(v)を5つ含むコンテナを作成(v_list).
  for( int i = 0; i < 5; i++ ){
    v.clear();
    for( int j = i; j < i+10; j++ ){
      v.push_back( j % 2 == 0 ? j : -j ); // 交互に正と負とする．
    }
    v_list.push_back( v );
  }

  cout << "ascending order" << endl;
  sort( v_list.begin(), v_list.end() );
  print_list( v_list );

  cout  << "descending order" << endl;
  sort( v_list.begin(), v_list.end(), greater< vector<int> >() );
  print_list( v_list );
}
