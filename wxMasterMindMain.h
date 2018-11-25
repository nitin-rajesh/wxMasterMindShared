/***************************************************************
 * Name:      wxMasterMindMain.h
 * Purpose:   Defines Application Frame
 * Author:    ITGuy ()
 * Created:   2018-11-12
 * Copyright: ITGuy ()
 * License:
 **************************************************************/

#ifndef WXMASTERMINDMAIN_H
#define WXMASTERMINDMAIN_H

//(*Headers(wxMasterMindFrame)
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/stattext.h>
//*)

class wxMasterMindFrame: public wxFrame
{
    public:

        wxMasterMindFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~wxMasterMindFrame();

    private:

        //(*Handlers(wxMasterMindFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void StartNewGame(wxCommandEvent& event);
        void configureMenu(wxCommandEvent& event);
        void showRules(wxCommandEvent& event);
        //*)

        //(*Identifiers(wxMasterMindFrame)
        static const long ID_STATICTEXT1;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(wxMasterMindFrame)
        wxPanel* Panel1;
        wxStatusBar* StatusBar1;
        wxButton* Button1;
        wxButton* Button2;
        wxButton* Button3;
        wxStaticText* StaticText1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // WXMASTERMINDMAIN_H
