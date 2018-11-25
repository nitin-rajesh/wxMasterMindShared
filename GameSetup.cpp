#include "wx_pch.h"
#include "GameSetup.h"
#include "GameConfig.h"
#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(GameSetup)
	#include <wx/string.h>
	#include <wx/intl.h>
	//*)
#endif
//(*InternalHeaders(GameSetup)
#include <wx/font.h>
//*)

//(*IdInit(GameSetup)
const long GameSetup::ID_STATICTEXT1 = wxNewId();
const long GameSetup::ID_STATICTEXT2 = wxNewId();
const long GameSetup::ID_CHOICE1 = wxNewId();
const long GameSetup::ID_CHECKBOX1 = wxNewId();
const long GameSetup::ID_STATICTEXT3 = wxNewId();
const long GameSetup::ID_CHOICE2 = wxNewId();
const long GameSetup::ID_BUTTON1 = wxNewId();
const long GameSetup::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(GameSetup,wxDialog)
	//(*EventTable(GameSetup)
	//*)
END_EVENT_TABLE()

GameSetup::GameSetup(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(GameSetup)
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Game\nSetup"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Sawasdee"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	BoxSizer2->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4 = new wxBoxSizer(wxVERTICAL);
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Number of\nColumns"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer4->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ColumnChoice = new wxChoice(Panel1, ID_CHOICE1, wxDefaultPosition, wxSize(80,31), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	ColumnChoice->SetSelection( -1 );
	ColumnChoice->Append(_("4"));
	//ColumnChoice->Append(_("5"));
	ColumnChoice->Append(_("6"));
	//ColumnChoice->Append(_("7"));
	ColumnChoice->Append(_("8"));
	BoxSizer4->Add(ColumnChoice, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
	RepChoice = new wxCheckBox(Panel1, ID_CHECKBOX1, _("Repition"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	RepChoice->SetValue(false);
	BoxSizer4->Add(RepChoice, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3 = new wxBoxSizer(wxVERTICAL);
	StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Number of\nDigits"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	BoxSizer3->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	DigitChoice = new wxChoice(Panel1, ID_CHOICE2, wxDefaultPosition, wxSize(80,31), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
	DigitChoice->SetSelection( -1 );
	DigitChoice->Append(_("8"));
	DigitChoice->Append(_("10"));
	DigitChoice->Append(_("12"));
	DigitChoice->Append(_("14"));
	BoxSizer3->Add(DigitChoice, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
	Button1 = new wxButton(Panel1, ID_BUTTON1, _("Save"), wxDefaultPosition, wxSize(46,34), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer3->Add(Button1, 1, wxALL|wxALIGN_RIGHT, 5);
	BoxSizer2->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(BoxSizer2);
	BoxSizer2->Fit(Panel1);
	BoxSizer2->SetSizeHints(Panel1);
	BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&GameSetup::numberOfColumns);
	Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&GameSetup::activateRepeat);
	Connect(ID_CHOICE2,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&GameSetup::numberOfDigits);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&GameSetup::pseudoSave);
	//*)
}

GameSetup::~GameSetup()
{
	//(*Destroy(GameSetup)
	//*)
}


void GameSetup::numberOfColumns(wxCommandEvent& event)
{
    int val = ColumnChoice->GetCurrentSelection();

    GameMode.numberOfColumns=val*2+4;
    wxString stringnumber = wxString::Format(wxT("%d"), GameMode.numberOfColumns);
    //wxMessageBox(stringnumber);
}

void GameSetup::numberOfDigits(wxCommandEvent& event)
{
    int val = DigitChoice->GetCurrentSelection();

    GameMode.numberOfColours=val*2+8;
    wxString stringnumber = wxString::Format(wxT("%d"), GameMode.numberOfColours);
    //wxMessageBox(stringnumber);
}

void GameSetup::pseudoSave(wxCommandEvent& event)
{
    Close();
}

void GameSetup::activateRepeat(wxCommandEvent& event)
{
    GameMode.isRepeat = RepChoice->GetValue();
    //wxMessageBox(stringnumber);

}
