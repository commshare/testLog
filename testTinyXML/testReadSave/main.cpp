#include <iostream>
#include "readsave.h"
#include "logger.h"

#include "rwjson.h"
int doJson(int argc, char *argv[])
{
  readStrJson();

  cout << "\n\n";
  readStrProJson();

  return 0;
}


int main(int argc, char * argv[]) {
  std::cout << "Hello, World!" << std::endl;
  setup_loger("main","./logger.conf");
  if(argc < 2 )
  {
    std::cout<<"no xml file input "<<std::endl;
    return -1;
  }
  int ret =  loadXML(argv[1]);
   ret = saveXML(argv[2]);

  loadConfigXML(argv[3]);
  doJson(argc,argv);
  return ret ;
}


