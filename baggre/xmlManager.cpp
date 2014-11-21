//
//  xmlManager.cpp
//  baggre
//
//  Created by Simone Salvo on 12/11/14.
//  Copyright (c) 2014 Simone Salvo. All rights reserved.
//

#include "xmlManager.h"

/**
 *  Constructor
*/
xmlManager::xmlManager()
: xmlFileName("sample.xml"),
saved(false),
loaded(false),
path("")
{
    vers = new TiXmlDeclaration( "1.0", "", "" );
    doc.LinkEndChild( vers );
}

/**
 *  Constructor
 *
 *  @param path xml file's path
 */
xmlManager::xmlManager(std::string path)
{
    vers = new TiXmlDeclaration( "1.0", "", "" );
    doc.LinkEndChild( vers );
    xmlFileName = path;
}

/**
 *  Destructor
 */
xmlManager::~xmlManager()
{
    
}

/**
 *  Set xml file name
 *
 *  @param n file name
 *
 *  @return return true
 */
bool xmlManager::setFilename(const std::string & n)
{
    xmlFileName = n;
    return true;
}

bool xmlManager::addChild( const std::string & parent, std::string & newChild)
{
    TiXmlElement * node = getNode(parent);
    
    if (node == NULL)
        return false;
    
    TiXmlText * childLeaves = new TiXmlText( newChild );
    
    node->LinkEndChild( childLeaves );
    
    save();
    return true;
}

bool xmlManager::isSaved()
{
    return saved;
}

TiXmlElement * xmlManager::getNode(const std::string & node)
{
    TiXmlElement * root = doc.RootElement();
    bool found = false;
    
    while (root && !found)
    {
        if (node.compare((root->ValueStr())))
            found = true;
        else
            root = root->NextSiblingElement();
    }
    
    if (!found)
        return NULL;
    else
        return root;
    
}

bool xmlManager::addNode(std::string & parent, std::string & newNode)
{

    TiXmlElement * node = getNode(parent);
    
    if (node == NULL)
        return false;
    
    TiXmlElement *child = new TiXmlElement(newNode);
    node->LinkEndChild( child );
    
    save();
    return true;
}

bool xmlManager::removeElement(std::string parent, std::string child)
{
    TiXmlElement * node = getNode(parent);
    TiXmlElement * childNode = getNode(child);

    if (node == NULL || childNode == NULL)
        return false;
    
    return node->RemoveChild(childNode);
}

bool xmlManager::removeALLChild(std::string parent)
{
    TiXmlElement * node = getNode(parent);
    
    if (node == NULL)
        return false;
    
    node->Clear();
    
    return true;
}

bool xmlManager::setPath(std::string p )
{
    path = p;
    return true;
}

std::string xmlManager::getPath()
{
    
    return path;
}

std::string & xmlManager::getFilename(void)
{
    return xmlFileName;
}

bool xmlManager::load(std::string)
{
    return doc.LoadFile(xmlFileName);
}

bool xmlManager::save()
{
    doc.SaveFile( xmlFileName);
    saved = true;
    lastStore = std::time(nullptr);
    return true;
}