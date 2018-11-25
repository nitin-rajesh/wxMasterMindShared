
#ifndef TENSOR_H
#define TENSOR_H

//#include "Tensor.t.hpp"
template<typename T>
class Tensor {
    public:
        Tensor();
        virtual ~Tensor();

        Tensor(int numberOfDimensions,int *dimensions);
        Tensor(int numberOfDimensions,int depthOfDimensions);//basically all dims are the same

        T getAtPosition(int *pos);
        void setAtPosition(int *pos,T val);
    protected:

    private:
        T *data;
        int *dimensions;//is the dimensions of all dims
        int numberOfDimensions;
        int actualSize;
};

#endif // NDIMENSIONALARRAY_H
