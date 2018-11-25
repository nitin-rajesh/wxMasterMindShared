#include <iostream>
#include <time.h>
#include "Tensor.h"
#include "Tensor.t.hpp"
#include "NNestedForLoop.h"
#include "EliminationLooper.h"
#include "InitLooper.h"
#include "ColourComplex.h"
#include "FindNextPositionLooper.h"
#include "Solver.h"
#include "Highscore.h"
#include <stdlib.h>

using namespace std;

void generateAnswer(int *answer,int numberOfDimensions,int depthOfDimensions,bool isRepeatAllowed);

/*int main(){
    Highscore *hs = new Highscore(1,1,1);
    hs->writeHighscore("Q");
    cout<<hs->isHighscore()<<endl;
    system("pause");

}
*/
void generateAnswer(int numberOfDimensions,int depthOfDimensions,bool isRepeatAllowed){
    int answer[16];
    /*if(!isRepeatAllowed&&depthOfDimensions<numberOfDimensions){
        cout<<"ERROR";
        return;
    }
    cout<<"Answer:";*/
    time_t t = time(&t);
    srand(t);
    for(int i = 0 ; i < numberOfDimensions ; ++i){
        answer[i] = rand()%depthOfDimensions;

        if(!isRepeatAllowed){
            for(int j = 0;j<i;++j){
                if(answer[j]==answer[i]){
                    answer[i]++;
                    j = -1;
                }
            }

        }
        cout<<answer[i];
    }
    cout<<endl;
}
