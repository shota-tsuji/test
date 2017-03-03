#include <iostream>

int main( int argc, char* argv[] )
{
  //std::cout << argv[0] << std::endl;

  // Check the number of parameters
  if ( argc < 2 ) {
    // Tell the user how to run the program
    std::cerr << "Usage: " << argv[0] << " NAME" << std::endl;
    return 1;
  }
  // Print the user's name:
  std::cout << argv[0] << " says hello, " << argv[1] << "!" << std::endl;
  return 0;
}
