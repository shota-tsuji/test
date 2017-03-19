#include <string>
#include <iostream>

int main()
{
  std::string str1; // からのstring
  std::string str2( "abcde" ); // 初期値"abcde"を与える

  std::cout << str1 << std::endl;
  std::cout << str2 << std::endl;

  str1 = str2;
  std::cout << str1 << std::endl;
  return 0;

}
