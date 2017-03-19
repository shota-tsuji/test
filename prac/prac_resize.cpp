// resizing vector
#include <iostream>
#include <vector>

int main()
{
  std::vector< int > myvector;
  std::vector< int > myvector2;

  // set some initial content;
  for ( int i = 1; i < 10; i++ ) myvector.push_back( i );

  myvector.resize( 5 );
  myvector.resize( 8, 100 );
  myvector.resize( 12 );

  std::cout << "myvector contains:";
  for ( int i = 0; i < myvector.size(); i++ ){
    std::cout << ' ' << myvector[i];
  }
  std::cout << '\n';

  myvector2.resize( 12 );
  std::cout << "myvector2 contains:";
  for ( int i = 0; i < myvector.size(); i++ ){
    std::cout << ' ' << myvector2[i];
  }
  std::cout << '\n';

  return 0;
}
