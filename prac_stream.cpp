#include <iostream>

// 指定した文字を，指定した文字数だけ出力するクラス
class CPut
{
  //グローバルな演算子オーバーロードをフレンド指定
friend std::ostream& operator<<(std::ostream& os, const CPut& put);

public:
  CPut(char c, int num) : m_char(c), m_num(num){}
private:
  char m_char; //出力する文字
  int m_num; // 出力する文字数
};

// 出力用の<<演算子定義
std::ostream& operator<<(std::ostream& os, const CPut& put)
{
  for( int i = 0; i < put.m_num; ++i)
  {
    os << put.m_char;
  }
  return os;
}

int main()
{
  CPut aster( '*', 10 );
  std::cout << aster << std::endl;

  CPut plus( '+', 5 );
  std::cout << aster << plus << std::endl;

  return 0;
}
