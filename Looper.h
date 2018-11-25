
#ifndef LOOPER_H
#define LOOPER_H

template <class ReturnType>
class Looper
{
    public:
        Looper();
        virtual ~Looper() = 0;
        virtual void loop() = 0;
        virtual ReturnType getResult() = 0;
    protected:

    private:
};

#endif // LOOPER_H
