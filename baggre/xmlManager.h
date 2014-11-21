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
    

    // public attributes
public:
    const std::string xmlEXT = ".xml";

    // public funcitons
public:
    xmlManager(void);
    xmlManager(std::string);
    ~xmlManager(void);
    
    std::string & getFilename(void);
    bool setFilename(const std::string &);
    bool addChild(const std::string &, std::string&);
    bool addNode(std::string&, std::string&);
    bool removeElement(std::string, std::string);
    bool removeALLChild(std::string);
    bool setPath(std::string);
    std::string getPath(void);
    TiXmlElement * getNode(const std::string &);
    std::time_t getLastStore(void);
    bool load(std::string);
    bool save(void);
    bool isSaved(void);
    
    // private attributes
private:
    bool fileExisting;
    bool saved;
    bool loaded;
    
    std::time_t lastStore;
    std::string path;
    TiXmlDeclaration * vers;
    std::string xmlFileName;
    TiXmlDocument doc;
};

#endif /* defined(__baggre__xmlManager__) */
