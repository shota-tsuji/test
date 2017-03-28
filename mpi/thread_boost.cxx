#include <iostream>
#include <boost/thread.hpp>

void para_func(void)
{
  for(int i=0; i<3; ++i){
    std::cout << "0" << std::endl;
  }
}

int main(void)
{
  boost::thread th(para_func);

  for(int i=0; i<3; ++i){
    std::cout << "1" << std::endl;
  }

  th.join();
  return 0;
}
