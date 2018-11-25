#ifndef PLAYTIME_H
#define PLAYTIME_H
#ifndef WX_PRECOMP
	//(*HeadersPCH(PlayTime)
	#include <wx/gauge.h>
	#include <wx/sizer.h>
	#include <wx/button.h>
	#include <wx/scrolwin.h>
	#include <wx/frame.h>
	#include <wx/stattext.h>
	#include <wx/textctrl.h>
	//*)
#endif
#include "GameRecord.h"
//(*Headers(PlayTime)
//*)

class PlayTime: public wxFrame
{
	public:

		PlayTime(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~PlayTime();

		//Declarations(PlayTime)
		wxScrolledWindow* ScrolledWindow1;
		wxButton* theButton[16];
		wxButton* Button4;
		wxButton* Button1;
		wxButton* Button2;
		wxButton* Button3;
		wxStaticText* StaticText1[64];
		wxStaticText* AnswerBox;
		wxButton* Button8;
		wxButton* Button5;
		wxButton* Button9;
		wxButton* AIButton;
		wxButton* ClearButton;
		wxTextCtrl* ColourComplex[64][8];
		wxGauge* Gauge1;
		wxButton* Button7;
		wxButton* Button6;
		//*)

	protected:

		//Identifiers(PlayTime)
		static const long ID_STATICTEXT1;
		static const long ID_COLOURCOMPLEX;
		static const long ID_SCROLLEDWINDOW1;
		static const long ID_THEBUTTON;
		static const long ID_CLEARBUTTON;
		/*static const long ID_BUTTON1;
		static const long ID_BUTTON3;
		static const long ID_BUTTON2;
		static const long ID_BUTTON4;
		static const long ID_BUTTON5;
		static const long ID_BUTTON6;
		static const long ID_BUTTON7;
		static const long ID_BUTTON8;*/
		static const long ID_BUTTON9;
		static const long ID_GAUGE1;
		static const long ID_ANSWERBOX;
		static const long ID_AIBUTTON;
		//*)

	private:

		//Handlers(PlayTime)
            void Clear(wxCommandEvent& event);
            void GO(wxCommandEvent& event);
            void Input(wxCommandEvent& event);
            void AI(wxCommandEvent& event);
            //void configureMenu(wxCommandEvent& event)

		//*)

		DECLARE_EVENT_TABLE()
};

#endif
