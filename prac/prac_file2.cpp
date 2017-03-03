#include <fstream>

int main()
{
  std::ofstream ofs( "test.txt", std::ios::out | std::ios::app );
  ofs << "append test" << std::endl;
  return 0;
}
