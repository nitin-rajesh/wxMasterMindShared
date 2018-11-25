
#ifndef INITLOOPER_H
#define INITLOOPER_H

#include "Looper.h"
#include "Tensor.h"
#include "NNestedForLoop.h"

class InitLooper : public virtual NNestedForLoop<void,bool>
{
    public:
        InitLooper();
        InitLooper(Tensor<bool> *arr,int numberOfDimensions,int depthOfDimensions,bool isRepeatAllowed);
        virtual ~InitLooper();
        void loop();
        void getResult();

    protected:

        void loopBody();

    private:

};

#endif // INITLOOPER_H
