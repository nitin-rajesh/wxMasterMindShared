
#ifndef SOLVER_H
#define SOLVER_H
#include "Tensor.h"
#include <vector>
using namespace std;

class Solver
{
    public:
        Solver();
        Solver(int* answer,int numberOfDimensions,int depthOfDimensions,
               bool isRepeatAllowed,bool useRandomStart = true);
        virtual ~Solver();
        void solve();
        vector<int*>* getGuesses();

    protected:

    private:
        int* answer;
        vector<int*>* guesses;
        int numberOfDimensions;
        int depthOfDimensions;
        bool isRepeatAllowed;
        bool useRandomStart;
        int* copy(int* arr);

};

#endif // SOLVER_H
