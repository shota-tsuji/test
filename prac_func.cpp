#include <iostream>
using namespace std;

void function()
{
  cout << "Di_Gi_Ghara\n";
}

class Kitty
{
  void function();
public:
  // コンストラクタ
  Kitty();
};

Kitty::Kitty()
{
  ::function();
  Kitty::function();
}

void Kitty::function()
{
  cout << "Kitty on your lap\n";
}

int main()
{
  Kitty obj;
  return 0;
}
