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
#include <vector>
#include "podofo.h"

class Creator
{

public:
    Creator(std::string, std::string);
    ~Creator();
    
private:
    std::string path;
    std::string outFileName;
    std::string inFileName;
    
    /*
    * PdfPainter is the class which is able to draw text and graphics
    * directly on a PdfPage object.
    */
    PoDoFo::PdfPainter painter;
    
    /*
     * This pointer will hold the page object later.
     * PdfSimpleWriter can write several PdfPage's to a PDF file.
     */
    PoDoFo::PdfPage* pPage;
    
    /*
     * A PdfFont object is required to draw text on a PdfPage using a PdfPainter.
     * PoDoFo will find the font using fontconfig on your system and embedd truetype
     * fonts automatically in the PDF file.
     */
    PoDoFo::PdfFont* pFont;
    
public:
    bool createDoc();
    bool createOdt();
    bool createPdf();
    
private:
    void pathCheck();
    
};
#endif /* defined(__baggre__creator__) */
