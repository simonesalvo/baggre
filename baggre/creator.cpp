//
//  creator.cpp
//  baggre
//
//  Created by Simone Salvo on 10/11/14.
//  Copyright (c) 2014 Simone Salvo. All rights reserved.
//

#include "creator.h"
#include <fstream>

Creator::Creator(std::string p, std::string n)
{
    path = p;
    outFileName = "output.pdf";
    inFileName = n;
}

Creator::~Creator()
{
    
}

bool Creator::createPdf()
{
    
    PoDoFo::PdfStreamedDocument document((path+outFileName).c_str());
    
    try
    {
        
        pPage = document.CreatePage( PoDoFo::PdfPage::CreateStandardPageSize( PoDoFo::ePdfPageSize_A4 ) );
    
        if( !pPage )
        {
            PODOFO_RAISE_ERROR( PoDoFo::ePdfError_InvalidHandle );
        }
        
        painter.SetPage( pPage );

        pFont = document.CreateFont( "Arial" );
        
        /*
         * If the PdfFont object cannot be allocated return an error.
         */
        if( !pFont )
        {
            PODOFO_RAISE_ERROR( PoDoFo::ePdfError_InvalidHandle );
        }
        
        pFont->SetFontSize( 18.0 );
        painter.SetFont( pFont );
        
        std::string tLine;
        std::ifstream inFile;

        PoDoFo::PdfRect::PdfRect rect = document.GetPage(0)->GetMediaBox();
        inFile.open (path+inFileName, std::ios::in);

        while(std::getline(inFile,tLine))
        {
            painter.DrawMultiLineText(rect, tLine.c_str());
        }
        inFile.close();

        painter.FinishPage();
        
        document.GetInfo()->SetCreator ( PoDoFo::PdfString::PdfString("Baggre"));
        document.GetInfo()->SetAuthor  ( PoDoFo::PdfString::PdfString("Simone Salvo") );
        document.GetInfo()->SetTitle   ( PoDoFo::PdfString::PdfString("Baggre unique") );
        document.GetInfo()->SetKeywords( PoDoFo::PdfString::PdfString("Baggre;"));
        // document.GetInfo()->SetSubject ( PdfString("Testing the PoDoFo PDF Library") );
        // document.GetInfo()->SetKeywords( PdfString("Test;PDF;Hello World;"));
        
        document.Close();
        
    }
    catch ( const PoDoFo::PdfError & e )
    {
        try
        {
          painter.FinishPage();
        }
        catch(const PoDoFo::PdfError & e )
        {
        }
        throw e;
    }

    
    /**
     * Free global memory allocated by PoDoFo.
     * This is normally not necessary as memory
     * will be free'd when the application terminates.
     *
     * If you want to free all memory allocated by
     * PoDoFo you have to call this method.
     *
     * PoDoFo will reallocate the memory if necessary.
     */
  //  PoDoFo::PdfEncodingFactory::FreeGlobalEncodingInstances();
    
    return true;
}

bool Creator::createOdt()
{
    
    return true;
}

bool Creator::createDoc()
{

    return true;
}


