//
//  pullerTest.cpp
//  baggre
//
//  Created by Simone Salvo on 20/11/14.
//  Copyright (c) 2014 Simone Salvo. All rights reserved.
//

#include "pullerTest.h"

void pullerTest::init(void)
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
}