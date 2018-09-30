#include <stdio.h>
#include <iostream>
#include <string>
#include <logger.h>

#include "reader.h"

#if 0
 * <ToDo> /*root*/
    <Item priority="1">
        <bold>
            Book store!
        </bold>
    </Item>
    <Item priority="2">
        book1
    </Item>
    <Item priority="2">
        book2
    </Item>
</ToDo>

---------------------

本文来自 一缕 的CSDN 博客 ，全文地址请点击：https://blog.csdn.net/huangkaiyue1/article/details/54140451?utm_source=copy
#endif



using namespace std;

int loadXML(const char *xmlfile){
  TiXmlDocument doc;
  if(false == doc.LoadFile(xmlfile))
  {
    std::cout<<"load err:"<<doc.ErrorDesc() << endl;
    return -1;
  }
  TiXmlElement *root = doc.FirstChildElement();
  if(root == NULL ){
    std::cout<<" fail to load file : not root element " <<std::endl;
    doc.Clear();
    return -1;
  }
 // int ret =readTODO(root);
  int ret=readPerson(root);
  doc.Clear();
  return ret;
}

#if 0
 <Persons> /*root*/
            <Person ID="1">
                <name>周星星</name>
                <age>20</age>
            </Person>
            <Person ID="2">
                <name>白晶晶</name>
                <age>18</age>
                <level>10</level>
            </Person>
        </Persons>
#endif

int readPerson(TiXmlElement *root)
{
  LOGI("root ");
  LOGI("Root value :"<<root->Value());  //输出根元素名称，即输出Persons。
  LOGFMTD("Root value %s ", root->Value());
  /*get first Person ID 1 */ //获得第一个Person节点。
  TiXmlElement *firstPerson = root->FirstChildElement();
  /*get first Person name and age */    //获得第一个Person的name节点和age节点和ID属性。
  TiXmlElement *name = firstPerson->FirstChildElement();
  TiXmlElement *age = name->NextSiblingElement();
  TiXmlAttribute *id = firstPerson->FirstAttribute();
  /*Get first person content */  //输出第一个Person的name内容，即周星星；age内容，即20；ID属性，即1。
  LOGI("NAME :"<<name->FirstChild()->Value());
  LOGI("AGE :"<<age->FirstChild()->Value());
  LOGI("ID :"<<id->Value());

  /*second person */
  TiXmlElement * secondPerson = firstPerson->NextSiblingElement();
  TiXmlElement * name2 =secondPerson->FirstChildElement();
  TiXmlElement * age2 = name2->NextSiblingElement();
  TiXmlAttribute *id2 = secondPerson->FirstAttribute();
  LOGI("NAME2 :"<<name2->FirstChild()->Value());
  LOGI("AGE2 :"<<age2->FirstChild()->Value());
  LOGI("ID2 :"<<id2->Value());
  TiXmlElement * level = age2->NextSiblingElement();
  LOGI("LEVEL :"<<level->FirstChild()->Value());
}

int readTODO(TiXmlElement *root){

  for(TiXmlElement *element = root->FirstChildElement(); element !=NULL; element = element->NextSiblingElement())
  {
    string elemName = element->Value();
    const char * attr;
    attr = element->Attribute("priority");
    std::cout << "priority attr :" << attr <<std::endl;
    if(strcmp (attr ,"1") == 0)
    {
      /*先有element*/
      TiXmlElement *e1  =  element->FirstChildElement("bold");
      /*然后是element的node*/
      TiXmlNode *E2 = e1->FirstChild();
      std::cout<<" priority == 1 \t "<<E2->ToText()->Value() <<std::endl;
    }else if(strcmp(attr,"2") ==0 ){
      /*直接就用node*/
      TiXmlNode *e1 = element->FirstChild();
      std::cout<<" priority ==2 \t" <<e1->ToText()->Value() <<endl;
    }
  }
}