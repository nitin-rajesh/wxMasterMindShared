#ifndef RULESOFGAMES_H
#define RULESOFGAMES_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(RulesOfGames)
	#include <wx/dialog.h>
	#include <wx/sizer.h>
	#include <wx/panel.h>
	#include <wx/stattext.h>
	//*)
#endif
//(*Headers(RulesOfGames)
//*)

class RulesOfGames: public wxDialog
{
	public:

		RulesOfGames(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~RulesOfGames();

		//(*Declarations(RulesOfGames)
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		//*)

	protected:

		//(*Identifiers(RulesOfGames)
		static const long ID_STATICTEXT1;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(RulesOfGames)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
                                                        