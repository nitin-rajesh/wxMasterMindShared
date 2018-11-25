
#ifndef NNESTEDFORLOOP_H
#define NNESTEDFORLOOP_H

#include "Looper.h"
#include "Looper.t.hpp"
#include "Tensor.h"

template <class ReturnType,typename ArrayType>
class NNestedForLoop : public Looper <ReturnType>
{
    public:
        NNestedForLoop();
        NNestedForLoop(Tensor<ArrayType> *arr,int numberOfDimensions,
                       int depthOfDimensions,bool isRepeatAllowed);
        virtual ~NNestedForLoop();
        virtual void loop() = 0;
        virtual ReturnType getResult() = 0;
        void reset();

    protected:

        Tensor<ArrayType> *arr;
        int numberOfDimensions;
        int depthOfDimensions;
        bool isRepeatAllowed;
        int *currentDimensionPositions;//basically loop variables on steroids
        bool stop;

        virtual bool isAnyDimensionSame();
        virtual void loopBody() = 0;
        virtual void loopIterator();

    private:
};

#endif // NNESTEDFORLOOP_H
