cmake_minimum_required(VERSION 3.10)
project(testTinyXML)

set(CMAKE_CXX_STANDARD 11)

include_directories(xmlconfigure)
include_directories(xmlconfigure/tinyxml)
include_directories(logger)

add_executable(testTinyXML
        testReadSave/main.cpp
        testReadSave/reader.cpp
        xmlconfigure/tinyxml/tinystr.cpp
        xmlconfigure/tinyxml/tinystr.h
        xmlconfigure/tinyxml/tinyxml.cpp
        xmlconfigure/tinyxml/tinyxml.h
        xmlconfigure/tinyxml/tinyxmlerror.cpp
        xmlconfigure/tinyxml/tinyxmlparser.cpp
        testReadSave/main.cpp
        testReadSave/reader.cpp
        logger/log4z.cpp logger/log4z.h
        logger/logger.cpp logger/logger.h
        )

TARGET_LINK_LIBRARIES(testTinyXML  pthread)
