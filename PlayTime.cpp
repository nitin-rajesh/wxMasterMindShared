#include "wx_pch.h"
#include "PlayTime.h"
#include "GameConfig.h"
#include "GameRecord.h"
#include "Solver.h"
#include <time.h>
#include <vector>
#include <string>
#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(PlayTime)
	#include <wx/string.h>
	#include <wx/intl.h>
	//*)
#endif
//(*InternalHeaders(PlayTime)
#include <wx/settings.h>
#include <wx/font.h>
//*)
using namespace std;
//IdInit(PlayTime)
const long PlayTime::ID_STATICTEXT1 = wxNewId();
const long PlayTime::ID_COLOURCOMPLEX = wxNewId();
const long PlayTime::ID_SCROLLEDWINDOW1 = wxNewId();
const long PlayTime::ID_THEBUTTON = wxNewId();
/*const long PlayTime::ID_BUTTON1 = wxNewId();
const long PlayTime::ID_BUTTON3 = wxNewId();
const long PlayTime::ID_BUTTON2 = wxNewId();
const long PlayTime::ID_BUTTON4 = wxNewId();
const long PlayTime::ID_BUTTON5 = wxNewId();
const long PlayTime::ID_BUTTON6 = wxNewId();
const long PlayTime::ID_BUTTON7 = wxNewId();
const long PlayTime::ID_BUTTON8 = wxNewId();*/
const long PlayTime::ID_BUTTON9 = wxNewId();
const long PlayTime::ID_GAUGE1 = wxNewId();
const long PlayTime::ID_CLEARBUTTON = wxNewId();
const long PlayTime::ID_AIBUTTON = wxNewId();
const long PlayTime::ID_ANSWERBOX = wxNewId();
//*)

BEGIN_EVENT_TABLE(PlayTime,wxFrame)
	//(*EventTable(PlayTime)
	//*)
END_EVENT_TABLE()

