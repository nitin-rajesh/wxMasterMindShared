#include "wx_pch.h"
#include "RulesOfGames.h"

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(RulesOfGames)
	#include <wx/string.h>
	#include <wx/intl.h>
	//*)
#endif
//(*InternalHeaders(RulesOfGames)
//*)

//(*IdInit(RulesOfGames)
const long RulesOfGames::ID_STATICTEXT1 = wxNewId();
const long RulesOfGames::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(RulesOfGames,wxDialog)
	//(*EventTable(RulesOfGames)
	//*)
END_EVENT_TABLE()

RulesOfGames::RulesOfGames(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(RulesOfGames)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Welcome to Mastermind Version 2 !\n\nHOW TO PLAY\n\nThe computer picks a sequence of four numbers. The numbers range from 1 to 8. Your objective is to guess that numbers, with all of its digits in the correct order.\n\nAfter filling a line with your guesses, the computer responses with the result of your guess.\n\nRed counts the numbers in your guess that are of the correct value and in correct position in the code sequence.\n\nWhite counts the numbers in your guess with the correct value but NOT in the correct position in the code sequence.\n\nYou win the game when you manage to guess all the colors in the code sequence and when they all in the right position before running out of tries.\n\nThe customization menu lets you select the number of digits, the number of columns and enable repititions in digits for the answer.\nAdd more digits and columns for a more challenging gameplay.\n\n"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer2->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(BoxSizer2);
	BoxSizer2->Fit(Panel1);
	BoxSizer2->SetSizeHints(Panel1);
	BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	//*)
}

RulesOfGames::~RulesOfGames()
{
	//(*Destroy(RulesOfGames)
	//*)
}

