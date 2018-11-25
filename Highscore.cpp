#include "Highscore.h"
#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;

inline bool fileExists(const std::string& name) {
    ifstream f(name.c_str());
    return f.good();
}
Highscore::Highscore()
{
    //ctor
}
Highscore::Highscore(int numberOfDimensions,int depthOfDimensions,int timeTakenInSeconds){
    this->numberOfDimensions = numberOfDimensions;
    this->depthOfDimensions = depthOfDimensions;
    this->timeTakenInSeconds = timeTakenInSeconds;

    char fileNameTemp[] = "HighscoreXXXX.dat";
    fileNameTemp[9] = numberOfDimensions/10 + '0';
    fileNameTemp[10] = numberOfDimensions % 10 + '0';
    fileNameTemp[11] = depthOfDimensions/10+'0';
    fileNameTemp[12] = depthOfDimensions % 10 + '0';
    strcpy(fileName,fileNameTemp);
    //cout<<fileName;
}
Highscore::~Highscore()
{
    //dtor
}
void Highscore::writeHighscore(char name[30]){
    strcpy(this->name,name);
    if(!isHighscore())
        return;
    int numRecords = 1;
    if(!fileExists(fileName)){
        ofstream of(fileName);
        of.write((char*)&(numRecords),sizeof(numRecords));
        of.write((char*)this,sizeof(*this));
        of.flush();
        of.close();
    } else {
        fstream fs(fileName,ios::in|ios::out);
        fs.read((char*)&numRecords,sizeof(numRecords));
        if(numRecords < 5){
            fs.seekp(numRecords*sizeof(Highscore));
            fs.write((char*)this,sizeof(*this));
            fs.seekp(ios::beg);
            ++numRecords;
            fs.write((char*)&numRecords,sizeof(numRecords));
            fs.flush();
            fs.close();
        } else {
            Highscore highscores[5];
            for(int i = 0;i < numRecords;++i){
                fs.write((char*)&highscores[i],sizeof(Highscore));
            }
        }
    }
}
bool Highscore::isHighscore(){
    if(!fileExists(fileName))
        return true;
    ifstream is(fileName);
    int numRecords;
    is.get((char*)&numRecords,sizeof(int));
    if(numRecords < 5){
        return true;
    }
    Highscore h;
    for(int i = 0;i < numRecords;++i){
        is.get((char*)&h,sizeof(h));
        if(h.timeTakenInSeconds > timeTakenInSeconds){
            return true;
        }
    }
    return false;
}
