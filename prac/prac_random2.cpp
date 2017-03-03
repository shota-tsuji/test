#include <iostream>
#include <random>

int main()
{
  std::mt19937 mt;
  std::random_device rnd;
  mt.seed( rnd() ); // シード指定
  std::uniform_int_distribution<> rand100( 0, 99 ); // [0, 99]範囲の一様乱数
  for ( int i = 0; i < 20; ++i ) {
    std::cout << std::hex << rand100( mt ) << "\n";
  }
}
