#ifndef PLAYAREA_H
#define PLAYAREA_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(PlayArea)
	#include <wx/dialog.h>
	#include <wx/sizer.h>
	#include <wx/button.h>
	#include <wx/radiobut.h>
	#include <wx/panel.h>
	#include <wx/stattext.h>
	#include <wx/choice.h>
	//*)
#endif
//(*Headers(PlayArea)
//*)

class PlayArea: public wxDialog
{
	public:

		PlayArea(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~PlayArea();

		//(*Declarations(PlayArea)
		wxPanel* Panel1;
		wxButton* Button2;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxRadioButton* RepChoice;
		wxStaticText* StaticText2;
		wxChoice* ColumnChoice;
		wxChoice* ColourChoice;
		//*)

	protected:

		//(*Identifiers(PlayArea)
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_CHOICE1;
		static const long ID_RADIOBUTTON1;
		static const long ID_STATICTEXT3;
		static const long ID_CHOICE2;
		static const long ID_BUTTON2;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(PlayArea)
		void RepititionBool(wxCommandEvent& event);
		void numberOfColumns(wxCommandEvent& event);
		void numberOfColours(wxCommandEvent& event);
		void saveButton(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
                                                                                                                                                                            