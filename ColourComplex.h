#ifndef COLOURCOMPLEX_H
#define COLOURCOMPLEX_H
#include <vector>
#include <iostream>
using namespace std;

class ColourComplex
{
    public:
        ColourComplex();
        ColourComplex(int ans[],int trial[],int size);
        ColourComplex(vector<int> ans,vector<int> trial);
        virtual ~ColourComplex();

        static ColourComplex generateComplex(int ans[],int trial[],int size);
        static ColourComplex generateComplex(vector<int> ans,vector<int> trial);
        bool operator==(ColourComplex c);
        bool isRight();

    protected:

    private:
        int reds;
        int whites;
        int length;
};

#endif // COLOURCOMPLEX_H
