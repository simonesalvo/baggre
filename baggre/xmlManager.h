//
//  xmlManager.h
//  baggre
//
//  Created by Simone Salvo on 12/11/14.
//  Copyright (c) 2014 Simone Salvo. All rights reserved.
//

#ifndef __baggre__xmlManager__
#define __baggre__xmlManager__

#include <stdio.h>
#include <string>
#include "tinyxml.h"

class xmlManager
{
    // public funcitons
public:
    // public attributes
public:
    // private functions
    xmlManager();
    ~xmlManager();
    std::string getXmlFilename();
    std::string setXmlFilename(std::string);
    bool addChild(std::string &, std::string&); // child name and parent
    bool addNode(std::string&, std::string&); // node name and parent
    bool removeElement(std::string, std::string); // child to remove and his parent
    bool removeALLChild(std::string);
    bool setPath(std::string);
    std::string getPath();
    TiXmlElement * getNode(std::string &);
    void setFilename(std::string);
    std::string getFilename();
    std::time_t getLastStore();
    bool loadXml(std::string);
    bool saveXml();
    bool isSaved();
    
    // private attributes
private:
    bool fileExisting;
    bool saved;
    std::time_t lastStore;
    std::string path;
    TiXmlDeclaration * vers;
    std::string xmlFileName;
    TiXmlDocument doc;
};

#endif /* defined(__baggre__xmlManager__) */
