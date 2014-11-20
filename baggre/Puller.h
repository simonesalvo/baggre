//
//  Puller.h
//  baggre
//
//  Created by Simone Salvo on 07/11/14.
//  Copyright (c) 2014 Simone Salvo. All rights reserved.
//

#include <curl/curl.h>
#include <curl/easy.h>
#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>

#ifndef baggre_Puller_h
#define baggre_Puller_h
class Puller
{
    // Attribute
public:
    
    // Attribute
private:
    CURL * curl;
    std::string path;
    std::string filename;
    
    // Function
public:
     Puller();
    ~Puller();

    bool getPage(std::vector<std::string> url);
    std::string getPath();
    std::string getFilename();
    std::string setFilename();
    void setPath(std::string);
    
    
    // Function
private:
    
};
#endif
