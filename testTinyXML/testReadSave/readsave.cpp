#include <stdio.h>
#include <iostream>
#include <string>
#include <logger.h>
#include <fstream>

#include "readsave.h"
enum LogLevel{
  Error =3,
   Info = 4,
  Debug =7,
};

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

#define LOGZ(level, fmt, args...)  do{\
  if (level <= Debug ) \
    LOGFMTI(  fmt , ##args);\
}while(0)


  std::map<std::string, int> m_smCenterConfs;
bool m_bTestModel =false;
    uint16_t    m_nServicePort;
    uint32_t  m_interval ;
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



/*https://blog.csdn.net/huangkaiyue1/article/details/54140451*/
#if 0
<root>
    <Element attribute="1932" />
    <E2 attribute2="2" attribute3="3">
        <Element3 attribute4="4" />
        <zhongguo />
    </E2>
</root>

#endif
int saveXML(const char * file){
  TiXmlDocument doc;
  TiXmlElement *root = new TiXmlElement("root");
  doc.LinkEndChild(root);

  TiXmlElement * e1 = new TiXmlElement("Element");
  root->LinkEndChild(e1);

  e1->SetAttribute("attribute","1932");

  TiXmlElement * e2 = new TiXmlElement("E2");
  root->LinkEndChild(e2);
  e2->SetAttribute("attribute2","2");
  e2->SetAttribute("attribute3","3");

  TiXmlElement* element3 = new TiXmlElement("Element3");
  e2->LinkEndChild(element3);
  element3->SetAttribute("attribute4","4");

  TiXmlElement * text = new TiXmlElement("zhongguo");
  e2->LinkEndChild(text);

  bool success = doc.SaveFile((char *)file);
  doc.Clear();
  if(success)
    return 0;
  else
    return -1;
}

std::string normalizeXmlString(const std::string &xml)
{
  // 1. format data
  uint32_t length = xml.size();
  char* buf = new char[length + 1];
  buf[length] = '\0';

  const char* s = xml.data();
  const char* e = s + length;
  char* dst = buf;
  while (s < e)
  {
    if (*s == 0xd) // skip CR
    {
      ++s;
      continue;
    }

    *dst++ = *s++;
  }

  *dst = '\0';
  std::string ret = std::string(buf);
  delete []buf;
  return ret;
}


