#include <string>
#include <iostream>

int main()
{
  using namespace std;

  string str( "abcdefghijk" );
  cout << str.substr( 5 ) << endl;
  cout << str.substr( 5, 3 ) << endl; // "fgh"

  string::size_type index = str.find( "afgh" ); // "fgh"を検索
  if( index == string::npos )
  {
    cout << "Failed to search" << endl;
  }
  else
  {
    cout << str.substr( index ) << endl;
  }

  return 0;
}
