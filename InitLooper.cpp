
#include "InitLooper.h"
#include "Looper.cpp"
#include "NNestedForLoop.cpp"
#include <iostream>
using namespace std;
#ifndef INITLOOPER_CPP
#define INITLOOPER_CPP

InitLooper::InitLooper(){
    currentDimensionPositions = NULL;
}
InitLooper::InitLooper(Tensor<bool> *arr,int numberOfDimensions,
                       int depthOfDimensions,bool isRepeatAllowed)
                       :NNestedForLoop<void,bool>(arr,numberOfDimensions,depthOfDimensions,isRepeatAllowed){
    /*
    this->arr = arr;
    this->numberOfDimensions = numberOfDimensions;
    this->depthOfDimensions = depthOfDimensions;
    currentDimensionPositions = new int[numberOfDimensions];
    for(int i = 0;i<numberOfDimensions;++i){
        currentDimensionPositions[i] = 0;
    }
    this->isRepeatAllowed = isRepeatAllowed;
    stop = false;
    */
}

InitLooper::~InitLooper(){
    delete currentDimensionPositions;
}

void InitLooper::loop(){

    while(!stop){


        loopBody();


        loopIterator();


    }

}
void InitLooper::getResult(){
}
void InitLooper::loopBody(){
    if(!isRepeatAllowed && isAnyDimensionSame()){
        arr->setAtPosition(currentDimensionPositions,false);
    }
    else {
        arr->setAtPosition(currentDimensionPositions,true);
    }
}


#endif // INITLOOPER_CPP
