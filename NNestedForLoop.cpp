#include "NNestedForLoop.h"

template <typename ReturnType,typename ArrayType>
NNestedForLoop<ReturnType,ArrayType>::NNestedForLoop(){
    //ctor
}

template <typename ReturnType,typename ArrayType>
NNestedForLoop<ReturnType,ArrayType>::~NNestedForLoop(){
    //dtor
}
template <typename ReturnType,typename ArrayType>
NNestedForLoop<ReturnType,ArrayType>::NNestedForLoop(Tensor<ArrayType> *arr,int numberOfDimensions,
                       int depthOfDimensions,bool isRepeatAllowed){
    this->arr = arr;
    this->numberOfDimensions = numberOfDimensions;
    this->depthOfDimensions = depthOfDimensions;
    currentDimensionPositions = new int[numberOfDimensions];
    for(int i = 0;i<numberOfDimensions;++i){
        currentDimensionPositions[i] = 0;
    }
    this->isRepeatAllowed = isRepeatAllowed;
    stop = false;

}
/*
template <typename ReturnType,typename ArrayType>
ReturnType NNestedForLoop<ReturnType,ArrayType>::loop(){
    ReturnType t;
    while(!stop){
        loopBody();
        loopIterator();
    }
    return t;
}
*/
template <typename ReturnType,typename ArrayType>
bool NNestedForLoop<ReturnType,ArrayType>::isAnyDimensionSame(){
    for(int i = 0;i<numberOfDimensions;++i){
        for(int j = i+1;j<numberOfDimensions;++j){
            if(currentDimensionPositions[i]==currentDimensionPositions[j]){
                return true;
            }
        }
    }
    return false;
}

template <typename ReturnType,typename ArrayType>
void NNestedForLoop<ReturnType,ArrayType>::loopIterator(){
    int i;
    for(i = numberOfDimensions-1;i>=0;--i){
        ++currentDimensionPositions[i];
        if(currentDimensionPositions[i]>=depthOfDimensions){
            currentDimensionPositions[i] = currentDimensionPositions[i] % depthOfDimensions;

        } else {
            break;
        }
    }
    if (i < 0){
        //cout<<"here";
        stop = true;
    }
}

