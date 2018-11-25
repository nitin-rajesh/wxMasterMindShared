
#include "Tensor.h"
#ifndef NDIMENSIONALARRAY_CPP
#define NDIMENSIONALARRAY_CPP
#include <iostream>
using namespace std;

template<typename T>
Tensor<T>::Tensor(){
    dimensions = NULL;
    data = NULL;
}

template<typename T>
Tensor<T>::~Tensor(){
    //dtor
    delete dimensions;
    delete data;
}

template<typename T>
Tensor<T>::Tensor(int numberOfDimensions,int *dimensions){
    this->numberOfDimensions = numberOfDimensions;
    this->dimensions = new int[numberOfDimensions];
    int num = 1;//number of elements.
    for(int i = 0;i<numberOfDimensions;++i){
        this->dimensions[i] = dimensions[i];
        num*=dimensions[i];
    }
    this->data = new T[num];
    this->actualSize = num;
}

template<typename T>
Tensor<T>::Tensor(int numberOfDimensions,int depthOfDimensions){
    this->numberOfDimensions = numberOfDimensions;
    this->dimensions = new int[numberOfDimensions];
    int num = 1;//number of elements.
    for(int i = 0;i<numberOfDimensions;++i){
        this->dimensions[i] = depthOfDimensions;
        num*=depthOfDimensions;
    }
    this->data = new T[num];
    this->actualSize = num;

}

template<typename T>
T Tensor<T>::getAtPosition(int *pos){
    int actualPosition = pos[numberOfDimensions-1];
    int multiplier = dimensions[numberOfDimensions-1];
    for(int i = numberOfDimensions - 2;i>=0;--i){
        actualPosition+=multiplier*pos[i];
        multiplier*=dimensions[i];
    }
    //cout<<actualPosition;
    return data[actualPosition];
}

template<typename T>
void Tensor<T>::setAtPosition(int *pos,T val){
    int actualPosition = pos[numberOfDimensions-1];
    int multiplier = dimensions[numberOfDimensions-1];
    for(int i = numberOfDimensions - 2;i>=0;--i){
        actualPosition+=multiplier*pos[i];
        multiplier*=dimensions[i];
    }
    //cout<<actualPosition;
    /*
    if(pos[0]==1&&pos[1]==2&&pos[2]==4&&pos[3]==5&&pos[4]==6&&pos[5]==3){
        cerr<<actualPosition<<"  "<<actualSize<<endl;
    }*/
    data[actualPosition] = val;
}

#endif // NDIMENSIONALARRAY_CPP
