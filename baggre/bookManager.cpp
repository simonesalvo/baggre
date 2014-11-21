//
//  bookManager.cpp
//  baggre
//
//  Created by Simone Salvo on 20/11/14.
//  Copyright (c) 2014 Simone Salvo. All rights reserved.
//

#include "bookManager.h"

/**
 *  Constructor
 */
bookManager::bookManager(void):
title("no_name"),
author("no_author"),
date(std::time(nullptr)),
currentChapter(0),
path("../"),
enableChapterMode(false)
{
}

/**
 *  Costructor with parameter
 */
bookManager::bookManager(std::string t, std::string a, std::time_t d, std::string p):
date(std::time(nullptr)),
currentChapter(0),
enableChapterMode(false)
{
    title = t;
    author = a;
    date = d;
    xml.setFilename(title+xml.xmlEXT);
    xml.setPath(p);
}

/**
 *  Destructor
 */
bookManager::~bookManager(void)
{
    
}
/**
 *  Add page means add a lief below the page node
 *  a page is a located in a file
 */
void bookManager::addPage()
{
    std::ifstream inFile;
    std::string text;
    std::string tLine;
    
    inFile.open (xml.getPath()+xml.getFilename(), std::ios::in);
    
    while(std::getline(inFile,tLine))
        text.append(tLine.c_str());
    
    inFile.close();

    xml.addChild(BOOK_STRING, text);
}
/**
 *  Remove a page means remove a lief below the page node
 */
void bookManager::removePage()
{
    
}
/**
 *  Remove a page means remove a lief below the page node
 * in this case will be removed the last inserted page
 */
void bookManager::removeLastIPage()
{
    
}
/**
 *  Add a chapter.
 */
void bookManager::addChapter(void)
{
    
}

/**
 *  Remove a specified chapter
 *
 *  @param cap chapter to be removed
 */
void bookManager::removeChapter(unsigned int cap)
{
    
}

/**
 *  Remove the last inserted chapter and all
 *  the pages below it
 */
void bookManager::removeLastChapter()
{
    
}

/**
 *  References are added at the end of of a chapter
 */
void bookManager::addReference()
{
    
}
/**
 *  Add an index. The index is linked to the chapters and pages
 */
void bookManager::addIndex()
{
    
}

/**
 *  Save book
 */
void bookManager::save()
{
    
}

/**
 *  Load book
 */
void bookManager::load()
{
    
}

/**
 *  Delete a stored book
 */
void bookManager::deleteB()
{
    
}

/**
 *  Moving the page p from a chapter to another
 *
 *  @param fromC capther where came from the page to move
 *  @param toC   destination chapter
 *  @param p     page to move. the meaning of page is one or more physical pages
 *               made by a link reference
 */
void bookManager::moveToChapter(unsigned int fromC, unsigned int toC, unsigned int p)
{
    
}



