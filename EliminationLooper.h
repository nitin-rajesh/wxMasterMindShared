
#ifndef ELIMINATIONLOOPER_H
#define ELIMINATIONLOOPER_H

#include "NNestedForLoop.h"
#include "Tensor.h"
#include "ColourComplex.h"


class EliminationLooper : public NNestedForLoop<void,bool>
{
    public:
        EliminationLooper();
        EliminationLooper(Tensor<bool> *arr,int numberOfDimensions,int depthOfDimensions,
                          bool isRepeatAllowed);
        virtual ~EliminationLooper();
        void loop();
        void getResult();
        void reset(int *guess, ColourComplex guessComplex);

    protected:

        void loopBody();

    private:

        int *guess;
        ColourComplex guessComplex;
};

#endif // ELIMINATIONLOOPER_H
