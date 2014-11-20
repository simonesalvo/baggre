//
//  main.cpp
//  baggre
//
//  Created by Simone Salvo on 07/11/14.
//  Copyright (c) 2014 Simone Salvo. All rights reserved.
//

#include <iostream>
#include "puller.h"
#include "creator.h"

int main(int argc, const char * argv[])
{
    
    std::string url;
    std::vector<std::string> urlVector;
    
    do
    {
        std::cin >> url;
        if (url.compare("q")!=0)
            urlVector.push_back(url);
    }
    while(url.compare("q")!=0);

    Puller puller;
    puller.getPage(urlVector);
    
    Creator creator(puller.getPath(),puller.getFilename());
    creator.createPdf();
    
    return 0;
}
