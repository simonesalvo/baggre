//
//  bookManager.h
//  baggre
//
//  Created by Simone Salvo on 20/11/14.
//  Copyright (c) 2014 Simone Salvo. All rights reserved.
//

#ifndef __baggre__bookManager__
#define __baggre__bookManager__

#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include "xmlManager.h"

class bookManager
{
public:
    
    bookManager(void);
    bookManager(std::string, std::string, std::time_t, std::string);
    ~bookManager(void);
    
    void addPage();
    void removePage();
    void removeLastIPage();
    void addChapter();
    void removeChapter(unsigned int);
    void removeLastChapter();
    void addReference();
    void addIndex();
    void save();
    void load();
    void moveToChapter(unsigned int, unsigned int, unsigned int);
    void deleteB();

    
public:
    
private:
    std::string title;
    std::string path;
    std::string author;
    std::time_t date;
    unsigned int currentChapter;
    bool enableChapterMode;
    const std::string BOOK_STRING = "book";
    
    xmlManager xml;
    
private:
    
    
};
#endif /* defined(__baggre__bookManager__) */
