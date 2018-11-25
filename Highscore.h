
#ifndef HIGHSCORE_H
#define HIGHSCORE_H


class Highscore
{
    public:
        Highscore();
        virtual ~Highscore();
        Highscore(int numberOfDimensions,int depthOfDimensions,int timeTakenInSeconds);
        void writeHighscore(char name[30]);
        bool isHighscore();
        char name[30];

    protected:

    private:
        int numberOfDimensions;
        int depthOfDimensions;
        char fileName[19];
        int timeTakenInSeconds;
};

#endif // HIGHSCORE_H
