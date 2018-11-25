#ifndef GAMECONFIG_H
#define GAMECONFIG_H

struct GameConfig{
    int numberOfColumns;
    int numberOfColours;
    bool isRepeat;

    GameConfig(){
        numberOfColours=8;
        numberOfColumns=4;
        isRepeat=false;
    };
    GameConfig(int,int,bool);
    ~GameConfig(){};
};
extern GameConfig GameMode;
#endif // GAMECONFIG_H

