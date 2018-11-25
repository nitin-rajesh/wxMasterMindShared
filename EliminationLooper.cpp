#include "EliminationLooper.h"
#include "ColourComplex.h"
#include "Tensor.h"
#include "Tensor.t.hpp"
#include "NNestedForLoop.t.hpp"
#include <iostream>
using namespace std;

EliminationLooper::EliminationLooper()
{
    //ctor
}

EliminationLooper::~EliminationLooper()
{
    //dtor
}

EliminationLooper::EliminationLooper(Tensor<bool> *arr,int numberOfDimensions,int depthOfDimensions,
                          bool isRepeatAllowed)
                          :NNestedForLoop<void,bool>(arr,numberOfDimensions,depthOfDimensions,isRepeatAllowed){
}
void EliminationLooper::loop(){
    while(!stop){

        loopBody();

        loopIterator();

    }
}
void EliminationLooper::getResult(){
}
void EliminationLooper::loopBody(){
    if(arr->getAtPosition(currentDimensionPositions)){
        ColourComplex c = ColourComplex::generateComplex(currentDimensionPositions,guess,numberOfDimensions);
        //cout<<currentDimensionPositions[0]<<currentDimensionPositions[1]<<" "<<(c==guessComplex)<<endl;
        arr->setAtPosition(currentDimensionPositions,(c==guessComplex));
    }
}
void EliminationLooper::reset(int* guess, ColourComplex guessComplex){
    NNestedForLoop<void,bool>::reset();
    this->guess = guess;
    this->guessComplex = guessComplex;
}
