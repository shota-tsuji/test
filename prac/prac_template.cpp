#include <iostream>
#include "./prac_Stack.h"

int main()
{
  Stack<int> iStack( 10 );
  Stack< std::string > sStack( 10 );

  const std::size_t capacity = iStack.GetCapacity();
  for (std::size_t i = 0; i < capacity; ++i ) {
    iStack.Push( static_cast<int>( i ) );
  }

  for (std::size_t i = 0; i < capacity; ++i ) {
    std::cout << iStack.Top() << std::endl;
    iStack.Pop();
  }

  sStack.Push( "aaa" );
  sStack.Push( "bbb" );
  sStack.Push( "ccc" );

  const std::size_t size = sStack.GetSize();
  for ( std::size_t i = 0; i < size; ++i ) {
    std::cout << sStack.Top() << std::endl;
    sStack.Pop();
  }
}
