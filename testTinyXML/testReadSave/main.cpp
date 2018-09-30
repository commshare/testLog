#include <iostream>
#include "reader.h"
#include "logger.h"
int main(int argc, char * argv[]) {
  std::cout << "Hello, World!" << std::endl;
  setup_loger("main","./logger.conf");
  if(argc < 2 )
  {
    std::cout<<"no xml file input "<<std::endl;
    return -1;
  }
  return loadXML(argv[1]);
}