#include<vector>
#ifndef ANSWERMAKER_H
#define ANSWERMAKER_H
using namespace std;

class AnswerMaker
{
    vector<int> answer;
    vector<int>::iterator ansIterator;
    int range, width;
public:
    static void holdOn();
    AnswerMaker(int range,int width, bool isRepeat=false){
        this->range=range;
        this->width=width;
        generateRandNum(isRepeat);
    }
    int getRandNum(bool isRepeat,int iteration);
    void generateRandNum(bool isRepeat);
    vector<int> returnAns();
};

#endif // ANSWERMAKER_H
