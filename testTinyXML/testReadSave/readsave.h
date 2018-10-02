#include "tinyxml.h"

int readPerson(TiXmlElement *root);
int loadXML(const char *xmlfile);
int readTODO(TiXmlElement *root);
int saveXML(const char * file);
bool loadConfigXML(const char* xmlPath);