#include <sstream>
#include <iostream>
#include <string>

int main()
{
  std::string str( "10+10" );
  std::istringstream is( str ); // 上の文字列を読み込む

  int num1, num2;
  char c;

  is >> num1 >> c >> num2; // 文字列を展開
  std::cout << num1 << c << num2 << std::endl;

  return 0;
}
