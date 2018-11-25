#include "AnswerMaker.h"
#include<iostream>
using namespace std;

vector<int> AnswerMaker::returnAns(){

    return answer;
}
void AnswerMaker::generateRandNum(bool isRepeat){
    for(int i=1;i<=width;i++){
        answer.push_back(getRandNum(isRepeat,i));
    }
}
int AnswerMaker::getRandNum(bool isRepeat,int iteration){
    bool repeatFound=false;
    int num;
    int n=1; int key;
    if(width>range){
        for(int i=1;i<=width;i++){
            answer.push_back(0);
        }
    }
    //Debug
    //cout<<"Range: "<<range<<"\tSize: "<<width<<endl;
        key=time(new time_t)*iteration;
        srand(key);
        num=rand()%range+1;
        //Debug
        cout<<"isRepeat"<<isRepeat<<endl;
        if(!isRepeat){
            do{
                int i;
                for(i=0,ansIterator=answer.begin();i<answer.size();i++,ansIterator++){
                    //Debug
                    cout<<"Iteration "<<i<<endl;
                    cout<<"Size: "<<answer.size()<<endl;
                    cout<<"Return Value: "<<num<<endl;
                    //Debug
                    //cout<<"Key: "<<key<<endl;
                    //key*=i;
                    //Debug
                    cout<<"Value: "<<num;
                    //cout<<i<<" Store: "<<*ansIterator<<'\n';
                    //Debug
                    cout<<"\nansIterator "<<*ansIterator<<'\n';
                    if(num==*ansIterator){
                        srand(rand());
                        num=rand()%range;
                        repeatFound=true;
                        cout<<"FOUND A DOUBLE\n";
                        break;
                    }

                    else{
                        repeatFound=false;
                    }
                    //Debug
                    //cout<<"Iteration done\n";
                }
            }while(repeatFound);
        }

    cout<<"Return Value: "<<num<<endl<<endl;
    //cout<<"\tStore: "<<*ansIterator<<'\n';
    if(num==0)
        num++;

    return num;
}
void AnswerMaker::holdOn(){
    int time1, time2, j=0;
    //cout<<"Thinking....";
    time1=time(NULL);
    for(int i=0;;i++){
        time2=time(new time_t);
        //cout<<endl<<time1<<endl<<time2;
        if(time2-time1==1){
            //cout<<".";
            j++;
        }
        if(j==4){
            return;
        }
    }
}
