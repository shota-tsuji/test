#include <sstream>
#include <iostream>
#include <string>

int main()
{
  std::string str( "10+20" );
  std::istringstream is( str ); // 上の文字列を読み込む

  int num1, num2;
  char c;

  is >> num1 >> c; // 文字列を展開
  std::cout << num1 << c << std::endl;
  is >> num2;
  std::cout << num2 << c << std::endl;
  //is >> num2;
  std::cout << is << std::endl;
  //std::cout << num2 << c << std::endl;


  return 0;
}
