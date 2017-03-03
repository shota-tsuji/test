#include <iostream>
using namespace std;

char *str = "Kitty on your lab\n";

int main()
{
  char *str = "Card Captor Sakura\n";

  cout << str;
  cout << ::str;
  return 0;
}
