
#ifndef FINDNEXTPOSITIONLOOPER_H
#define FINDNEXTPOSITIONLOOPER_H
#include "Looper.h"
#include "Tensor.h"
#include "NNestedForLoop.h"
#include "NNestedForLoop.t.hpp"
class FindNextPositionLooper : public NNestedForLoop<int*,bool>
{
    public:
        FindNextPositionLooper(Tensor<bool> *arr,int numberOfDimensions,
                               int depthOfDimensions,bool isRepeatAllowed,bool randomStart = false);
        FindNextPositionLooper();
        virtual ~FindNextPositionLooper();
        void loop();
        int* getResult();
        void loopBody();

    protected:

    private:
        bool randomStart;
        int* internalCurrentDimensionPositions;
        void generateRandomStart();
};

#endif // FINDNEXTPOSITIONLOOPER_H
