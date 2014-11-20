//
//  xmlManager.cpp
//  baggre
//
//  Created by Simone Salvo on 12/11/14.
//  Copyright (c) 2014 Simone Salvo. All rights reserved.
//

#include "xmlManager.h"

xmlManager::xmlManager()
: xmlFileName("sample.xml"),
saved(false),
path("")
{
    // Make xml
    vers = new TiXmlDeclaration( "1.0", "", "" );
    doc.LinkEndChild( vers );
}

std::string xmlManager::getXmlFilename()
{
    return xmlFileName;
}

void xmlManager::setFilename(std::string n)
{
    xmlFileName = n;
}

bool xmlManager::addChild(std::string & parent, std::string & newChild)
{
    TiXmlElement * node = getNode(parent);
    
    if (node == NULL)
        return false;
    
    TiXmlText * childLeaves = new TiXmlText( newChild );
    
    node->LinkEndChild( childLeaves );
    
    saveXml();
    return true;
}

bool xmlManager::isSaved()
{
    return saved;
}

TiXmlElement * xmlManager::getNode(std::string & node)
{
    TiXmlElement * root = doc.RootElement(); //Tree root
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
    
    saveXml();
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

std::string xmlManager::getFilename()
{
    return xmlFileName;
}
bool xmlManager::loadXml(std::string)
{
    return true;
}

bool xmlManager::saveXml()
{
    doc.SaveFile( xmlFileName);
    saved = true;
    lastStore = std::time(nullptr);
    return true;
}