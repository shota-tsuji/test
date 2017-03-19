#include <fstream>

int main()
{
  std::ofstream ofs( "test.txt" );
  /*std::ofstream ofs;
  ofs.open( "test.txt" );
  */

  ofs << "testmessage" << 123 << std::endl;

  /*ofs.close();
  */
  return 0;
}
