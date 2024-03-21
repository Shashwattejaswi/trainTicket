#include<fstream>
#include<iostream>
using namespace std;

#ifndef FILEH_H_INCLUDED
#define FILEH_H_INCLUDED
class abst //made this because this class act as parent that can store addr of any child class
{
    public:
    int s;
    char* a1[5];

};

class fileHandle
{
    char readWrite;
   abst c;
   char *obj;
   string opt;
   abst *p;
      int siz;
    char *fileName; // we use char pointer instead of string because open method of is of C programming style so it can't take string (class)
    public:
    abst aa;
    fstream sab;
    ifstream sa;

    fileHandle(char modeRW,char *a,abst *b)
    {

        opt=b->a1[0];
        p=b;
        siz=b->s;
        fileName=a;
        readWrite=modeRW;
        createWay();
    }

    void createWay()
    {
        string s;
        if(readWrite=='W'||readWrite=='w')
        {
            sab.open(fileName,ios::app);
            sab.write((char*)p,siz);
            cout<<"ho gya";

        }
        else
        {
           sa.open(fileName,ios::in);
           sa.read((char*)&aa,sizeof(aa));
           cout<<aa.s;

        }

    // aany fstream function don't support copy constractor so return address of object
    }


};


#endif // FILEH_H_INCLUDED
