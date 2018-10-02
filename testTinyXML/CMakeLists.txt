cmake_minimum_required(VERSION 3.10)
project(testTinyXML)

set(CMAKE_CXX_STANDARD 11)
set( CMAKE_VERBOSE_MAKEFILE on )

include_directories(xmlconfigure)
include_directories(xmlconfigure/tinyxml)
include_directories(logger)
#include_directories(json/jsoncpp)
include_directories(json/jsoncpp-1.8.4/include)


ADD_SUBDIRECTORY(json/jsoncpp-1.8.4)

#[[PROJECT_SOURCE_DIR : /home/zhangbin/stream/ttttsdk/testLog/testTinyXML]]
message(STATUS "PROJECT_SOURCE_DIR : ${PROJECT_SOURCE_DIR}")


add_library(JSON_LIB STATIC IMPORTED)
set_target_properties(JSON_LIB
        PROPERTIES
        IMPORTED_LOCATION
        ${PROJECT_SOURCE_DIR}/json/jsoncpp-1.8.4/build/debug/src/lib_json/libjsoncpp.a
        )

message(STATUS "JSON_LIB : ${JSON_LIB}")
message(STATUS "JSON_LIB : JSON_LIB")

add_executable(testTinyXML
        testReadSave/main.cpp
        testReadSave/readsave.cpp
        xmlconfigure/tinyxml/tinystr.cpp
        xmlconfigure/tinyxml/tinystr.h
        xmlconfigure/tinyxml/tinyxml.cpp
        xmlconfigure/tinyxml/tinyxml.h
        xmlconfigure/tinyxml/tinyxmlerror.cpp
        xmlconfigure/tinyxml/tinyxmlparser.cpp
        testReadSave/main.cpp
        testReadSave/readsave.cpp
        logger/log4z.cpp logger/log4z.h
        logger/logger.cpp logger/logger.h
        testReadSave/rwjson.cpp testReadSave/rwjson.h)

TARGET_LINK_LIBRARIES(testTinyXML  pthread
        JSON_LIB)
