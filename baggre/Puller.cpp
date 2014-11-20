//
//  Puller.cpp
//  baggre
//
//  Created by Simone Salvo on 07/11/14.
//  Copyright (c) 2014 Simone Salvo. All rights reserved.
//

#include "puller.h"


Puller::Puller()
{
    path = "/Users/simone/Desktop/";
    filename = "file.txt";
}

Puller::~Puller()
{
    
}

std::string Puller::getFilename()
{
    return filename;
}

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
    int written = fwrite(ptr, size, nmemb, (FILE *)stream);
    return written;
}

void Puller::setPath(std::string p)
{
    path = p;
}

std::string Puller::getPath()
{
    return path;
}

bool Puller::getPage(std::vector<std::string> url)
{
    curl_global_init(CURL_GLOBAL_ALL);
    
    curl = curl_easy_init();
    FILE *fp;
    CURLcode res;
    
    if (curl)
    {
        if (!url.empty())
        {
            fp = fopen((path+filename).c_str(),"wb");
            
            for (int i = 0; i < url.size();++i)
            {
                curl_easy_setopt(curl, CURLOPT_URL, (url[i].c_str()));
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
                res = curl_easy_perform(curl);
            }
            fclose(fp);
            curl_easy_cleanup(curl);
        }
        
    }
    return true;
}


