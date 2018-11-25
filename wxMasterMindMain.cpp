/***************************************************************
 * Name:      wxMasterMindMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    ITGuy ()
 * Created:   2018-11-12
 * Copyright: ITGuy ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "wxMasterMindMain.h"
#include <wx/msgdlg.h>
#include "GameSetup.h"
#include "PlayTime.h"
#include "GameConfig.h"
#include "GameRecord.h"
#include "Solver.h"
#include "RulesOfGames.h"
//(*InternalHeaders(wxMasterMindFrame)
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/font.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(wxMasterMindFrame)
const long wxMasterMindFrame::ID_STATICTEXT1 = wxNewId();
const long wxMasterMindFrame::ID_BUTTON1 = wxNewId();
const long wxMasterMindFrame::ID_BUTTON2 = wxNewId();
const long wxMasterMindFrame::ID_BUTTON3 = wxNewId();
const long wxMasterMindFrame::ID_PANEL1 = wxNewId();
const long wxMasterMindFrame::idMenuQuit = wxNewId();
const long wxMasterMindFrame::idMenuAbout = wxNewId();
const long wxMasterMindFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wxMasterMindFrame,wxFrame)
    //(*EventTable(wxMasterMindFrame)
    //*)
END_EVENT_TABLE()

wxMasterMindFrame::wxMasterMindFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(wxMasterMindFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxGridSizer* GridSizer1;
    wxMenu* Menu1;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Panel1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    Panel1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOWTEXT));
    GridSizer1 = new wxGridSizer(3, 3, 0, 0);
    GridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Master Mind"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    GridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("Start"), wxDefaultPosition, wxSize(107,48), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    Button1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    wxFont Button1Font(16,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    Button1->SetFont(Button1Font);
    GridSizer1->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(Panel1, ID_BUTTON2, _("Configure"), wxDefaultPosition, wxSize(174,31), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    GridSizer1->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button3 = new wxButton(Panel1, ID_BUTTON3, _("\?"), wxDefaultPosition, wxSize(38,31), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    GridSizer1->Add(Button3, 1, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 5);
    Panel1->SetSizer(GridSizer1);
    GridSizer1->Fit(Panel1);
    GridSizer1->SetSizeHints(Panel1);
    BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxMasterMindFrame::StartNewGame);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxMasterMindFrame::configureMenu);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxMasterMindFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxMasterMindFrame::OnAbout);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxMasterMindFrame::showRules);
    //*)
}
GameConfig GameMode;
GameTime TheRealGame;
wxMasterMindFrame::~wxMasterMindFrame()
{
    //(*Destroy(wxMasterMindFrame)
    //*)
}

void wxMasterMindFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void wxMasterMindFrame::OnAbout(wxCommandEvent& event)
{
    //wxString msg = wxbuildinfo(long_f);
    wxMessageBox("Created by the\n\nITGuy", _("v2.6.9"));
}

void wxMasterMindFrame::StartNewGame(wxCommandEvent& event)
{
    if(!TheRealGame.GameInProgress){
        PlayTime *world = new PlayTime(NULL);
        world->Show(TRUE);
        event.Skip();
    }
}

void wxMasterMindFrame::configureMenu(wxCommandEvent& event)
{
    GameSetup dialog(this);
    dialog.ShowModal();
}

void wxMasterMindFrame::showRules(wxCommandEvent& event)
{
    RulesOfGames dialog(this);
    dialog.ShowModal();
}
