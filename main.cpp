#include<iostream>
#include<fstream>
#include<conio.h>
#include<iomanip>
#include<windows.h>
using namespace std;



//inherit abst in all most all classes
// bcz i can pass addr of any obj to abst class so , abst class can receive any obj address through parent can store child addr

class coach
{


    public:
    int totalSeat;
        coach()
        {

            cout<<"hehe";
        }
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

class station
{
public:
    char sName[20];
    long current[10];
    int trainsAStns[2]={0,0};
    char sCode[4];
    char nextStn[6][4];

friend class fatchAllData;
friend bool comp(station st[20],string ,int);
    public:


    void pickStation(string demand)
    {

    }
    void recordStation()
    {
        cout<<"Enter station name>>";
        cin>>sName;
        cout<<"Enter station code>>";
        cin>>sCode;
        cout<<"enter all near station code (max six)";
        string tempStn;
        cin>>tempStn;

        int i;
        for(i=0;tempStn!="end";i++)
        {
            for(int j=0;j<4;j++)
            {
                nextStn[i][j]=tempStn[j];
            }
            cin>>tempStn;
        }

        trainsAStns[1]=i-1;
        fileH('w');
//        cout<<"want to enter running train number \n press y/n"<<endl;
//        char ch=getche();
//        if(ch=='y' || ch=='Y')
//        {
//            cout<<"How many >";
//            cin>>noFTrain;
//            for(int i=0;i<noFTrain;i++)
//                cin>>current[i];
//                fileH('w');
//        }
//        else
//            cout<<"please enter later";

    }
    void seeStation(station st[20],int tot)
    {
        cout<<setw(15)<<"NAME"<<setw(6)<<"CODE"<<setw(11)<<"TRAINS"<<"\tnNEAR STATIONS"<<endl;
        for(int i=0;i<tot;i++)
        {
            cout<<setw(15)<<st[i].sName<<setw(6)<<st[i].sCode<<" ";
            for(int j=0;j<st[i].trainsAStns[0];j++)
            {
                cout<<setw(7)<<st[i].current[j]<<",";
            }
            for(int k=0;k<6;k++)
            {
                cout<<setw(1);
                for(int m=0;m<4;m++)
                {
                    cout<<st[i].nextStn[k][m];
                }
                cout<<",";
            }
            cout<<endl;

        }


    }
    void fileH(char a)
    {
        fstream fi;
        if(a=='w')
        {
            fi.open("station",ios::app);
            fi.write((char*)this,sizeof(*this));
        }
        else
        {
            station s;
            fi.open("station",ios::in);
            fi.read((char*)&s,sizeof(s));

        }
        fi.close();
    }
};
bool comp(station st[20],string s,int len,double forfitting)
{
    int i,j;
    if(s=="end")
    {
        return true;
    }
    for(i=0;i<=len;i++)
    {

        for(j=0;j<4;j++)
        {
            if(st[i].sCode[j]!=s[j])
            {
                break;
            }
        }
        if(j==4)
        {
            cout<<st[i].trainsAStns[0]++<<" "<<forfitting;
            st[i].current[st[i].trainsAStns[0]++]=forfitting;
            return true;
        }



    }
    return false;
}
class train
{
    public:
    double tNumber;
    char tName[20];
    int type;
    char stn[15][4];
    short stnTime[15][2];
    int stNo;

