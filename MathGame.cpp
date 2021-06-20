#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<string>
#include "Mark.cpp"
#include "GroupQueue.h"
#include "Group.h"
using namespace std;

void comm(int m){
    if(m<=5) cout<<"You could do it BETTER!";
    else if(m>5 && m<=10) cout<<"GOOD. But it's not enough!";
    else if(m>10 && m<=15) cout<<"GREAT!";
    else if(m>15 && m<=20) cout<<"Awesome!";
    else if(m>20 && m<=25) cout<<"You're GENIUS!";
    else cout<<"You're MATHGOD!!!";

}


int main()
{

    srand(time(NULL));
    Group grpname;
    GroupQueue GRP;
    Stack STK;
    Score S;
    int high=0, a, b, f, ans, mark, bil, finalmark;
    string team;
    const char per= '%';


    GAME:
    mark=0;
    cout<<"============WELCOME TO MATH GAME============\n";
    cout<<"********************************************\n";
    cout<<"\nSOLVE SIMPLE MATHS\nONE MISTAKE AND YOU'RE DEAD\n\n";
    cout<<"MAX: 2 Groups. Next update will be increase.";
    cout<<"What group are you in : ";
    cin>>team;
    cout<<"\nHow many members in your group?"<<endl;
    cin>>bil;
    grpname.setData(team,bil);
    GRP.enqueue(grpname);
    while(1){
        a=rand()%29+1;
        b=rand()%23+1;
        if(a<b) swap(a,b);
        f=rand()%5;
        ans=0;
        if(f==0) {
            cout<<a<<"\t"<<per<<"\t"<<b<<"\t=\t";
            cin>>ans;
            if(ans==(a%b))
            mark++;
            else {goto END;}
        }
        else if(f==1) {
            cout<<a<<"\t-\t"<<b<<"\t=\t";
            cin>>ans;
            if(ans==(a-b)) 
            mark++;
            else {goto END;}
        }
        else if(f==2) {
            cout<<a<<"\tx\t"<<b<<"\t=\t";
            cin>>ans;
            if(ans==(a*b))
            mark++;
            else {goto END;}
        }
        else if(f==3 && a%b==0) {
            cout<<a<<"\t/\t"<<b<<"\t=\t";
            cin>>ans;
            if(ans==(a/b))
            mark++;
            else {goto END;}
        }
        else {
            cout<<a<<"\t+\t"<<b<<"\t=\t";
            cin>>ans;
            if(ans==(a+b))
            mark++;
            else {goto END;}
        }
    }
    END:
    char grp;
    int mark1,mark2;
    cout<<"\nYour Score: "<<mark;
    if(mark>high) {
        high=mark;
        cout<<"\n\nCONGRATULATIONS!!!!\nYOU MADE A NEW HIGH SCORE!!!\n";
        cout<<"\nHighscore: "<<high<<"\n\n";
        S.setScore(mark);
        STK.push(S);
    }
    else {
        cout<<"\nHighscore: "<<high<<"\n\n";
        S.setScore(mark);
        STK.push(S);
        comm(mark);
    }
    cout<<"\n\nIf all group have played,enter any char.\nIf your group havent play,press 'G' to play the game.\n";
    cin>>grp;
    cout<<"\n\n";
    if(grp=='G'||grp=='g')
        goto GAME;
    else
    {   
        STK.pop(S);
        mark1 = S.getScore();
        STK.pop(S);
        mark2 = S.getScore();
        cout<<"THE RESULT\n";
        if(mark2>mark1){
            GRP.dequeue(grpname);
            cout<<grpname.getGroup()<<" is the winner.\n";
            cout<<"Group 1: "<<mark2;
            cout<<"\nGroup 2: "<<mark1;
        }
        else if(mark1>mark2){
            GRP.dequeue(grpname);
            GRP.dequeue(grpname);
            cout<<grpname.getGroup()<<" is the winner\n";
            cout<<"Group 1: "<<mark2;
            cout<<"\nGroup 2: "<<mark1;
        }
        else
        {
            cout<<"\nThe result are draw.";
            cout<<"Group 1: "<<mark2;
            cout<<"Group 2: "<<mark1;
        }
    }
    return 0;
}
