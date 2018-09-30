//
// Created by zhangbin on 2018/9/30.
//

#include "logger.h"


//
// Created by zhangbin on 2018/9/30.
//




using namespace zsummer::log4z;
using namespace std;

LoggerId LOGID_TEST;

int setup_loger(const char * name ,char * configfile)
{
  /*all config in logger.conf */

  //设置是否将日志输出到文件中,true:使能输出到文件,false:禁止输出到文件中,default true
  //ILog4zManager::getRef().setLoggerOutFile(LOG4Z_MAIN_LOGGER_ID,true);
  /*config */
  ILog4zManager::getRef().config(configfile);
  ILog4zManager::getRef().setLoggerName(LOG4Z_MAIN_LOGGER_ID,name); //设置存储文件的名字
  //start log4z
  //ILog4zManager::getRef().start();
  //LOGFMT_INFO(LOG4Z_MAIN_LOGGER_ID, "int log4z log ");

  //设置输出文件的大小,单位是M
  //ILog4zManager::getRef().setLoggerLimitsize(LOG4Z_MAIN_LOGGER_ID,10);

  //设置日志是按月进行分文件夹,每月都会有一个文件夹
//	ILog4zManager::getRef().setLoggerMonthdir(LOG4Z_MAIN_LOGGER_ID, true);

  //设置日志能够保留多长时间,前提条件为文件大小已经达到限制的大小
  ILog4zManager::getRef().setLoggerReserveTime(LOG4Z_MAIN_LOGGER_ID,3600*24*3);

  //start log4z
  cout<<"setup loger!!"<<endl;

  LOGID_TEST = ILog4zManager::getRef().createLogger("test" );
#if 0
  // ILog4zManager::getRef().config("config.cfg");
	ILog4zManager::getRef().setLoggerDisplay(LOG4Z_MAIN_LOGGER_ID, false);
	ILog4zManager::getRef().setLoggerOutFile(LOG4Z_MAIN_LOGGER_ID, false);

	ILog4zManager::getRef().setLoggerDisplay(LOGID_TEST, true);
	ILog4zManager::getRef().setLoggerOutFile(LOGID_TEST, true);
#endif
  ILog4zManager::getRef().start();
  std::cout<<"LOGID_TEST:"<<LOGID_TEST<<("!setup finish!!")<<endl;
  return 0;
}


