#include <stack>
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
  char *c;
  int a, b;
  stack<int> S;
  cin >> *c;
  S.push( std::atoi(c) );

  do {
    cin >> c;
    if(*c == '+'){
      a = S.top();
      S.pop();
      b = S.top();
      S.pop();
      S.push( a+b );
    }
    else if(*c == '-'){
      a = S.top();
      S.pop();
      b = S.top();
      S.pop();
      S.push( b-a ); // not a - b
    }
    else if(*c == '*'){
      a = S.top();
      S.pop();
      b = S.top();
      S.pop();
      S.push( a * b);
    }
    else {
      S.push( std::atoi(c) );
    }
  } while(S.size() != 1);
  cout << S.top() << endl;

  return 0;
}
