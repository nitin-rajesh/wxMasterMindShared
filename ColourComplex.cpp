#include "ColourComplex.h"
#include <iostream>
using namespace std;

ColourComplex::ColourComplex()
{
    reds = whites = length = 0;
}
ColourComplex::ColourComplex(vector<int> ans,vector<int> trial){
    int size = ans.size();
    bool ansMarked[size];
    bool trialMarked[size];
    for(int i = 0;i < size; ++i){
        ansMarked[i] = false;
        trialMarked[i] = false;
    }
    reds = 0;
    whites = 0;
    //check for reds first?
    for(int i = 0;i<size;++i){
        if(ans.at(i)==trial.at(i)){
            reds++;
            ansMarked[i] = trialMarked[i] = true;
        }
    }
    //Now check for whites?
    for(int i = 0;i<size;++i){
        for(int j = 0;j<size;++j){
            if(i == j){
                continue;
            }
            if(trialMarked[i]){
                break;
            }
            if(ansMarked[i]){
                continue;
            }
            if(trial.at(i)==ans.at(j)){
                ansMarked[i] = trialMarked[i] = true;
                ++whites;
            }
        }
    }
    this->length = size;
    //cout<<reds<<" "<<whites<<endl;
}
ColourComplex::ColourComplex(int ans[],int trial[],int size){
    //ColourComplex c;
    bool ansMarked[size];
    bool trialMarked[size];
    for(int i = 0;i < size; ++i){
        ansMarked[i] = false;
        trialMarked[i] = false;
    }
    reds = 0;
    whites = 0;
    //check for reds first?
    for(int i = 0;i<size;++i){
        if(ans[i]==trial[i]){
            reds++;
            ansMarked[i] = trialMarked[i] = true;
        }
    }
    //Now check for whites?
    for(int i = 0;i<size;++i){
        for(int j = 0;j<size;++j){
            if(i == j){
                continue;
            }
            if(trialMarked[i]){
                break;
            }
            if(ansMarked[i]){
                continue;
            }
            if(trial[i]==ans[j]){
                ansMarked[i] = trialMarked[i] = true;
                ++whites;
            }
        }
    }
    length = size;
    //cout<<"R:"<<reds<<" W:"<<whites<<endl;
}
ColourComplex::~ColourComplex()
{
    //cout<<"Y";
    //dtor
}
ColourComplex ColourComplex::generateComplex(int ans[],int trial[],int size){
    ColourComplex c;
    bool ansMarked[size];
    bool trialMarked[size];
    for(int i = 0;i < size; ++i){
        ansMarked[i] = false;
        trialMarked[i] = false;
    }
    int reds = 0;
    int whites = 0;
    //check for reds first?
    for(int i = 0;i<size;++i){
        if(ans[i]==trial[i]){
            reds++;
            ansMarked[i] = trialMarked[i] = true;
        }
    }
    //Now check for whites?
    for(int i = 0;i<size;++i){
        for(int j = 0;j<size;++j){
            if(i == j){
                continue;
            }
            if(trialMarked[i]){
                break;
            }
            if(ansMarked[i]){
                continue;
            }
            if(trial[i]==ans[j]){
                ansMarked[i] = trialMarked[i] = true;
                ++whites;
            }
        }
    }
    c.length = size;
    c.reds = reds;
    c.whites = whites;
    //cout<<reds<<" "<<whites<<endl;
    return c;
}
ColourComplex ColourComplex::generateComplex(vector<int> ans,vector<int> trial){
    int size = ans.size();
    ColourComplex c;
    bool ansMarked[size];
    bool trialMarked[size];
    for(int i = 0;i < size; ++i){
        ansMarked[i] = false;
        trialMarked[i] = false;
    }
    int reds = 0;
    int whites = 0;
    //check for reds first?
    for(int i = 0;i<size;++i){
        if(ans.at(i)==trial.at(i)){
            reds++;
            ansMarked[i] = trialMarked[i] = true;
        }
    }
    //Now check for whites?
    for(int i = 0;i<size;++i){
        for(int j = 0;j<size;++j){
            if(i == j){
                continue;
            }
            if(trialMarked[i]){
                break;
            }
            if(ansMarked[i]){
                continue;
            }
            if(trial.at(i)==ans.at(j)){
                ansMarked[i] = trialMarked[i] = true;
                ++whites;
            }
        }
    }
    c.length = size;
    c.reds = reds;
    c.whites = whites;
    //cout<<reds<<" "<<whites<<endl;
    return c;
}
bool ColourComplex::operator==(ColourComplex c){
    //cout<<"A";
    return (c.reds == reds && c.whites == whites && c.length == length);
}
bool ColourComplex::isRight(){
    return reds == length;
}