bool loadConfigXML(const char* xmlPath)
{
  if(NULL == xmlPath )
  {
    LOGZ(Error,"NULL == xmlPath ");
    return false;
  }
  try {
    std::string fileContent;
    std::string fileMd5;
    std::ifstream ifs;
    ifs.open(xmlPath);
    if(ifs.fail())
    {
      LOGZ(Error,"fail to open %s",xmlPath);
      return false;
    }
    fileContent.assign((std::istreambuf_iterator<char>(ifs)),
                       (std::istreambuf_iterator<char>()));
  //  fileMd5 = MUtility::md5_encrypt(fileContent);
    LOGZ(Info,"config file %s ",fileContent.c_str());
    std::string xml = normalizeXmlString(fileContent);
    LOGZ(Info,"config file %s",xml.c_str());
    TiXmlDocument doc;
    doc.Parse(xml.c_str());
    if(doc.Error())
    {
      LOGZ(Error,"fail to parse xml file %s content %s ",xmlPath,fileContent.c_str());
      return false;
    }
    LOGZ(Info,"parse ok");
    TiXmlHandle docH(&doc);
    /*   TiXmlHandle redis = docH.FirstChildElement("conf").FirstChildElement("redis");
     if(!redis.Element())
      {
        LOGZ(Error,"could not find element redis , content = %s ",fileContent.c_str());
        return false;
      }*/
    /*sm config*/
    /*read sm center list*/
    m_smCenterConfs.clear();
    TiXmlHandle sn = docH.FirstChildElement("conf").FirstChildElement("sn");
    if(NULL != sn.Element())
    {
      TiXmlElement * smgr = sn.FirstChildElement("smgr").Element();
      if(NULL != smgr)
      {
          const char * sn_vc_timer_interval = smgr->Attribute("timer");
          if(NULL != sn_vc_timer_interval)
          {
            m_interval = atoi(sn_vc_timer_interval);
            LOGZ(Info,"m_interval %u ",m_interval);
          }else{
            LOGZ(Error,"error smgr sn_vc_timer_interval config ");
          }
      }else{
        LOGZ(Error,"smgr is null ");
      }
      TiXmlElement * centerE = sn.FirstChildElement("smcenter").Element();
      while(centerE)
      {
        TiXmlElement *tempE = centerE;
        centerE = centerE->NextSiblingElement("smcenter");
        const char * host = tempE->Attribute("host");
        const char * port = tempE->Attribute("port");
          if(NULL == host || 0 == *host
            || NULL == port || 0 == *port )
          {
            LOGZ(Error,"error smgr smcenter config ");
            return false;
          }
          /*to int */
          int portI = atoi(port);
          m_smCenterConfs[host] = portI;
          LOGZ(Info,"load sm config center:host %s port %d",host,portI);
      }
    } else{
      LOGZ(Error,"could not find element smgr , content = %s ",fileContent.c_str());
      return false;
    }
    /////////////server////////////////
    TiXmlHandle server = docH.FirstChildElement("conf").FirstChildElement("server");
    if(NULL != server.Element())
    {
      /*read listen port*/
      TiXmlElement * listenE = server.FirstChildElement("listen").Element();
      if(listenE)
      {
        const char * portS = listenE->Attribute("port");
        if(NULL != portS &&  0!= *portS)
        {
          /*sm 才需要监听端口*/
          m_nServicePort = atoi(portS);
          LOGZ(Info,"server listen port :%u",m_nServicePort);
        }
      }

      /*read test model*/
      TiXmlElement * testModelE = server.FirstChildElement("testmodel").Element();
      if(NULL != testModelE)
      {
        const char * enableS = testModelE->Attribute("enable");
        if(NULL != enableS && 0!= *enableS)
        {
          m_bTestModel =  atoi(enableS) > 0 ;
        }
      }else{
        LOGZ(Error,"not find testmodel");
      }
    }
    LOGZ(Info,"testmodel %d",m_bTestModel);
    if(m_bTestModel == true )
    {
      /*clear it first */
      m_smCenterConfs.clear();
      LOGZ(Info,"testmodel TRUE %d",m_bTestModel);

      TiXmlHandle localtest = docH.FirstChildElement("conf").FirstChildElement("localtest");
      if(NULL != localtest.Element())
      {
        TiXmlElement * centerE = localtest.FirstChildElement("smcenter").Element();
        while(centerE)
        {
          TiXmlElement *tempE = centerE;
          centerE = centerE->NextSiblingElement("smcenter");
          const char * host = tempE->Attribute("host");
          const char * port = tempE->Attribute("port");
          if(NULL == host || 0 == *host
             || NULL == port || 0 == *port )
          {
            LOGZ(Error,"error smgr smcenter config ");
            return false;
          }
          /*to int */
          int portI = atoi(port);
          m_smCenterConfs[host] = portI;
          LOGZ(Info,"load sm config center:host %s port %d",host,portI);
        }
      }else{
        LOGZ(Error,"not find local test ,fileContent %s",fileContent.c_str());
        return false;
      }
    }
  }catch (std::exception &se){
    LOGZ(Error,"load %s exception :%s",xmlPath,se.what());
    return false;
  }
  catch (...)
  {
    LOGZ(Error, "load:%s unknown exception.", xmlPath);
    return false;
  }
  std::map<std::string, int>::iterator it = m_smCenterConfs.begin();
  for(;it!= m_smCenterConfs.end();++it)
  {
    LOGZ(Info," host %s port %d",it->first.c_str(),it->second);
  }
  return true;
}