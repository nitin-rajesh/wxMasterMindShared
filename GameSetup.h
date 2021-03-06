#ifndef GAMESETUP_H
#define GAMESETUP_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(GameSetup)
	#include <wx/checkbox.h>
	#include <wx/dialog.h>
	#include <wx/sizer.h>
	#include <wx/button.h>
	#include <wx/panel.h>
	#include <wx/stattext.h>
	#include <wx/choice.h>
	//*)
#endif
//(*Headers(GameSetup)
//*)

class GameSetup: public wxDialog
{
	public:

		GameSetup(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~GameSetup();

		//(*Declarations(GameSetup)
		wxPanel* Panel1;
		wxButton* Button1;
		wxCheckBox* RepChoice;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxChoice* DigitChoice;
		wxStaticText* StaticText2;
		wxChoice* ColumnChoice;
		//*)

	protected:

		//(*Identifiers(GameSetup)
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_CHOICE1;
		static const long ID_CHECKBOX1;
		static const long ID_STATICTEXT3;
		static const long ID_CHOICE2;
		static const long ID_BUTTON1;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(GameSetup)
		void numberOfColumns(wxCommandEvent& event);
		void numberOfDigits(wxCommandEvent& event);
		void pseudoSave(wxCommandEvent& event);
		void activateRepeat(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
                                                                                                    