//
//  main.cpp
//  baggre
//
//  Created by Simone Salvo on 07/11/14.
//  Copyright (c) 2014 Simone Salvo. All rights reserved.
//

#include <iostream>
#include <curl/curl.h>

int main(int argc, const char * argv[])
{
    std::string url;
    std::cin >> url;


    std::cout << "Hello, World! " << url;
    return 0;
}
