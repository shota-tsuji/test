#include <string>
#include <iostream>

int main()
{
  using namespace std;

  string filename( "test.txt" );

  FILE* fp = std::fopen( filename.c_str(), "r" );

  std::fclose( fp );

  return 0;
}
