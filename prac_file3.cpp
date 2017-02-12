#include <fstream>
#include <string>
#include <iostream>

int main()
{
  std::ifstream ifs( "test.txt" );
  std::string str;

  //ifs.seekg( 15, std::ios::beg );
  ifs >> str;
  std::cout << str << std::endl;
  ifs >> str;
  std::cout << str << std::endl;
  ifs >> str;
  std::cout << str << std::endl;
  ifs >> str;
  std::cout << str << std::endl;

  return 0;
}
