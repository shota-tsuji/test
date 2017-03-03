#include <iostream>
#include <random>
int main()
{
  std::random_device rnd; // 非決定的な乱数生成器
  std::mt19937 mt( rnd() ); // メルセンヌ・ツイスタの32bit 引数は初期シード
  //std::mt19937 mt( (int)time( 0 ) );
  for ( int i = 0; i < 10; ++i ) {
    std::cout << std::hex << mt() << "\n";
  }
  /*
  for ( int i = 0; i < 10; ++i ) {
    std::cout << std::hex << rnd() << "\n";
  }
  */
  getchar();
  return 0;
}
