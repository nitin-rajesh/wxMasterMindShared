
#include "Solver.h"
#include <vector>
#include "Tensor.t.hpp"
#include "InitLooper.h"
#include "EliminationLooper.h"
#include "FindNextPositionLooper.h"
#include "Tensor.h"
#include "ColourComplex.h"

using namespace std;
Solver::Solver()
{
    guesses = new vector<int*>();
}
Solver::Solver(int* answer,int numberOfDimensions,int depthOfDimensions,bool isRepeatAllowed,
               bool useRandomStart){
    this->answer = answer;
    this->numberOfDimensions = numberOfDimensions;
    this->depthOfDimensions = depthOfDimensions;
    this->isRepeatAllowed = isRepeatAllowed;
    this->useRandomStart = useRandomStart;
    guesses = new vector<int*>();
}

void Solver::solve(){
    Tensor<bool> *possibleSolutions = new Tensor<bool>(numberOfDimensions,depthOfDimensions);
    ColourComplex answerComplex = ColourComplex::generateComplex(answer,answer,numberOfDimensions);
    int *guess;
    InitLooper *init = new InitLooper(possibleSolutions,numberOfDimensions,depthOfDimensions,isRepeatAllowed);
    init->loop();

    FindNextPositionLooper *next = new FindNextPositionLooper(possibleSolutions,numberOfDimensions,
                                                              depthOfDimensions,isRepeatAllowed,useRandomStart);
    EliminationLooper *elim = new EliminationLooper(possibleSolutions,numberOfDimensions,
                                                    depthOfDimensions,isRepeatAllowed);
    int count = 0;
    while(true){

        next->loop();
        guess = next->getResult();
        guesses->push_back(copy(guess));
        ColourComplex guessComplex = ColourComplex::generateComplex(answer,guess,numberOfDimensions);
        if(guessComplex == answerComplex){
            cout<<"The Ans is:";
            for(int i = 0;i < numberOfDimensions;++i){
                cout<<guess[i];
            }
            cout<<endl;

            cout<<"Solved!";
            break;
        }

        next->reset();

        elim->reset(guess,guessComplex);
        elim->loop();

        ++count;
        if(count>=10){
            break;
        }

    }
    for(int i = 0;i<2;++i){
        //cout<<endl;
        int temp[2];
        temp[0] = i;
        for(int j = 0;j<depthOfDimensions;++j){
            temp[1] = j;
            //cout<<possibleSolutions->getAtPosition(temp);

        }
        //cout<<endl;
    }
}
Solver::~Solver(){
    delete guesses;
    delete answer;
}
int* Solver::copy(int* arr){
    int* copied = new int[numberOfDimensions];
    for(int i = 0;i < numberOfDimensions;++i){
        copied[i] = arr[i];
    }
    return copied;
}
vector<int*>* Solver::getGuesses(){
    return guesses;
}