PlayTime::PlayTime(wxWindow* parent,wxWindowID id)
{
	//Initialize(PlayTime)
    int numberOfTries = GameMode.numberOfColumns*2 + (GameMode.numberOfColours - 8)*2;
    if(GameMode.isRepeat){
        numberOfTries += 4;
    }
	wxGridSizer* GridSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;

    TheRealGame.feedIt(GameMode);

    TheRealGame.generateAnswer(GameMode);
    int scrollSize;
    int windowSize = numberOfTries * 70;
    if(windowSize > 800){
        scrollSize = windowSize;
        windowSize = 800;
    }
	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	int maxSize = 256+GameMode.numberOfColumns*20;
	SetClientSize(wxSize(maxSize,windowSize + 128));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	ScrolledWindow1 = new wxScrolledWindow(this, ID_SCROLLEDWINDOW1, wxDefaultPosition, wxSize(maxSize*4,windowSize), wxVSCROLL|wxHSCROLL, _T("ID_SCROLLEDWINDOW1"));
	ScrolledWindow1->SetForegroundColour(wxColour(255,255,255));
	ScrolledWindow1->SetBackgroundColour(wxColour(255,255,255));


    //wxMessageBox(stringnumber);

	BoxSizer1->Add(ScrolledWindow1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	GridSizer1 = new wxGridSizer(2, 8, 0, 0);
    int j;

	//Drawing the buttons
    char c[3];
    wxString stringnumber = wxString::Format(wxT("%d"), GameMode.numberOfColours);
    //wxMessageBox(stringnumber);

	for(int k = 0; k < GameMode.numberOfColours; k++){

        c[0] = k<9?k+'1':'1';
        c[1] = k<9?'\0':k%10+'1';
        if(k==9)
            c[1]='0';
        c[2]='\0';
        theButton[k] = new wxButton(this, ID_THEBUTTON, _(c), wxDefaultPosition, wxSize(30,25), 0, wxDefaultValidator, _T("ID_THEBUTTON"));
        GridSizer1->Add(theButton[k], 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    }

	BoxSizer1->Add(GridSizer1, 0, wxALIGN_CENTER_HORIZONTAL, 0);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);


	Button9 = new wxButton(this, ID_BUTTON9, _("SOLVE!"), wxDefaultPosition, wxSize(50,50), 0, wxDefaultValidator, _T("ID_BUTTON9"));
	ClearButton = new wxButton(this, ID_CLEARBUTTON, _("Clear"), wxDefaultPosition, wxSize(50,50), 0, wxDefaultValidator, _T("ID_CLEARBUTTON"));
	BoxSizer2->Add(ClearButton, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	AnswerBox = new wxStaticText(this, ID_ANSWERBOX, " ", wxDefaultPosition, wxDefaultSize, 0, _T("ID_ANSWERBOX"));
	BoxSizer2->Add(AnswerBox, 1, wxALL|wxALIGN_CENTER, 5);
	BoxSizer2->Add(0,0,wxEXPAND,5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

	//Remove this comment to activate AI button

	AIButton = new wxButton(this, ID_AIBUTTON, _("A I"), wxDefaultPosition, wxSize(50,50), 0, wxDefaultValidator, _T("ID_AIBUTTON"));
	BoxSizer2->Add(AIButton, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);

	BoxSizer2->Add(Button9, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	SetSizer(BoxSizer1);
	Layout();
	//*)
	ScrolledWindow1->EnableScrolling(true,true);
	ScrolledWindow1->SetVirtualSize(maxSize*4,scrollSize);
	ScrolledWindow1->SetScrollRate(0,10);

	//The text part
	int i;
	int choice = GameMode.numberOfColumns;
	char str[choice*2+1];
	for(i = 0; i < choice*3;){
        str[i++]='*';
        str[i++]=' ';
        str[i++]=' ';
	}
	str[i]='\0';
	for(int i = 0; i < numberOfTries; i++){
        StaticText1[i] = new wxStaticText(ScrolledWindow1, ID_STATICTEXT1, _(str), wxPoint(0,(i)*65+25), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
        StaticText1[i]->SetForegroundColour(wxColour(0,0,0));
        wxFont StaticText1Font(14,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Sawasdee"),wxFONTENCODING_DEFAULT);
        StaticText1[i]->SetFont(StaticText1Font);
	}


	//The colour coding
	int rowsDrawn = 0;
	int rowNo = 0;
    j = 0;
    int vecPos = 0;
    for(int k = 0; k < numberOfTries; k++){
        for(i = 0; i < 2; i++){
            for(j = 0; j < GameMode.numberOfColumns/2; j++){
                ColourComplex[k][vecPos] = new wxTextCtrl(ScrolledWindow1, ID_COLOURCOMPLEX, wxEmptyString, wxPoint(maxSize-30*(j+1)-10,rowNo*30 + k*5/*+TheRealGame->turnLine()-25*/), wxSize(29,29), 0, wxDefaultValidator, _T("ID_ColourComplex"));
                ColourComplex[k][vecPos]->Disable();
                ColourComplex[k][vecPos]->SetForegroundColour(wxColour(200,200,200));
                ColourComplex[k][vecPos]->SetBackgroundColour(wxColour(100,100,100));
                wxString stringnumber = wxString::Format(wxT("%d"), GameMode.numberOfColumns);

                vecPos++;
            }
            rowNo++;

        }
        vecPos=0;
    }

    Connect(ID_BUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PlayTime::GO);
    Connect(ID_THEBUTTON,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PlayTime::Input);
    Connect(ID_CLEARBUTTON,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PlayTime::Clear);
    Connect(ID_AIBUTTON,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PlayTime::AI);
    /*Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxMasterMindFrame::configureMenu);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxMasterMindFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxMasterMindFrame::OnAbout);*/
}


PlayTime::~PlayTime()
{
    TheRealGame.GameInProgress = false;
}

void PlayTime::Input(wxCommandEvent& event){
    int numberOfTries = GameMode.numberOfColumns*2 + (GameMode.numberOfColours - 8)*2;
    if(!TheRealGame.victory){

        wxButton* pButton = wxDynamicCast(event.GetEventObject(), wxButton);
        wxString sLabel = pButton->GetLabel();
        wxString sName = pButton->GetName();
        char entryChar[16];
        strncpy(entryChar, (const char*)sLabel.mb_str(wxConvUTF8), 3);

        int entryVal = entryChar[0]-'0';
        if(entryChar[1]!='\0')
            entryVal = 10 + (entryChar[1]-'0');

        wxString stringnumber = wxString::Format(wxT("%d"), entryVal);

        TheRealGame.updateLog(entryVal);

        string dispVal = "";

        for(int i = 0; i < TheRealGame.currentEntry; i++){
            dispVal = dispVal + to_string(TheRealGame.entryArr[i]) + "  ";
        }

        for(int i = TheRealGame.currentEntry; i < TheRealGame.GameMode.numberOfColumns; i++){
            dispVal = dispVal + "*  ";
        }

        StaticText1[TheRealGame.currentTurn]->SetLabel(dispVal);

        if(TheRealGame.currentEntry == GameMode.numberOfColumns){

            for(int i = 0; i < GameMode.numberOfColumns; i++){
                if(TheRealGame.red > 0){
                    ColourComplex[TheRealGame.currentTurn][i]->SetBackgroundColour(wxColour(255,0,0));
                    TheRealGame.red--;
                }
                else if(TheRealGame.white > 0){
                    ColourComplex[TheRealGame.currentTurn][i]->SetBackgroundColour(wxColour(230,230,230));
                    TheRealGame.white--;
                }

            }
        }

    }

    if(TheRealGame.victory && !TheRealGame.isScam){
        wxMessageBox("YOU WIN!!");
        Close();
    }
    else if(TheRealGame.victory && TheRealGame.isScam){
        wxMessageBox("Victory falsified :o");
        Close();
    }

    if(!TheRealGame.victory && ((numberOfTries - 1) == (TheRealGame.currentTurn)) && TheRealGame.currentEntry == (GameMode.numberOfColumns)){
        string dispVal = "Out of turns :(\n\nAnswer: ";
        for(int i = 0; i < TheRealGame.GameMode.numberOfColumns; i++){
            dispVal = dispVal + to_string(TheRealGame.answer[i]) + "  ";
        }
        wxMessageBox(dispVal);
        Close();
    }
}


void PlayTime::GO(wxCommandEvent& event){

    TheRealGame.isScam = true;
    string dispVal = "ANSWER:  ";
    for(int i = 0; i < TheRealGame.GameMode.numberOfColumns; i++){
        dispVal = dispVal + to_string(TheRealGame.answer[i]) + "  ";
    }

    AnswerBox->SetLabel(dispVal);


}

void PlayTime::Clear(wxCommandEvent& event){
    string dispVal = "";
    if(TheRealGame.currentEntry < GameMode.numberOfColumns){
        TheRealGame.currentEntry = GameMode.numberOfColumns;
        for(int i = 0; i < TheRealGame.GameMode.numberOfColumns; i++){
            dispVal = dispVal + "*  ";
        }
        StaticText1[TheRealGame.currentTurn]->SetLabel(dispVal);
        TheRealGame.currentTurn--;
    }

}

void PlayTime::AI(wxCommandEvent& event){
    //Add solver logic here
    int ansArr[64][GameMode.numberOfColumns];
    int holder;
    vector<int*>* answerVector = new vector<int*>();
    Solver* aiSolver = new Solver(TheRealGame.answer,GameMode.numberOfColumns,GameMode.numberOfColours,GameMode.isRepeat);
    aiSolver->solve();
    answerVector = aiSolver->getGuesses();
    vector<int*>::iterator answerIter;
    answerIter = answerVector->begin();
    int k = 0;
    do{
        //wxMessageBox("Looping");
        //for(int i = 0; i < GameMode.numberOfColumns; i++){
            holder = **answerIter;
        //}
        //k++;
        (*answerIter)++;

    }while(answerIter != answerVector->end());
    wxMessageBox("Fake button");

    //delete aiSolver;
    //delete answerVector;

}
