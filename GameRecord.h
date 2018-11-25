#include "AnswerMaker.h"
#include "GameConfig.h"
#include <vector>
#ifndef GAMERECORD_H
#define GAMERECORD_H
using namespace std;

struct GameTime{
    int currentTurn;
    int currentEntry;
    int answer[16];
    int red;
    int white;
    bool isScam;
    bool victory;
    bool GameInProgress;
    AnswerMaker* GameAns;
    int entryArr[16];
    char entryArrBugfix[16];
    int redMatch[16];
    vector<int> entryLog;
    vector<int>::iterator logIterator;
public:
    GameConfig GameMode;
    GameTime();
    void updateLog(int entry);
    bool checkAnswer();
    int turnLine();
    void generateAnswer(GameConfig);
    void redScan();
    void whiteScan();
    int getWhite();
    int getRed();
    int getCurrentEntry();
    int getCurrentTurn();
    void feedIt(GameConfig);

};

extern GameTime TheRealGame;
#endif // GAMERECORD_H