    void addTrain(station sta[20],int tot)
    {
        for(int k=0;k<2;k++) //we ask two times for one new train (train runs in full-duplex mode)
        {
            string temp="0";
            if(k==0) // in first time
            {
                bool fesla=true;
                cout<<"Train number > ";
                cin>>tNumber;
                cout<<"Train name > ";
                cin>>tName;
                cout<<"Train type > ";
                cin>>type;
                cout<<"enter stoppage of trains>>";
                do
                {
                    try
                    {
                        cin>>temp;
                        system("color 07");
                        if(!comp(sta,temp,tot,tNumber))
                        {
                            cout<<tot;
                            throw sta;
                        }
                        fesla=false;
                    }
                    catch(station sta[20])
                    {
                        system("Color 04");
                        cout<<"station not registerd enter again\t";
                       for(int i=0;i<tot;i++)
                        {
                        cout<<"|";
                        for(int j=0;j<4;j++)
                            cout<<sta[i].sCode[j];
                        }

                        cout<<"|"<<endl;
                    }
                }while(fesla);
                stNo=0;
            }
            else //IN SECOND TIME
            {
                tNumber+=1;
                char temp[4];
                for(int a=0;a<stNo/2;a++) // arrange in desanding order
                {
                    for(int j=0;j<4;j++)
                        temp[j]=stn[a][j];

                    for(int j=0;j<4;j++)
                        stn[a][j]=stn[stNo-(a+1)][j];

                    for(int j=0;j<4;j++)
                        stn[stNo-(a+1)][j]=temp[j];
                }
            }
            int aa=0;
            while(temp!="end")
            {
                if(k==0)
                {
                    for(int i=0;i<4;i++)
                        stn[stNo][i]=temp[i];
                    aa=stNo;
                }
                else
                {
                    if(aa>=stNo)
                        break;
                    for(int i=0;i<4;i++)
                        cout<<stn[aa][i];
                    cout<<endl;
                }
                cout<<"arrival and departure"<<endl;
                cin>>stnTime[aa][0]>>stnTime[aa][1];
                if(k==0)
                {
                    bool fa=true;
                    stNo++;
                    do
                {
                    try
                    {
                        cin>>temp;
                        system("color 07");
                        if(!comp(sta,temp,tot,tNumber))
                        {
                            cout<<tot;
                            throw sta;
                        }
                        fa=false;
                    }
                    catch(station sta[20])
                    {
                        system("Color 04");
                        cout<<"station not registerd enter again\t";
                        for(int i=0;i<tot;i++)
                        {
                        cout<<"|";
                        for(int j=0;j<4;j++)
                            cout<<sta[i].sCode[j];
                        }

                        cout<<"|"<<endl;
                    }
                }while(fa);
                }
                else
                    aa++;
            }
            fileH('w');
        }
    }

