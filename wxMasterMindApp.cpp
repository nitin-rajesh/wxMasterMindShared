/***************************************************************
 * Name:      wxMasterMindApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ITGuy ()
 * Created:   2018-11-12
 * Copyright: ITGuy ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "wxMasterMindApp.h"
#include "Solver.h"

//(*AppHeaders
#include "wxMasterMindMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(wxMasterMindApp);

bool wxMasterMindApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	wxMasterMindFrame* Frame = new wxMasterMindFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
