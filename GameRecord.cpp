#include "GameRecord.h"
#include <vector>
using namespace std;

GameTime::GameTime(){
    victory = false;
    GameInProgress = false;
    isScam = false;
}
void GameTime::feedIt(GameConfig GameMode){
    this->GameMode=GameMode;
    currentTurn=0;
    currentEntry=0;
    victory = false;
    GameInProgress = true;

}

void GameTime::redScan(){
    red = 0;
    int* redPtr = redMatch;
    for(int i = 0; i < GameMode.numberOfColumns; i++){
        if(entryArr[i]==answer[i]){
            red++;
            *redPtr = i;
            redPtr++;
        }
    }
}

void GameTime::whiteScan(){
    white = 0;
    bool isRedMatch = false;
    for(int i = 0; i < GameMode.numberOfColumns; i++){
        isRedMatch = false;
        for(int j = 0; j < GameMode.numberOfColours; j++){
            for(int k = 0; k < red; k++){
                if(i==redMatch[k]){
                    isRedMatch = true;
                    break;
                }
            }
            if(isRedMatch)
                continue;
            if(entryArr[j]==answer[i]){
                white++;
                break;
            }
        }
    }
    if(red == GameMode.numberOfColumns){
        victory = true;
        //GameInProgress = false;
    }
}


void GameTime::updateLog(int entry){

    entryLog.push_back(entry);
    int allocPos = currentEntry%GameMode.numberOfColumns;
    entryArr[allocPos] = entry;
    currentEntry++;
    if(currentEntry%(GameMode.numberOfColumns+1)==0){
        currentTurn++;
        currentEntry=1;
    }
    if(currentEntry%GameMode.numberOfColumns==0){
        redScan();
        whiteScan();
    }
}

int GameTime::turnLine(){
    return (currentTurn+1)*30 - 5;
}

void GameTime::generateAnswer(GameConfig GameMode){
    int seed;
    seed = time(new time_t);
    srand(seed);
    for(int i = 0; i< GameMode.numberOfColumns; i++){
        answer[i]=rand()%GameMode.numberOfColours+1;
        if(!GameMode.isRepeat){
            for(int j = 0; j < i; j++){
                if(answer[j]==answer[i]){
                    i--;
                    break;
                }
            }
        }
    }
}

int GameTime::getRed(){
    return red;
}

int GameTime::getWhite(){
    return white;
}

int GameTime::getCurrentEntry(){
    return currentEntry;
}

int GameTime::getCurrentTurn(){
    return currentTurn;
}
