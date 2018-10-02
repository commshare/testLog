//
// Created by root on 10/2/18.
//

#include "rwjson.h"



#include <string>
#include <json/json.h>
#include <iostream>
#include <fstream>
using namespace std;

void readStrJson(); //从字符串中读取JSON
void readStrProJson(); //从字符串中读取JSON（内容复杂些）



//从字符串中读取JSON
void readStrJson()
{
  //字符串
  const char* str =
      "{\"praenomen\":\"Gaius\",\"nomen\":\"Julius\",\"cognomen\":\"Caezar\","
      "\"born\":-100,\"died\":-44}";

  /*
  //json内容如下：
  {
        "praenomen":"Gaius",
        "nomen":"Julius",
        "cognomen":"Caezar",
        "born":-100,
        "died":-44
    }
  */

  Json::Reader reader;
  Json::Value root;

  //从字符串中读取数据
  if(reader.parse(str,root))
  {
    string praenomen = root["praenomen"].asString();
    string nomen = root["nomen"].asString();
    string cognomen = root["cognomen"].asString();
    int born = root["born"].asInt();
    int died = root["died"].asInt();

    cout << praenomen + " " + nomen + " " + cognomen
         << " was born in year " << born
         << ", died in year " << died << endl;
  }

}

//从字符串中读取JSON（内容复杂些）
void readStrProJson()
{
  string strValue = "{\"name\":\"json\",\"array\":[{\"cpp\":\"jsoncpp\"},{\"java\":\"jsoninjava\"},{\"php\":\"support\"}]}";
  /*
  //json内容如下：
  {
  "name": "json″,
  "array": [
      {
          "cpp": "jsoncpp"
      },
      {
          "java": "jsoninjava"
      },
      {
          "php": "support"
      }
  ]
  }
  */


  Json::Reader reader;
  Json::Value value;

  if (reader.parse(strValue, value))
  {
    string out = value["name"].asString();
    cout << out << endl;
    const Json::Value arrayObj = value["array"];
    for (unsigned int i = 0; i < arrayObj.size(); i++)
    {
      if (!arrayObj[i].isMember("cpp"))
        continue;
      out = arrayObj[i]["cpp"].asString();
      cout << out;
      if (i != (arrayObj.size() - 1))
        cout << endl;
    }
  }
}
/*

---------------------

本文来自 Windows_and_Linux 的CSDN 博客 ，全文地址请点击：https://blog.csdn.net/Windows_and_Linux/article/details/78478669?utm_source=copy*/
