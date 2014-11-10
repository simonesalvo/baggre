//
//  creator.h
//  baggre
//
//  Created by Simone Salvo on 10/11/14.
//  Copyright (c) 2014 Simone Salvo. All rights reserved.
//

#ifndef __baggre__creator__
#define __baggre__creator__

#include <stdio.h>
#include <string>
#include </opt/local/include/podofo/podofo.h>

class Creator
{

public:
    Creator(std::string);
    ~Creator();
    
private:
    std::string path;
    
public:
    bool createDoc();
    bool createOdt();
    bool createPdf();
    
private:
    
};
#endif /* defined(__baggre__creator__) */
