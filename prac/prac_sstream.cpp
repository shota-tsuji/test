#include <sstream>
#include <iostream>

int main()
{
  std::ostringstream os;

  os << "test" << ' ' << 100; // 文字列書き込み
  std::cout << os.str() << std::endl; // 結果を出力

  return 0;
}
