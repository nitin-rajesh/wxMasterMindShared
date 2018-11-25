#include "wx_pch.h"
#include "PlayArea.h"
#include "GameConfig.h"
#include <iostream>
#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(PlayArea)
	#include <wx/string.h>
	#include <wx/intl.h>
	//*)
#endif
//(*InternalHeaders(PlayArea)
#include <wx/font.h>
//*)

//(*IdInit(PlayArea)
const long PlayArea::ID_STATICTEXT1 = wxNewId();
const long PlayArea::ID_STATICTEXT2 = wxNewId();
const long PlayArea::ID_CHOICE1 = wxNewId();
const long PlayArea::ID_RADIOBUTTON1 = wxNewId();
const long PlayArea::ID_STATICTEXT3 = wxNewId();
const long PlayArea::ID_CHOICE2 = wxNewId();
const long PlayArea::ID_BUTTON2 = wxNewId();
const long PlayArea::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(PlayArea,wxDialog)
	//(*EventTable(PlayArea)
	//*)
END_EVENT_TABLE()

PlayArea::PlayArea(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(PlayArea)
	wxGridSizer* GridSizer1;
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer5;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	GridSizer1 = new wxGridSizer(0, 3, 0, 0);
	BoxSizer3 = new wxBoxSizer(wxVERTICAL);
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Game \nSetup"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(16,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	BoxSizer3->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	GridSizer1->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Number of columns"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer2->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ColumnChoice = new wxChoice(Panel1, ID_CHOICE1, wxDefaultPosition, wxSize(82,40), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	ColumnChoice->SetSelection( ColumnChoice->Append(_("4")) );
	ColumnChoice->Append(_("5"));
	ColumnChoice->Append(_("6"));
	ColumnChoice->Append(_("7"));
	ColumnChoice->Append(_("8"));
	BoxSizer2->Add(ColumnChoice, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	RepChoice = new wxRadioButton(Panel1, ID_RADIOBUTTON1, _("Repetitions"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
	BoxSizer2->Add(RepChoice, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	GridSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
	BoxSizer4 = new wxBoxSizer(wxVERTICAL);
	StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Number of colours"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	BoxSizer4->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ColourChoice = new wxChoice(Panel1, ID_CHOICE2, wxDefaultPosition, wxSize(77,27), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
	ColourChoice->SetSelection( ColourChoice->Append(_("8")) );
	ColourChoice->Append(_("9"));
	ColourChoice->Append(_("10"));
	ColourChoice->Append(_("11"));
	ColourChoice->Append(_("12"));
	ColourChoice->Append(_("13"));
	ColourChoice->Append(_("14"));
	ColourChoice->Append(_("15"));
	ColourChoice->Append(_("16"));
	ColourChoice->Append(_("ASCII"));
	BoxSizer4->Add(ColourChoice, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	Button2 = new wxButton(Panel1, ID_BUTTON2, _("Save"), wxDefaultPosition, wxSize(40,31), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer5->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4->Add(BoxSizer5, 1, wxALL|wxALIGN_RIGHT, 5);
	GridSizer1->Add(BoxSizer4, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
	Panel1->SetSizer(GridSizer1);
	GridSizer1->Fit(Panel1);
	GridSizer1->SetSizeHints(Panel1);
	BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&PlayArea::numberOfColumns);
	Connect(ID_RADIOBUTTON1,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&PlayArea::RepititionBool);
	Connect(ID_CHOICE2,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&PlayArea::numberOfColours);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PlayArea::saveButton);
	//*)
}

PlayArea::~PlayArea()
{
	//(*Destroy(PlayArea)
	//*)
}

//GameConfig GameMode;

void PlayArea::RepititionBool(wxCommandEvent& event)
{
    bool selection = RepChoice->GetValue();
    wxString stringnumber = wxString::Format(wxT("%d"), (int)selection);
    //wxMessageBox(stringnumber);

}

void PlayArea::numberOfColumns(wxCommandEvent& event)
{
    int val = ColourChoice->GetCurrentSelection();

//    GameMode.numberOfColumns=val+4;

}

void PlayArea::numberOfColours(wxCommandEvent& event)
{
    int val = ColourChoice->GetCurrentSelection();

    if(val<10){
         GameMode.numberOfColumns=val+8;
    }
    else
        GameMode.numberOfColours=256;
    wxString stringnumber = wxString::Format(wxT("%d"), GameMode.numberOfColours);
    //wxMessageBox(stringnumber);

}

void PlayArea::saveButton(wxCommandEvent& event)
{
    Close();
}