    void showTrain()
    {
        train t=fileH('r');
    }
    train fileH(char o)
    {
        fstream fina;

            train t1;
        if(o=='w')
        {
            fina.open("train",ios::app);
            fina.write((char*)this,sizeof(*this));
        }
        else if(o=='r')
        {
            fina.open("train",ios::in);
            fina.read((char*)&t1,sizeof(t1));
            string trainType;
            cout<<setw(6)<<"NUMBER"<<setw(12)<<"NAME"<<setw(11)<<"TYPE"<<"\tSTATIONS"<<endl;
            while(!fina.eof())
            {
                    if(t1.type==1)
                        trainType="Superfast";
                    else if(t1.type==2)
                        trainType="Express";
                    else
                        trainType="Passenger";
                    cout<<setw(6)<<t1.tNumber<<setw(12)<<t1.tName<<setw(11)<<trainType<<"\t";
                    int a=0;
                    while(a<t1.stNo)
                    {
                        for(int j=0;j<4;j++)
                            cout<<t1.stn[a][j];
                        cout<<",";
                        a++;
                    }
                    cout<<"\b"<<endl;
                    fina.read((char*)&t1,sizeof(t1));
            }
        fina.close();
        return t1;
        }
    }


};

class fatchAllData
{
    public:
    int stnTr[2]={0,0};  // iuterator for station
    ifstream getData;
    station reviveS[20];
    train reviveT[20];
    string key="raja";
    void fatch()
    {
        getData.open("station",ios::in);
       do
        {
            getData.read((char*)&reviveS[stnTr[0]],sizeof(reviveS[stnTr[0]]));
        stnTr[0]++;

        }while(!getData.eof());
        stnTr[0]--;
        getData.close();

        getData.open("train",ios::in);
       do
        {
            getData.read((char*)&reviveT[stnTr[1]],sizeof(reviveT[stnTr[1]]));
        stnTr[1]++;

        }while(!getData.eof());
        stnTr[1]--;
    }
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
class admin
{
    private:
        int b=10;
        char password[10],username[10];
    public:
         void enterPass(station st[20],int total)
         {

             cout<<"Username> ";
             cin>>username;
             cout<<"Password> ";
             cin>>password;
            fstream s;
            admin a;
            s.open("admin",ios::in);
            s.read((char*)&a,sizeof(a));
           s.close();
            string temp1=a.username; //we cant camp char arry like a="shashawa" this only with string dtatyppe & i cant create string dtatype that goes to store in txt file
            string temp2=a.password;
            if(temp1==username && temp2==password)
            {
                cout<<"hii\nHow's your days is going\n"<<endl;
                cout<<"add Train\nadd Station\n"<<endl;
                char a=getch();
                if(a=='S')
                {

                    station s;
                    char y;
                     do
                    {
                    s.recordStation();
                    cout<<"'y' for add more"<<endl;
                    y=getch();
                    }while(y=='y' || y=='Y');
                }
                else if(a=='s')
                {
                    station s;
                    s.seeStation(st,total);
                }
                else if(a=='T')
                {
                    train t1;
                    char y;
                     do
                    {
                    t1.addTrain(st, total);
                    cout<<"'y' for add more"<<endl;
                    y=getch();
                    }while(y=='y' || y=='Y');
                }
                else if(a=='t')
                {
                    train t1;
                    t1.showTrain();
                }
            }
            else{
                cout<<"Boss!!! what is this.."<<endl;
            }
         }


};

void updateAll(station ss[20],train tt[20],int stnTr[2])
{
    ofstream editing;
    editing.open("tryS",ios::app);
    cout<<stnTr[0];
    for(int i=0;i<stnTr[0];i++)
        editing.write((char*)&ss[i],sizeof(ss[i]));

    editing.close();
    remove("station");
    rename("tryS","station");

}
void timeTable(station ss[20],train tt[20],int stnTr[2])
{
    string stat[2];
    int j=0;
    station forCheck[2];
    cout<<"From >";
    cin>>stat[0];
    cout<<"To >";
    cin>>stat[1];
    for(int i=0;i<stnTr[0];i++)
    {
            if(stat[0]==ss[i].sName)
            {
                forCheck[j]=ss[i];
                j++;
            }
            else if(stat[1]==ss[i].sName)
            {
                forCheck[j]=ss[i];
                j++;
            }
        if(j==2)
            break;
    }
    j=forCheck[0].trainsAStns[0]+forCheck[1].trainsAStns[0];
    int *allTrains=new int[j];
    int i=0;
    for(i=0;i<forCheck[0].trainsAStns[0];i++)
    {
            allTrains[i]=forCheck[0].current[i];

    }
    for(int q=0,i=forCheck[0].trainsAStns[0];q<forCheck[1].trainsAStns[0];q++,i++)
    {
        allTrains[i]=forCheck[1].current[q];
    }
    for(int m=1;m<j;m++)
    {
        for(int n=0;n<m-1;n++)
        {
            if(allTrains[m]==allTrains[n])
            {

            }
        }
    }

}

int main()
{
    cout<<"welcome in Railway ticket booking"<<endl;
    int a=1;
    fatchAllData fat;
    fat.fatch();

    while(a)
    {
        cout<<"press 1 for ticket booking"<<endl;
        cout<<"press 2 for show route"<<endl;
        cout<<"press 3 for show train time table"<<endl;
        cout<<"press 4 for cancel ticket"<<endl;
        cout<<"press 5 for exit"<<endl;

        char c;
        c=getche();
        switch(c)
        {
        case '1':
            {
                trainBooking();
                break;
            }
        case '2':
            {
                cout<<"call show route"<<endl;
                break;
            }
        case '3':
            {
                timeTable(fat.reviveS,fat.reviveT,fat.stnTr);
                break;
            }
        case '4':
            {
                cout<<"call cancel ticket"<<endl;
                break;
            }
        case '5':
            {
                exit(1);
                break;
            }
        case '6':
            {
                cout<<"add station";
                break;

            }
        case '@':
            {
               admin a;
               a.enterPass(fat.reviveS,fat.stnTr[0]);
                break;
            }
        case '>':
            {
                for(int k=0;k<fat.stnTr[0];k++)
                {
                    for(int m=0;m<fat.reviveS[k].trainsAStns[0];m++)
                    cout<<fat.reviveS[k].current[m]<<" ";
                }
                updateAll(fat.reviveS,fat.reviveT,fat.stnTr);
                break;
            }
        }
    }

    return 0;
}
