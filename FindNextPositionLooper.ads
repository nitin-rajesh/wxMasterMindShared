
#include "FindNextPositionLooper.h"
#include <iostream>
using namespace std;

FindNextPositionLooper::FindNextPositionLooper():NNestedForLoop<int*,bool>()
{
    internalCurrentDimensionPositions = NULL;
}
FindNextPositionLooper::FindNextPositionLooper(Tensor<bool> *arr,int numberOfDimensions,
                       int depthOfDimensions,bool isRepeatAllowed,bool randomStart)
                       :NNestedForLoop<int*,bool>(arr,numberOfDimensions,depthOfDimensions,isRepeatAllowed){
    this->randomStart = randomStart;
    this->internalCurrentDimensionPositions = new int[numberOfDimensions];
}
FindNextPositionLooper::~FindNextPositionLooper()
{
    delete internalCurrentDimensionPositions;
}

void FindNextPositionLooper::loop(){

    if(randomStart){
        generateRandomStart();
    } else {
        for(int i = 0;i < numberOfDimensions;++i){
            internalCurrentDimensionPositions[i] = 0;
        }
    }
    while(!stop){

        loopBody();
        loopIterator();

    }
}
int* FindNextPositionLooper::getResult(){
    return internalCurrentDimensionPositions;
}

void FindNextPositionLooper::loopBody(){
    int i;
    if(arr->getAtPosition(internalCurrentDimensionPositions)){
        stop = true;
        return;
    }
    for(i = numberOfDimensions-1;i>=0;--i){
        ++internalCurrentDimensionPositions[i];
        if(internalCurrentDimensionPositions[i]>=depthOfDimensions){
            internalCurrentDimensionPositions[i] = internalCurrentDimensionPositions[i] % depthOfDimensions;

        } else {
            break;
        }
    }
}
void FindNextPositionLooper::generateRandomStart(){

    if(!isRepeatAllowed&&depthOfDimensions<numberOfDimensions){
        cout<<"ERROR";
        return;
    }
    time_t t = time(&t);
    srand(t);
    for(int i = 0 ; i < numberOfDimensions ; ++i){
        internalCurrentDimensionPositions[i] = rand()%depthOfDimensions;

        if(!isRepeatAllowed){
            for(int j = 0;j<i;++j){
                if(internalCurrentDimensionPositions[j]==internalCurrentDimensionPositions[i]){
                    internalCurrentDimensionPositions[i]++;
                    j = -1;
                }
            }
        }
        //cout<<answer[i];
    }
}
