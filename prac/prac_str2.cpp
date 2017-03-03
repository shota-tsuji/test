#include <string>
#include <iostream>

int main()
{
  using namespace std;

  string str1( "abcde" );
  string str2( "fghij" );

  str1 += str2; // str1の末尾に連結
  cout << str1 << endl;

  if( str1 == "abcdefghij" )
  {
    cout << "same string" << endl;
  }
  else
  {
    cout << "different string" << endl;
  }

  cout << "The number of letter of str1 is " << str1.size() << endl; // 文字列の長さを出力
  return 0;
}
