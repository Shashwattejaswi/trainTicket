#include<fstream>
#include<iostream>
using namespace std;
#ifndef KAAM_H_INCLUDED
#define KAAM_H_INCLUDED
#include"fileH.h"

class coach
{
    protected:

    int totalSeat;
};

class sleeper :public coach
{
    public:
    sleeper()
    {
        lb=mb=ub=20;
        sl=su=10;
    }
    short lb,mb,ub,sl,su;
};

class chair :public coach
{
    public:
    chair()
    {

    }
    short window,aise,middle;
};

class station: public abst
{
protected:
    char sName[20];
    char code[10];
    int current[20];

    public:


    void pickStation(string demand)
    {

    }
    void recordStation()
    {
        s=sizeof(*this);
        cout<<"Enter station name>>";
        cin>>sName;
        cout<<"Enter station code>>";
        cin>>code;
        cout<<"want to enter running train number \n press y/n";
        char ch=getche();
        if(ch=='y' || ch=='Y')
        {
            cout<<"i will enter this";
        }
        else
        {
            cout<<"please enter later";
        }

        fileHandle a('w',"station",this);

    }
    void addTrain()
    {

    }
};
class train
{
    protected:
    int tNumber;
    char tName;
    station stn[15];




};


void trainBooking()
{
    ifstream in("station.txt");
    int i=0;
    string s[6];
    while(!in.eof())
    {
      in>>s[i];
      i++;
    }
    cout<<i;
}
class admin:public abst
{
    private:
        char username[20];
        char password[20];
    public:
        admin()
        {

        }
        admin *a=this;
         void enterPass()
         {
        s=sizeof(*this);
        a1[0]=username;

             cout<<"Username> ";
             cin>>username;
             cout<<"Password> ";
             cin>>password;

             fileHandle pass('r',"admin",this);

         }


};

#endif // KAAM_H_INCLUDED
